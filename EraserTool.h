#ifndef _EraserTool_H_
#define _EraserTool_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class EraserTool : public Tool
{
public:
	EraserTool(){name="EraserTool";};
	~EraserTool(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawLineTo(const QPoint &endPoint, PaintArea*);
	static void setEraserSize(int newSize){EraserTool::brushSize = newSize;}
	static QColor brushColor;
	static int brushSize;

};



#endif