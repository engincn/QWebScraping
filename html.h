#ifndef HTML_H
#define HTML_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>


class html : public QObject
{
    Q_OBJECT

public:
    html();
    void downloadHtml();
    void getURL(QString url);
    QString getHtml();

private:
    QNetworkAccessManager *htmlDownload;
    QString htmlStr;

private slots:
    void download(QNetworkReply *reply);

signals:
    void finishSignal(void);

};

#endif // HTML_H
