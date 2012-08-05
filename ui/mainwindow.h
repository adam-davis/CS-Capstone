#ifndef MainWindow_H
#define MainWindow_H

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QInputDialog>
#include <QtGui/QMainWindow>
#include <QPixmap>
#include <QTabWidget>
#include <QSignalMapper>
#include "FilterFactory.h"
#include "ui_MainWindow.h"
#include "ImageScrollArea.h"
#include "PaintArea.h"
#include "ToolFactory.h"
#include "ToolManager.h"
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();
	void addNewImageTab(PaintArea*);
	PaintArea* getCurrentPaintArea();
	bool imageNotLoaded(){return getCurrentPaintArea() == NULL;};
	private slots:
		void newImage();
		void open();
		void exit();
		void close();
		void resizeEraser();
		void saveAs();
		void save();
		void undo();
		void redo();
		void zoomIn();
		void zoomOut();
		void colorPicker();
		void toggleTool(const QString);
		void applyFilter(const QString&);
		void downloadImage();
		void resizeImage();
		void rotateImageClockwise();
		void rotateImageCounterClockwise();
		void rotateImage();
		void crop();
		void toClipboard();
		void imageFromClipboard();
		void cut();
	
private:
	Ui::MainWindowClass ui;
	void scale(double factor);
	QTabWidget *imageTabs;
	QSignalMapper* toolSignalMapper;
	QSignalMapper* filterSignalMapper;
	FilterFactory filterFactory;
	ToolManager* toolManager;
};

#endif // MainWindow_H
