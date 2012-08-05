#ifndef _IMAGEDOWNLOADER_H_
#define _IMAGEDOWNLOADER_H_

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QMainWindow>
#include <QNetworkReply>

class ImageDownloader : public QWidget
{

	Q_OBJECT

		
		public slots:
			void downloadBegin();
			void downloadFinished();
		public:
			ImageDownloader();
			QNetworkAccessManager* netManager;
			QNetworkReply* netReply;
			QImage* urlImage;
			bool downloaded;
	
};

#endif