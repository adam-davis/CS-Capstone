#ifndef _ZOOM_H_
#define _ZOOM_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class ZoomTool : public Tool
{
public:
	ZoomTool(){ name="ZoomTool";scaleFactor = .5;};
	~ZoomTool(){};
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);		
	float scaleFactor;
	void undoZoom(PaintArea *currentPaintArea);
};



#endif