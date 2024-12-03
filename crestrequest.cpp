#include "crestrequest.h"
#include <QNetworkReply>
#include <QEventLoop>
#include <QStandardPaths>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

CrestRequest::CrestRequest(QObject *parent)
    : QObject(parent)
{
}

CrestRequest::CrestRequest(const QString &url, const int &delay, QObject *parent)
    : QObject(parent), m_url(url), m_delay(delay)
{
}

QString CrestRequest::url() const
{
    return m_url;
}

void CrestRequest::setUrl(const QString &url)
{
    if (url != m_url) {
        m_url = url;
        emit urlChanged();
    }
}

int CrestRequest::delay() const
{
    return m_delay;
}

void CrestRequest::setDelay(const int &delay)
{
    if (delay != m_delay) {
        m_delay = delay;
        emit delayChanged();
    }
}

QVariantList CrestRequest::getResults() const
{
    QVariantList list;
    for(auto r: m_results)
        list.append(QVariant::fromValue(r));
    return list;
}

QList<Cresult *>* CrestRequest::results()
{
    return &m_results;
}

void CrestRequest::updateUrl(const QList<Cvariable *> &varList)
{
    for(auto var: varList)
        m_url = m_url.replace("["+var->name()+"]", var->value());
}

void CrestRequest::execute()
{
//    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
//    auto fileName= path + "/mySomeFile";

    // https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd
    //m_url = "https://api.coindesk.com/v1/bpi/currentprice.json";
//    Cresult result("aa", "aa");
//    result.setName("btc");
//    result.setKey("bpi.usd.rate");
//    m_results.append(&result);

    QNetworkAccessManager *manager = new QNetworkAccessManager;
    QEventLoop loop;
    QObject::connect(manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    QNetworkReply* reply= manager->get(QNetworkRequest(QUrl(m_url)));
    loop.exec();

    QByteArray bytes = reply->readAll();
    QString str = QString::fromUtf8(bytes.data(), bytes.size());
    //qDebug() << str;

    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    //get the jsonObject
    QJsonObject jsonObject = doc.object();
    //QVariant variant = jObject.toVariantMap();
    //convert the json object to variantmap
    //QVariantMap mainMap = jObject.toVariantMap();

    // check results
    for(auto r: m_results)
    {
        QStringList keyList = r->key().split('.', Qt::SkipEmptyParts);
        for(auto key: keyList)
        {
            // \s*"*(.*?)"*\s*\[\s*"*(.*?)"*\s*\=\s*"*(.*?)"*\s*]
            // \s*(.*?)\s*\[\s*(.*?)\s*]
            QRegularExpression regexTrigger("\\s*\"*(.*?)\"*\\s*\\[\\s*\"*(.*?)\"*\\s*\\=\\s*\"*(.*?)\"*\\s*]");     // "one[two = three]", "one one2 [ "two" = "three three2"]"
            QRegularExpression regexTab("\\s*(.*?)\\s*\\[\\s*(.*?)\\s*]");                                           // "one[2]"
            QRegularExpressionMatch matchTrigger = regexTrigger.match(key);

            if (matchTrigger.hasMatch())   // "one[two = three]"
            {
                QString matched1 = matchTrigger.captured(1);
                QString matched2 = matchTrigger.captured(2);
                QString matched3 = matchTrigger.captured(3);

                if (matched1 == "") // no name array: root.[two = 2]
                {

                }
                else
                {
                    QJsonArray jsonArray = jsonObject[matched1].toArray();

                    bool find= false;
                    for(auto jObject: jsonArray)
                    {
                        QJsonObject currentObject = jObject.toObject();
                        if (jsonObject[matched2].toString() == matched3)
                        {
                            find = true;
                            jsonObject = currentObject;
                            break;
                        }
                    }
                    if (!find)
                    {
                        r->setValue("");
                        delete manager;
                        return;
                    }
                }
            }
            else
            {
                QRegularExpressionMatch matchTab = regexTab.match(key);
                if (matchTab.hasMatch())   // "one[2]"
                {
                    QString matched1 = matchTab.captured(1);
                    QString matched2 = matchTab.captured(2);

                    bool isInt;
                    int value = matched2.toUInt(&isInt);
                    if (isInt)
                    {
                        QJsonArray jsonArray;
                        if (matched1 == "" && key == keyList.front()) // no name array: [2].name (only for root element)
                            jsonArray = doc.array();
                        else
                            jsonArray = jsonObject[matched1].toArray();

                        jsonObject = jsonArray[value].toObject();
                        if (key == keyList.back()) // is last
                        {
                            QJsonValue jsonvalue = jsonArray[value];
                            QVariant variant = jsonvalue.toVariant();
                            r->setValue(variant.toString());
                        }
                    }
                }
                else // "one"
                {
                    if (key != keyList.back())  // is not last
                    {
                        jsonObject = jsonObject[key].toObject();
                    }
                    else
                    {
                        //QJsonValue jvalue = jObject[key].toString();
                        r->setValue(jsonObject[key].toString());
                        int a=0;
                    }
                }
            }
        }
    }
    delete manager;
}
