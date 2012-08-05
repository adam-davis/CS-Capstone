#include "NumericInput.h"

#include <QRegExpValidator>

NumericInput::NumericInput(QWidget* parent = 0) : QLineEdit(parent)
{


}


NumericInput::~NumericInput()
{
}

void NumericInput::focusOutEvent ( QFocusEvent * e )
{
	if(this->text().length() == 0)
		this->setText("1");

	QLineEdit::focusOutEvent(e);

}
