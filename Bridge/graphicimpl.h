#ifndef GRAPHICIMPL_H
#define GRAPHICIMPL_H

#include <string>
using std::string;

class GraphicImpl
{
	public:
		virtual void DrawText (const string & text) = 0;
		virtual void DrawLine (int x1, int y1, int x2, int y2) = 0;
};

class GraphicImplSystem1 : public GraphicImpl 
{
	public:
		void DrawText (const string & text);
		void DrawLine (int x1, int y1, int x2, int y2);
};

class GraphicImplSystem2 : public GraphicImpl 
{
	public:
		void DrawText (const string & text);
		void DrawLine (int x1, int y1, int x2, int y2);
};

#endif // GRAPHICIMPL_H
