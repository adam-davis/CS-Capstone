#include "ImageDownloader.h"	
#include <QInputDialog>
#include <QDir>


ImageDownloader::ImageDownloader()
{
	 netManager = new QNetworkAccessManager(); 
	 urlImage = new QImage();	
}
void ImageDownloader::downloadBegin()
	{
		downloaded = false;
		bool ok;
		 QString text = QInputDialog::getText(this, "Mad Downloading",
											 "URL", QLineEdit::Normal,
											  QDir::home().dirName(), &ok);
		 if (ok && !text.isEmpty())
		 {
			QUrl url(text);
			netReply = netManager->get(QNetworkRequest(url));
		 }

		 
	}



void ImageDownloader::downloadFinished()
	{
		 urlImage = new QImage();
		if (netReply->error() != QNetworkReply::NoError) {
			netReply->deleteLater();
			downloaded = true;
			return;
		}

		QVariant redir = netReply->attribute(QNetworkRequest::RedirectionTargetAttribute);
		if (redir.isValid()) {
			QUrl url = redir.toUrl();
			if (url.isRelative()) {
				url.setScheme(netReply->url().scheme());
				url.setEncodedHost(netReply->url().encodedHost());
			}
			QNetworkRequest req(url);
		   netManager->get(req);
			netReply->deleteLater();
			downloaded = true;
			return;
	
		
		}
    QByteArray jpegData = netReply->readAll();

	downloaded = true;
    urlImage->loadFromData(jpegData);

	}