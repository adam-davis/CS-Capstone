#ifndef NEWIMAGEDIALOG_H
#define NEWIMAGEDIALOG_H

#include <QDialog>
#include "NumericInput.h"

namespace Ui {
class NewImageDialog;
}

class NewImageDialog : public QDialog
{
    Q_OBJECT
    
public:
	 explicit NewImageDialog(QWidget *parent = 0);
    ~NewImageDialog();
    QSize* getNewSize();
private slots:
		void reject();
private:
	int getNewHeight();
	int getNewWidth();
	int originalHeight;
	int originalWidth;
    Ui::NewImageDialog *ui;
	NumericInput* imageHeight;
	NumericInput* imageWidth;
};

#endif 
