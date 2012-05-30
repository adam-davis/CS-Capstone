#ifndef _LINETOOL_H_
#define _LINETOOL_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class LineTool : public Tool
{
public:
	LineTool(){name="LineTool";};
	~LineTool(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawLineTo(const QPoint &endPoint, PaintArea*);
	static void setBrushSize(int newSize){LineTool::brushSize = newSize;}
	static int brushSize;
	QPoint* startingPoint;
	QImage originalImage;

};



#endif