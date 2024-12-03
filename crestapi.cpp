#include "crestapi.h"
#include <QNetworkReply>
#include <QEventLoop>

//#include <QtNetworkAuth/QOAuth2AuthorizationCodeFlow>

void CRestApi::init()
{
}


QString CRestApi::getResult()
{
    //QOAuth2AuthorizationCodeFlow oauth2;

    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QEventLoop loop;
    QObject::connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply* reply= manager->get(QNetworkRequest(QUrl("https://api.coindesk.com/v1/bpi/currentprice.json")));
    loop.exec();

    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    qDebug() << str;
    return str;
}
