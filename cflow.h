#ifndef CFLOW_H
#define CFLOW_H

#include <QVariant>
#include "cvariable.h"
#include "crestrequest.h"

class CFlow : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool enable READ enable WRITE setEnable NOTIFY enableChanged)
    Q_PROPERTY(QVariantList restRequests READ getRestRequests NOTIFY restRequestsChanged)
    Q_PROPERTY(QVariantList variables READ getVariables NOTIFY variablesChanged)

public:
    explicit CFlow(QObject *parent = nullptr);
    CFlow(const QString &name, /*const QString &url,*/ QObject *parent=0);

    QString name() const;
    void setName(const QString& name);
    bool enable() const;
    void setEnable(const bool& enable);
    QVariantList getRestRequests() const;
    QVariantList getVariables() const;

public slots:
    void testSlot(int value);

private:
    QString m_name;
    bool m_enable;
    QList<CrestRequest*> m_restRequests;
    QList<Cvariable*> m_variables;

signals:
    void nameChanged();
    void enableChanged();
    void restRequestsChanged();
    void variablesChanged();
};

#endif // CFLOW_H
