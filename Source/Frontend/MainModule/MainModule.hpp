#ifndef SOURCE_FRONTEND_MAIN_MODULE_HPP
#define SOURCE_FRONTEND_MAIN_MODULE_HPP

#include <QObject>
#include <QtQml/qqml.h>

class MainModule : public QObject
{
	Q_OBJECT
	QML_ELEMENT

public:
	auto resize_grid(size_t new_size) -> void;

private:

};

#endif // SOURCE_FRONTEND_MAIN_MODULE_HPP
