#include "imagerotatedialog.h"
#include "ui_imagerotatedialog.h"

ImageRotateDialog::ImageRotateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageRotateDialog)
{

	rejected = false;
    ui->setupUi(this);	
	QRegExp expr("[0-9]{0,3}");
	QRegExpValidator *v = new QRegExpValidator(expr, 0);
	degreesToRotate = new NumericInput(this);
	degreesToRotate->setObjectName(QString::fromUtf8("degreesToRotate"));
	degreesToRotate->setGeometry(QRect(120, 130, 51, 20));
	degreesToRotate->setInputMethodHints(Qt::ImhDigitsOnly);
	degreesToRotate->setValidator(v);
}

ImageRotateDialog::~ImageRotateDialog()
{
    delete ui;
}

int ImageRotateDialog::getImageAngle(){
        return this->degreesToRotate->text().toUInt();

}

