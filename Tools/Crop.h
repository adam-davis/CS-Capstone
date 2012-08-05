#pragma once
#include "Tool.h"
#include <QMouseEvent>

class Crop :
	public Tool
{
public:
	Crop(PaintArea*);
	~Crop(void);
};
