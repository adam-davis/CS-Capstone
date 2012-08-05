#ifndef _EYEDROPPER_H_
#define _EYEDROPPER_H_




#include <QMouseEvent>
 #include <QColor>
 #include <QImage>
#include <QPainter>
 #include <QWidget>
#include "Tool.h"

class EyedropperTool : public Tool
{
public:
	EyedropperTool(){name="EyedropperTool";};
	~EyedropperTool(){};
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);		

};



#endif