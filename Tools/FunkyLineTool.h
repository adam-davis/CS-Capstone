#ifndef _FUNKYLINETOOL_H_
#define _FUNKYLINETOOL_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class FunkyLineTool : public Tool
{
public:
	FunkyLineTool(){name="FunkyLineTool";};
	~FunkyLineTool(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawLineTo(const QPoint &endPoint, PaintArea*);
	static void setBrushSize(int newSize){FunkyLineTool::brushSize = newSize;}
	static QColor brushColor;
	static int brushSize;
	QPoint* startingPoint;
	QImage originalImage;

};



#endif