#include "graphicimpl.h"
#include <iostream>

void GraphicImplSystem1::DrawText (const string & text)
{
	std::cout << "Выводим текст для графической системы 1: " << text << std::endl;
}

void GraphicImplSystem1::DrawLine (int x1, int y1, int x2, int y2)
{
	std::cout << "Выводим линию по координатам " << x1 << ", " << y1 << ", " 
			  << x2 << ", " << y2 << " для графической системы 1" << std::endl;
}

void GraphicImplSystem2::DrawText (const string & text)
{
	std::cout << "Выводим текст для графической системы 2: " << text << std::endl;
}

void GraphicImplSystem2::DrawLine (int x1, int y1, int x2, int y2)
{
	std::cout << "Выводим линию по координатам " << x1 << ", " << y1 << ", " 
			  << x2 << ", " << y2 << " для графической системы 2" << std::endl;
}
