#ifndef FILTERBRUSH_H_
#define FILTERBRUSH_H_
#include "Tool.h"
#include <map>

class FilterBrush : public Tool

{
public:
	FilterBrush(){name="FilterBrush";};
	~FilterBrush(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawLineTo(const QPoint &endPoint, PaintArea*);
	static void setBrushSize(int newSize){FilterBrush::brushSize = newSize;}
	static QColor brushColor;
	static int brushSize;
	std::map<std::string, QPoint*> pixels;



};

#endif