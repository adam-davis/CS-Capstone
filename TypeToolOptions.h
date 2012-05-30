#ifndef FONTTOOLOPTIONS_H_
#define FONTTOOLOPTIONS_H_

 #include <QFontComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include "TypeToolInput.h"
class TypeToolOptions : public QWidget
{
	Q_OBJECT
public:
	TypeToolOptions(QWidget* parent); 
	TypeToolOptions();
	~TypeToolOptions();
	void populateFontSelectionCombo();
	void populateFontSizeCombo();

	QFontComboBox* fontSelectionCombo;
	QComboBox* fontSizeCombo;
	TypeToolInput* text;
	QLabel* fontNameLabel;
	QLabel* fontSizeLabel;
	QSize sizeHint(){return QSize(400, 70);};
	static QString textFromInput;
	public slots:
		void changeFontPnt();
		void changeTextFont();
		void printToImage();




};


#endif