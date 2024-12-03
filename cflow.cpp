#include "cflow.h"
#include "cresult.h"

CFlow::CFlow(QObject *parent)
    : QObject(parent)
{
}

CFlow::CFlow(const QString &name, /*const QString &url,*/ QObject *parent)
    : QObject(parent), m_name(name)/*, m_url(url)*/
{
//
//    m_variables.insert("test1", "variable1");
//    m_variables.insert("test2", "variable2");

//     Cvariable test1 = Cvariable("test1", "variable1");
//     Cvariable test2 = Cvariable("test2", "variable2");
//     m_variables.append(test1);
//     m_variables.append(test2);

    m_variables.append(new Cvariable("nameVariable1", "valueVariable1"));
    m_variables.append(new Cvariable("nameVariable2", "valueVariable2"));
    m_variables.append(new Cvariable("nameVariable3", "valueVariable3"));
    m_variables.append(new Cvariable("price", "currentprice"));

//    m_restRequests.append(new CrestRequest("https://api.coindesk.com/v1/bpi/[price].json", 0));
//    m_restRequests[0]->updateUrl(m_variables);
//    m_restRequests[0]->results()->append(new Cresult("result", ""));
//    m_restRequests[0]->results()->at(0)->setKey("bpi.USD.rate"); //"bpi.usdh[3].rate[a=b]"

//    m_restRequests.append(new CrestRequest("https://api-adresse.data.gouv.fr/search/?q=8+bd+du+port", 0));
//    m_restRequests[0]->updateUrl(m_variables);
//    m_restRequests[0]->results()->append(new Cresult("result", ""));
//    //m_restRequests[0]->results()->at(0)->setKey("type");
//    m_restRequests[0]->results()->at(0)->setKey("features[1].properties.label");

    m_restRequests.append(new CrestRequest("https://www.breakingbadapi.com/api/characters", 0));
    m_restRequests[0]->updateUrl(m_variables);
    m_restRequests[0]->results()->append(new Cresult("result", ""));
    //m_restRequests[0]->results()->at(0)->setKey("[1].name");
    m_restRequests[0]->results()->at(0)->setKey("[1].appearance[3]");

    //m_restRequests[0]->execute();
}

QString CFlow::name() const
{
    return m_name;
}

void CFlow::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

bool CFlow::enable() const
{
    return m_enable;
}

void CFlow::setEnable(const bool &enable)
{
    if (enable != m_enable) {
        m_enable = enable;
        emit enableChanged();
    }
}

QVariantList CFlow::getRestRequests() const
{
    QVariantList list;
    for(auto r: m_restRequests)
        list.append(QVariant::fromValue(r));
    return list;
}

QVariantList CFlow::getVariables() const
{
    QVariantList list;
    for(auto v: m_variables)
        list.append(QVariant::fromValue(v));
    return list;
}

void CFlow::testSlot(int value)
{
    m_restRequests[0]->execute();
    m_name = "name ok!!!";
    emit nameChanged();
}

