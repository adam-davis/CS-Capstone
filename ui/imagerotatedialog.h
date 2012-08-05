#ifndef IMAGEROTATEDIALOG_H
#define IMAGEROTATEDIALOG_H

#include <QDialog>
#include "NumericInput.h"
namespace Ui {
class ImageRotateDialog;
}

class ImageRotateDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImageRotateDialog(QWidget *parent = 0);
    ~ImageRotateDialog();
	int getImageAngle();
	bool rejected;
	NumericInput* degreesToRotate;
	private slots:
		void reject(){rejected = true;this->close();QDialog::reject();};
private:
    Ui::ImageRotateDialog *ui;

};

#endif // IMAGEROTATEDIALOG_H
 