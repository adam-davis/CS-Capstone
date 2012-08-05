#pragma once
#include "Tool.h"
#include <QRubberBand>
#include <QImage>
#include <QWidget>
#include <QMouseEvent>
class MarqueeSelect : public Tool
{
public:
	MarqueeSelect(void){name="MarqueeSelect";};
	~MarqueeSelect(void);
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*);
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*);
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
private:
	QPoint lastPoint;
};
