#ifndef _RECTANGLETOOL_H_
#define _RECTANGLETOOL_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class RectangleTool : public Tool
{
public:
	RectangleTool(){name="RectangleTool";};
	~RectangleTool(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawRectangleTo(const QPoint &endPoint, PaintArea*);
	static void setBrushSize(int newSize){RectangleTool::brushSize = newSize;}
	static int brushSize;
	QPoint* startingPoint;
	QImage originalImage;

};



#endif