#include "NewImageDialog.h"
#include "ui_newimagedialog.h"

NewImageDialog::NewImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewImageDialog)
{
    ui->setupUi(this);
}

NewImageDialog::~NewImageDialog()
{
    delete ui;
}
