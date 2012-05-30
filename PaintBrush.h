#ifndef _PAINTBRUSH_H_
#define _PAINTBRUSH_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class PaintBrush : public Tool
{
public:
	PaintBrush(){name="PaintBrush";};
	~PaintBrush(){};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void drawLineTo(const QPoint &endPoint, PaintArea*);
	static void setBrushSize(int newSize){PaintBrush::brushSize = newSize;}
	static int brushSize;

};



#endif