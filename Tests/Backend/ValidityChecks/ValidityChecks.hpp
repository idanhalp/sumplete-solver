#ifndef TESTS_VALIDITY_CHECKS
#define TESTS_VALIDITY_CHECKS

#include <QObject>
#include <QtTest>

class ValidityChecksTests : public QObject
{
	Q_OBJECT

private slots:
	auto test_1() -> void;
	auto test_2() -> void;
	auto test_3() -> void;
	auto test_4() -> void;
	auto test_5() -> void;
};

#endif // TESTS_VALIDITY_CHECKS
