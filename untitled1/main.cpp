#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <portcontroller.h>
#include <QtQml/qqmlregistration.h>
#include <QSerialPort>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("PortController", PortController::getInstance());

    const QUrl url(QStringLiteral("qrc:/untitled1/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
