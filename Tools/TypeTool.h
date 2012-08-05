#ifndef _TYPETOOL_H_
#define _TYPETOOL_H_

#include <QMouseEvent>
#include <vector>
#include <QFont>
#include "Tool.h"
#include "PaintArea.h"
#include "TypeToolOptions.h"
#include "TypeToolInput.h"

class TypeTool : public Tool
{
public:
	TypeTool(void);
	~TypeTool(void);
	void mousePressEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*,PaintArea*);
	void initTextEdit(PaintArea*, QPoint);
private:
	bool active;
	TypeToolOptions* text;

};
#endif

