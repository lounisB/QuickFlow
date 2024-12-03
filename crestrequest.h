#ifndef CRESTREQUEST_H
#define CRESTREQUEST_H

#include <QObject>
#include <QVariant>
#include <cresult.h>
#include <cvariable.h>

class CrestRequest : public QObject
{    
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(int delay READ delay WRITE setDelay NOTIFY delayChanged)
    Q_PROPERTY(QVariantList results READ getResults NOTIFY resultsChanged)

public:
    CrestRequest(QObject *parent = nullptr);
    CrestRequest(const QString &url, const int &delay, QObject *parent=0);

    QString url() const;
    void setUrl(const QString &url);
    int delay() const;
    void setDelay(const int &delay);
    QVariantList getResults() const;
    QList<Cresult*>* results();

    void updateUrl(const QList<Cvariable*> &varList);    // update url with variables
    void execute();

signals:
    void urlChanged();
    void delayChanged();
    void resultsChanged();

private:
    QString m_url;
    int m_delay;
    QList<Cresult*> m_results;
};

#endif // CRESTREQUEST_H
