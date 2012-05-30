#include "TypeToolInput.h"
#include <QtGui>
#include "TypeToolOptions.h"
#include "Tool.h"

TypeToolInput::TypeToolInput()
{
	finished = false;

}

TypeToolInput::TypeToolInput(QWidget* parent = 0) : QTextEdit(parent)
{

	//setParent(parent);

}

void TypeToolInput::changeTextFont(const QString& newFont)
{

	

}

void TypeToolInput::adjustWidth()

{				
	int width = targetPaintArea->getImage()->width() - point.x();
	this->resize(width, height());

}

TypeToolInput::~TypeToolInput()
{

}

void TypeToolInput::keyPressEvent(QKeyEvent* e)
{
		this->setTextColor(Tool::globalToolColor);
	if(e->key() == Qt::Key_Return)
	{
		finished = true;
		QImage* yup = targetPaintArea->getImage();
		QPainter painter(yup);
		//Hacky hacky code
		QFont tempFont = this->font();
		tempFont.setPointSize(fontSize);
		QFontMetrics fm(tempFont);
		this->setFontPointSize(this->fontSize);
		painter.setPen(Tool::globalToolColor);
         painter.setFont(tempFont);
		 QPoint nuPount(point.x(),point.y() + fm.height());
		painter.drawText(nuPount, this->toPlainText());
		targetPaintArea->saveUndoState();


	targetPaintArea->update();


		this->close();
	}
	else
		QTextEdit::keyPressEvent(e);
}

