#include "TypeToolOptions.h"
 #include <QFontDatabase>
#include "Tool.h"
TypeToolOptions::TypeToolOptions(QWidget*parent=0) : QWidget(parent)
{
		setObjectName("TypeToolOptions");
	resize(400, 60);
	setParent(parent);
	fontSelectionCombo = new QFontComboBox(this);
	fontSizeCombo = new QComboBox(this);
	text = new TypeToolInput();
	populateFontSizeCombo();

	fontSelectionCombo->resize(190, 17);
	fontSelectionCombo->setMinimumSize(QSize(190,17));
	fontSelectionCombo->setMaximumSize(QSize(190,17));
	
	fontSizeCombo->setGeometry(QRect(210, 0, 50, 17));
	text->setTabChangesFocus(true);
	text->setWordWrapMode(QTextOption::NoWrap);
	text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    text->setFixedHeight(text->sizeHint().height());
	text->viewport()->setAutoFillBackground(false);

	 connect(fontSelectionCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(changeTextFont()));
	 	  connect(fontSizeCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(changeFontPnt()));

}

TypeToolOptions::TypeToolOptions()
{
	setObjectName("fontToolOptions");
	resize(400, 60);

	fontSelectionCombo = new QFontComboBox(this);
	fontSizeCombo = new QComboBox(this);
	text = new TypeToolInput(this);
	populateFontSizeCombo();

	fontSelectionCombo->resize(190, 17);
	fontSelectionCombo->setMinimumSize(QSize(190,17));
	fontSelectionCombo->setMaximumSize(QSize(190,17));
	
	fontSizeCombo->setGeometry(QRect(210, 0, 50, 17));
	text->setTabChangesFocus(true);
	text->setWordWrapMode(QTextOption::NoWrap);
	text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    text->setFixedHeight(sizeHint().height());
	text->setStyleSheet("{background-color:rgba("+QString("%1, %2, %3, %4").arg("255", "255", "255", "20%")+");}");
	 connect(fontSelectionCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(changeTextFont()));
	  connect(fontSizeCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(changeFontPnt()));

}

void TypeToolOptions::printToImage()
{


}

void TypeToolOptions::changeFontPnt()
{
	text->setFontPointSize(fontSizeCombo->currentText().toInt());
	text->fontSize = fontSizeCombo->currentText().toInt();
}
void TypeToolOptions::changeTextFont()
{

	text->setFont(fontSelectionCombo->currentFont());

	

}
void TypeToolOptions::populateFontSelectionCombo()

{
	QFontDatabase yoWeStoreOurFontsUpInHere;
	QStringList avaliableFontFamilies = yoWeStoreOurFontsUpInHere.families();

	for(int i = 0;i < avaliableFontFamilies.length();++i)
		fontSelectionCombo->addItem(avaliableFontFamilies.at(i));


}

void TypeToolOptions::populateFontSizeCombo()
{
	QList<int> sizes = QFontDatabase::standardSizes();

		for(int i = 0;i < sizes.length();++i)
			fontSizeCombo->addItem(QString::number(sizes.at(i)));


}
TypeToolOptions::~TypeToolOptions()
{
	delete text;


}


