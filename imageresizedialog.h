#ifndef IMAGERESIZEDIALOG_H
#define IMAGERESIZEDIALOG_H

#include <QDialog>
#include "NumericInput.h"

namespace Ui {
class ImageResizeDialog;
}

class ImageResizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImageResizeDialog(QWidget *parent = 0, int imageWidth = 0, int imageHeight= 0);
    ~ImageResizeDialog();
	QString getResizeType();
	QSize* getNewSize();
private slots:
	void updateComboBox(QString);
	void reject();
private:
	NumericInput* newWidth;
	NumericInput* newHeight;
	int getNewHeight();
	int getNewWidth();
	int originalHeight;
	int originalWidth;
    Ui::ImageResizeDialog *ui;
};

#endif // IMAGERESIZEDIALOG_H
