#include "Source/Backend/Parameters.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

auto main(int argc, char *argv[]) -> int
{
	qmlRegisterUncreatableMetaObject(
		Params::staticMetaObject,      // meta object created by Q_NAMESPACE macro
		"Parameters",                  // import statement
		1, 0,                          // major and minor version of the import
		"Params",                      // name in QML.
		"Error: only enums"            // error in case someone tries to create a MyNamespace object
	);

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	QObject::connect(
	    &engine,
	    &QQmlApplicationEngine::objectCreationFailed,
	    &app,
	    []() { QCoreApplication::exit(-1); },
	    Qt::QueuedConnection);
	engine.loadFromModule("SumpleteSolverQt", "Main");

	return app.exec();
}
