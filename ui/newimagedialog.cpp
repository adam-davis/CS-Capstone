#include "NewImageDialog.h"
#include "ui_newimagedialog.h"
NewImageDialog::~NewImageDialog()
{
    delete ui;
}
NewImageDialog::NewImageDialog(QWidget *parent) :
    QDialog(parent),
	ui(new Ui::NewImageDialog)
{
	//Setting up validation - numeric only
	QRegExp expr("[0-9]{0,5}");
	QRegExpValidator *v = new QRegExpValidator(expr, 0);


    ui->setupUi(this);
	imageHeight = new NumericInput(this);
    imageHeight->setObjectName(QString::fromUtf8("imageHeight"));
    imageHeight->setGeometry(QRect(110, 140, 61, 20));
    imageHeight->setInputMethodHints(Qt::ImhDigitsOnly);
	imageHeight->update();
	
	imageHeight->setText("500");


    imageWidth =  new NumericInput(this);
    imageWidth->setObjectName(QString::fromUtf8("imageWidth"));
    imageWidth->setGeometry(QRect(110, 100, 61, 20));
    imageWidth->setInputMethodHints(Qt::ImhDigitsOnly);

    imageWidth->setText("500");

	imageHeight->setValidator(v); 
	imageWidth->setValidator(v); 

	connect(imageHeight,SIGNAL(textChanged(QString)),this,SLOT(checkInput(QString)));
}

void NewImageDialog::reject()
{
	imageHeight->setText("0");
	this->close();
	
	QDialog::reject();

}

QSize* NewImageDialog::getNewSize(){
	return new QSize(getNewWidth(), getNewHeight());

}
int NewImageDialog::getNewHeight()
{
	return imageHeight->text().toInt();
}

int NewImageDialog::getNewWidth()
{
	return imageWidth->text().toInt();
}

