#ifndef _TOOL_H_
#define _TOOL_H_

#include "PaintArea.h"


class Tool 
{
	
public:
	Tool(void){name="";};
	static void setColor(QColor newColor){ globalToolColor = newColor;};
	~Tool(void){};
	virtual QString getName(){return name;};
	virtual void mouseMoveEvent(QMouseEvent*, PaintArea*){};
	virtual void mouseReleaseEvent(QMouseEvent*, PaintArea*){};
	virtual void mousePressEvent(QMouseEvent*, PaintArea*){};
public:
	static QColor globalToolColor;
	QString name;
};



#include "CopyPaste.h"
#endif