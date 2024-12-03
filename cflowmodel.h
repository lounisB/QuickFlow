#ifndef CFLOWMODEL_H
#define CFLOWMODEL_H

#include <QObject>
#include <QVariant>
#include "cflow.h"

class CFlowModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList flows READ getFlows NOTIFY flowsChanged)

public:
    explicit CFlowModel(QObject *parent = nullptr);
    QVariantList getFlows() const;

protected:

private:
    QList<CFlow*> m_flows;

signals:
    void flowsChanged();

};

#endif // CFLOWMODEL_H
