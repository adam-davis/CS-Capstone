#include "MarqueeSelect.h"



MarqueeSelect::~MarqueeSelect(void)
{
}
void MarqueeSelect::mousePressEvent(QMouseEvent* event, PaintArea* image) {
	image->setScribbling(true);
	if (event->button() == Qt::LeftButton) {
		lastPoint = event->pos();
		image->setRubberGeo(QRect(lastPoint, QSize()));
	}
}

void MarqueeSelect::mouseMoveEvent(QMouseEvent* event, PaintArea* image) {
	image->setRubberGeo(QRect(lastPoint, event->pos()).normalized());
}


void MarqueeSelect::mouseReleaseEvent(QMouseEvent* event, PaintArea* image) {
	
	image->setRubberGeo(QRect(lastPoint, event->pos()).normalized());
	image->setSelection();
}
