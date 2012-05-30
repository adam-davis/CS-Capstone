#include "imageresizedialog.h"
#include "ui_imageresizedialog.h"

ImageResizeDialog::ImageResizeDialog(QWidget *parent,int imageWidth,  int imageHeight) :
    QDialog(parent),
    ui(new Ui::ImageResizeDialog)
{
    ui->setupUi(this);
		QRegExp expr("[0-9]{0,5}");
	QRegExpValidator *v = new QRegExpValidator(expr, 0);

	newWidth = new NumericInput(ui->groupBox);
	newWidth->setObjectName(QString::fromUtf8("newWidth"));
	newWidth->setGeometry(QRect(70, 30, 71, 20));
	newHeight = new NumericInput(ui->groupBox);
	newHeight->setObjectName(QString::fromUtf8("newHeight"));
	newHeight->setGeometry(QRect(70, 80, 71, 20));
	newHeight->setText(QString("%1").arg(imageHeight));
	newWidth->setText(QString("%1").arg(imageWidth));
	newHeight->setValidator(v);
	newWidth->setValidator(v);
		originalHeight = imageHeight;
		originalWidth = imageWidth;
		connect(ui->resizeType, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateComboBox(QString)));
}

QSize* ImageResizeDialog::getNewSize(){
	return new QSize(getNewWidth(), getNewHeight());

}
int ImageResizeDialog::getNewHeight()
{
	QString yup = ui->resizeType->currentText();
	return (ui->resizeType->currentText() == "Percent") ?
		originalHeight * float(.01 * newHeight->text().toInt()) : newHeight->text().toInt();
}

int ImageResizeDialog::getNewWidth()
{
		return (ui->resizeType->currentText() == "Percent") ?
		originalWidth * float(.01 * newWidth->text().toInt()) : newWidth->text().toInt();
}

void ImageResizeDialog::reject()
{
	this->close();
	newHeight->setText("0");
	this->close();
	
	QDialog::reject();
}
ImageResizeDialog::~ImageResizeDialog()
{
    delete ui;
}

QString ImageResizeDialog::getResizeType()
{
	return "yup";
}

void ImageResizeDialog::updateComboBox(QString string)
{
	if(string == "Percent")
	{
			newHeight->setText(QString("%1").arg(100));
			newWidth->setText(QString("%1").arg(100));
	}
	else
	{
		newHeight->setText(QString("%1").arg(originalHeight));
			newWidth->setText(QString("%1").arg(originalWidth));
	}

		int resizeIndex = ui->comboBox_2->findText(string);
		 ui->comboBox_2->setCurrentIndex(resizeIndex);

}

