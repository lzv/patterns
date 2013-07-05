#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <string>
using std::string;

#include "graphicimpl.h"

class Graphic
{
	private:
		GraphicImpl * impl;

	public:
		Graphic ();
		virtual ~Graphic ();

		void DrawText (const string & text);
		void DrawRect (int tlx, int tly, int dlx, int dly);
};

class Button : public Graphic
{
	public:
		void Draw (const string & text, int tlx, int tly, int dlx, int dly);
};

class DoubleBorder : public Graphic
{
	public:
		void Draw (int tlx, int tly, int dlx, int dly);
};

#endif // GRAPHIC_H
