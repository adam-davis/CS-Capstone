#ifndef TOOLMANAGER_H_
#define TOOLMANAGER_H_

#include "ToolFactory.h"
#include <string>
class ToolManager
{
public:
	ToolManager(){};
	void setCurrentTool(QString toolName){ToolManager::currentTool = ToolFactory::createTool(toolName);currentToolName=toolName;};
	Tool* getCurrentTool(){return ToolManager::currentTool;};
	QString getCurrentToolName(){return currentToolName;};
private:
	ToolFactory toolFactory;
	static Tool* currentTool;
	QString currentToolName;

};


#endif