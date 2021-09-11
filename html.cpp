#include "html.h"


html::html()
{
    htmlDownload = new QNetworkAccessManager();
    downloadHtml();
}
void html::downloadHtml()
{
    QObject::connect(htmlDownload, &QNetworkAccessManager::finished, this, &html::download);
}

void html::download(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    htmlStr = QString::fromLatin1(data);
    emit finishSignal();
}

void html::getURL(QString url)
{
    htmlDownload->get(QNetworkRequest(QUrl(url)));
}

QString html::getHtml()
{
    return htmlStr;
}
