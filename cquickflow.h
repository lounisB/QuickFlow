#ifndef CQUICKFLOW_H
#define CQUICKFLOW_H

#include <QObject>
#include "cflowmodel.h"

class CQuickFlow : public QObject
{
    Q_OBJECT

private:
    CFlowModel* m_flowModel;                // flows model
    CFlowModel* m_homeModel;                // flows model in home page

public:
    CQuickFlow();
    ~CQuickFlow();

    CFlowModel* flowModel();                // return flows model
    CFlowModel* homeModel();                // return homepage model
};

#endif // CQUICKFLOW_H
