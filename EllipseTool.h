#ifndef _ELLIPSETOOL_H_
#define _ELLIPSETOOL_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
#include "Tool.h"

class EllipseTool : public Tool
{
public:
	EllipseTool(){name="EllipseTool";};
	~EllipseTool(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawEllipseTo(const QPoint &endPoint, PaintArea*);
	static void setBrushSize(int newSize){EllipseTool::brushSize = newSize;}
	static int brushSize;
	QPoint* startingPoint;
	QImage originalImage;

};



#endif