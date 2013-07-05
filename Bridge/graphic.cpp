#include "graphic.h"
#include <iostream>

extern int impl_variant;

Graphic::Graphic()
{
	if (impl_variant == 1) impl = new GraphicImplSystem1();
	else impl = new GraphicImplSystem2();
}

Graphic::~Graphic ()
{
	delete impl;
}

void Graphic::DrawText (const string & text)
{
	std::cout << "Выводим текст." << std::endl;
	impl->DrawText(text);
}

void Graphic::DrawRect (int tlx, int tly, int drx, int dry) 
{
	std::cout << "Рисуем прямоугольник." << std::endl;
	impl->DrawLine(tlx, tly, tlx, dry);
	impl->DrawLine(tlx, tly, drx, tly);
	impl->DrawLine(drx, dry, tlx, dry);
	impl->DrawLine(drx, dry, drx, tly);
}

void Button::Draw (const string & text, int tlx, int tly, int dlx, int dly)
{
	std::cout << "Рисуем кнопку - текст в рамке." << std::endl;
	this->DrawText(text);
	this->DrawRect(tlx, tly, dlx, dly);
}

void DoubleBorder::Draw (int tlx, int tly, int dlx, int dly)
{
	std::cout << "Рисуем двойную рамку." << std::endl;
	this->DrawRect(tlx, tly, dlx, dly);
	this->DrawRect(tlx + 2, tly + 2, dlx - 2, dly - 2);
}
