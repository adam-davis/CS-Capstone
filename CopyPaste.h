#pragma once
#include "Tool.h"
class CopyPaste :
	public Tool
{
public:
	CopyPaste(PaintArea*);
	~CopyPaste(void);
	void copy(void);
	void paste(void);
	void cut(void);
private:
	PaintArea *ourImage;
};

