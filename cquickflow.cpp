#include "cquickflow.h"

CQuickFlow::CQuickFlow()
{
    m_flowModel = new CFlowModel();
    m_homeModel = new CFlowModel();
}

CQuickFlow::~CQuickFlow()
{
    delete m_flowModel;
    delete m_homeModel;
}

CFlowModel *CQuickFlow::flowModel()
{
    return m_flowModel;
}

CFlowModel *CQuickFlow::homeModel()
{
    return m_homeModel;
}
