#include "ToolFactory.h"
#include "TypeTool.h"
#include <iostream>


Tool* ToolFactory::ourTool;

Tool* ToolFactory::createTool(const QString& toolName)
{
	if(ourTool != NULL)
		delete ToolFactory::ourTool;
	if(toolName == "")
		ToolFactory::ourTool = new Tool();
	else if(toolName == "PaintBrush")
		ToolFactory::ourTool = new PaintBrush();
	else if(toolName == "EllipseTool")
		ToolFactory::ourTool = new EllipseTool();
	else if(toolName == "EyedropperTool")
		ToolFactory::ourTool = new EyedropperTool();
	else if(toolName == "ZoomTool")
		ToolFactory::ourTool = new ZoomTool();
	else if(toolName == "LineTool")
		ToolFactory::ourTool = new LineTool();
	else if(toolName == "FunkyLineTool")
		ToolFactory::ourTool = new FunkyLineTool();
	else if(toolName == "FillTool")
		ToolFactory::ourTool = new FillTool();
	else if(toolName == "RectangleTool"){
		ToolFactory::ourTool = new RectangleTool();
	}
	else if(toolName == "TypeTool")
		ourTool = new TypeTool();
	else if(toolName == "FilterBrush")
		ToolFactory::ourTool = new FilterBrush();
	else if(toolName == "EraserTool")
		ToolFactory::ourTool = new EraserTool();
	else if(toolName == "MarqueeSelect")
		ToolFactory::ourTool = new MarqueeSelect();
	return ToolFactory::ourTool;
}