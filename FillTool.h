#ifndef FILLTOOL_H_
#define FILLTOOL_H_

#include "Tool.h"


class FillTool : public Tool

{
public:
	FillTool(){name="FillTool";};
	~FillTool();
	virtual void mousePressEvent(QMouseEvent*, PaintArea*);
	void fill(QRgb& targetColor, QRgb* newColor, const QPoint&);
	QImage imageToFill;
};



#endif