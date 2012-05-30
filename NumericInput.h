#ifndef NUMERICINPUT_H_
#define NUMERICINPUT_H_


#include <QLineEdit>

class NumericInput : public QLineEdit
{


public:
	NumericInput(QWidget*);
	~NumericInput();
	void focusOutEvent(QFocusEvent* event);


};



#endif