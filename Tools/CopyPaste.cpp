#include "CopyPaste.h"
#include <QApplication>
#include <QClipboard>
#include <QLineEdit>


CopyPaste::CopyPaste(PaintArea* image)
{
	ourImage = image;
}


CopyPaste::~CopyPaste(void)
{
}

void CopyPaste::copy() {
	QImage copy = ourImage->getImage()->copy(ourImage->getSelection());
	QClipboard *clipboard = QApplication::clipboard();
	clipboard->setImage(copy);
}

void CopyPaste::paste() {
	QPoint point = QPoint::QPoint(0,0);
	QImage *image = ourImage->getImage();
	QPainter painter(image);
	QClipboard *clipboard = QApplication::clipboard();
	QImage paste = clipboard->image();
	painter.drawImage(point, paste);
	ourImage->update();
}

void CopyPaste::cut() {
	copy();
	QImage *image = ourImage->getImage();
	QPainter painter(image);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush("white"));
	painter.drawRect(ourImage->getSelection());
	ourImage->update();
}