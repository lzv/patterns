#include "strategies.h"

#include <iostream>
using std::cout;
using std::endl;

// Интерфейс стратегий.

strategy::strategy () {}

// Очистка текста от строк и символов переноса строк

clear_text::clear_text () {}

/*
 * Типы глифов: 
 * 1 - символ, 2 - перевод строки, 3 - пробел,
 * 101 - текст, 102 - параграф, 103 - строка.
 */
void clear_text::Run (glif * glif_obj)
{
	glif::container * container = glif_obj->GetContainer();
	if (container and container->size() > 0)
	{
		glif::container new_container;
		int type;
		glif::container::size_type i, n;
		glif * p_current_glif;
		
		for (i = 0; i < container->size(); ++i)
		{
			p_current_glif = (*container)[i];
			type = p_current_glif->GetType();
			
			switch (type)
			{
				case 2:
					// Перевод строки пропускаем.
					break;
					
				case 1:
				case 3:
					// Символы и пробелы добавляем.
					new_container.push_back(p_current_glif);
					break;
					
				case 101:
				case 102:
					// Если контейнер, но не строка, применяем алгоритм к нему.
					p_current_glif->RunAlgorithm(this, false);
					new_container.push_back(p_current_glif);
					break;
				
				case 103:
					// Применим алгоритм к самой строке, что бы не было подстрок, затем вытащим из нее все глифы.
					p_current_glif->RunAlgorithm(this, false);
					for (n = 0; n < p_current_glif->Count(); ++n) new_container.push_back(p_current_glif->GetChild(n));
					break;
			}
		}
		
		container->swap(new_container);
	}
}

// Разбиение на строки по символам

row_split_by_simbols::row_split_by_simbols (unsigned int len) : lenght(len)
{
	if (lenght == 0) lenght = 1;
}

/*
 * Типы глифов: 
 * 1 - символ, 2 - перевод строки, 3 - пробел,
 * 101 - текст, 102 - параграф, 103 - строка.
 */
void row_split_by_simbols::Run (glif * glif_obj) 
{
	glif_obj->RunAlgorithm(new clear_text(), true);
	glif::container * container = glif_obj->GetContainer();
	if (container and container->size() > 0)
	{
		glif::container new_container;
		int type;
		glif::container::size_type i;
		row * new_row = new row();
		glif * p_current_glif;
		
		for (i = 0; i < container->size(); ++i)
		{
			p_current_glif = (*container)[i];
			type = p_current_glif->GetType();
			switch (type)
			{
				case 1:
				case 3:
					new_row->Add(p_current_glif);
					if (new_row->Count() == lenght)
					{
						new_container.push_back(new_row);
						new_row = new row();
					}
					break;
					
				case 101:
				case 102:
					if (new_row->Count() > 0)
					{
						new_container.push_back(new_row);
						new_row = new row();
					}
					p_current_glif->RunAlgorithm(this, false);
					new_container.push_back(p_current_glif);
					break;
			}
		}
		
		if (new_row->Count() > 0) new_container.push_back(new_row);
		else delete new_row;
		
		container->swap(new_container);
	}
}

// Разбиение на строки по словам

row_split_by_words::row_split_by_words (unsigned int len) : lenght(len)
{
	if (lenght == 0) lenght = 1;
}

/*
 * Типы глифов: 
 * 1 - символ, 2 - перевод строки, 3 - пробел,
 * 101 - текст, 102 - параграф, 103 - строка.
 */
void row_split_by_words::Run (glif * glif_obj) 
{
	glif_obj->RunAlgorithm(new clear_text(), true);
	glif::container * container = glif_obj->GetContainer();
	if (container and container->size() > 0)
	{
		int type;
		bool is_last_glif;
		unsigned int simbols_in_row = 0;
		glif::container::iterator i, ip1, temp_i;
		glif::container::iterator to_row_start = container->begin();
		glif::container::iterator last_space = to_row_start;
		glif::container::iterator to_row_end = to_row_start;
		
		for (i = container->begin(); i != container->end(); ++i)
		{
			type = (*i)->GetType();
			switch (type)
			{
				case 101:
				case 102:
					// Если в строку были отобраны элементы, и внезапно встречается контейнер, все набранные элементы вносим в новую строку перед этим контейнером.
					if (simbols_in_row > 0)
					{
						glif * new_row = new row();
						for (temp_i = to_row_start; temp_i != to_row_end; ++temp_i) new_row->Add(*temp_i);
						i = container->erase(to_row_start, to_row_end);
						i = container->insert(i, new_row) + 1;
						simbols_in_row = 0;
					}
					// Применяем текущий алгоритм для подконтейнера.
					(*i)->RunAlgorithm(this, false);
					break;
				
				case 1:
				case 3:
					to_row_end = i + 1;
					++simbols_in_row;
					if (type == 3) last_space = i;
					
					if (simbols_in_row == 1)
					{
						to_row_start = i;
						last_space = i;
					}
					
					is_last_glif = container->end() == (i + 1);
					if (simbols_in_row == lenght or is_last_glif)
					{
						if (last_space == to_row_start or is_last_glif) last_space = i; // Для слов длиннее строки, либо для последней, еще не заполненной строки.
						ip1 = last_space + 1;
						glif * new_row = new row();
						for (temp_i = to_row_start; temp_i != ip1; ++temp_i) new_row->Add(*temp_i);
						i = container->erase(to_row_start, ip1);
						i = container->insert(i, new_row); // Не эффективно, часть символов будет проверена еще раз. Но делать сложней нет цели, так как в коде демонстрируется паттерн, а не алгоритм разбиения на строки.
						simbols_in_row = 0;
					}
					break;
			}
		}
	}
}
