#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
//#include <QSettings>
//#include <QQuickStyle>
#include <QIcon>

#include "crestapi.h"
#include "cquickflow.h"
#include "cflowmodel.h"
#include "cflow.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication::setApplicationName("QuickFlow");
    QGuiApplication::setOrganizationName("SpaceMonkeySoftware");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CRestApi* myObject = new CRestApi();
    engine.rootContext()->setContextProperty("myObject", myObject);

    CQuickFlow* quickFlow = new CQuickFlow();
//    quickFlow->flowModel()->getFlows().append(QVariant::fromValue(new CFlow("name1", "value1")));
//    quickFlow->flowModel()->getFlows().append(QVariant::fromValue(new CFlow("name2", "value2")));
//    quickFlow->flowModel()->getFlows().append(QVariant::fromValue(new CFlow("name3", "value3")));
//    quickFlow->flowModel()->addFlow(CFlow("name2","value2"));
//    quickFlow->flowModel()->addFlow(CFlow("name3","value3"));

    // faux
//    QVariant test = quickFlow->flowModel()->index(0).data(CFlowModel::VariablesRole);
//    QObject *object = qvariant_cast<QObject*>(test);
//    QList<Cvariable*> *variablesList = qobject_cast<QList<Cvariable*>*>(object);
//    Cvariable test1 = Cvariable("test1", "variable1");
//    Cvariable test2 = Cvariable("test2", "variable2");
//    variablesList->append(&test1);

    engine.rootContext()->setContextProperty("quickFlowModel", quickFlow->flowModel());
    engine.rootContext()->setContextProperty("homeModel", quickFlow->homeModel());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QIcon appIcon = QIcon("qrc:/img/logo.ico"); // did not work on ubuntu
    app.setWindowIcon(appIcon);

    return app.exec();
}
