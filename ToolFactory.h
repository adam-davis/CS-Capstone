#ifndef _TOOLFACTORY_H_
#define _TOOLFACTORY_H_



#include "PaintBrush.h"
#include "EyeDropper.h"
#include "Zoom.h"
#include "LineTool.h"
#include "FunkyLineTool.h"
#include "FillTool.h"
#include "RectangleTool.h"
#include "FilterBrush.h"
#include "MarqueeSelect.h"
#include "Crop.h"
#include "EraserTool.h"
#include "EllipseTool.h"


class ToolFactory{
	
public:
	ToolFactory(){};
	~ToolFactory(){};
	static Tool* createTool(const QString&);
private:
	static Tool *ourTool;

};


#endif