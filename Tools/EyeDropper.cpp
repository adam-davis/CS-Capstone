#include "EyeDropper.h"


void EyedropperTool::mousePressEvent(QMouseEvent* event, PaintArea* currentPaintArea)
	{
			currentPaintArea->setLastPoint(event ->pos());                      
			QRgb pick = currentPaintArea->getImage()->pixel(currentPaintArea->getLastPoint());
			QColor color(pick);
			globalToolColor = color;
}