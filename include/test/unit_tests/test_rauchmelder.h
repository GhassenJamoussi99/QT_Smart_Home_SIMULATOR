#pragma once

#include "rauchmelder_mockup.h"
#include "abstract_rauchmelder.h"

#include <QObject>
#include <QtTest>
#include <string>

class test_rauchmelder : public QObject
{
    Q_OBJECT

    abstract_rauchmelder *cut_;

public:
    test_rauchmelder();

    // Some special values for testing


    // Dictates the answer of temperatursensor
    static int TEMPERATUR_SENSOR_VALUE;

private slots:

    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases
    void test_check_temperatur();
};
