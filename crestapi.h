#ifndef CRESTAPI_H
#define CRESTAPI_H

#include <QObject>
#include <QMap>
#include <QStringList>


class CRestApi: public QObject
{
    Q_OBJECT
    QMap<QString, QString> m_variables;

public:
    explicit CRestApi (QObject* parent = 0) : QObject(parent) {}

    void init();
    Q_INVOKABLE QString getResult();
};

#endif // CRESTAPI_H
