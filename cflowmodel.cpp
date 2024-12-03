#include "cflowmodel.h"
#include "cvariable.h"


CFlowModel::CFlowModel(QObject *parent)
    : QObject(parent)
{
    m_flows.append(new CFlow("name1"));
    m_flows.append(new CFlow("name2"));
    m_flows.append(new CFlow("name3"));
}

QVariantList CFlowModel::getFlows() const
{
    QVariantList list;
    for(auto f: m_flows)
        list.append(QVariant::fromValue(f));
    return list;
}
