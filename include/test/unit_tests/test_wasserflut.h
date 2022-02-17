#pragma once

#include "wasserflut_mockup.h"
#include "abstract_wasserflut.h"

#include <QObject>
#include <QtTest>
#include <string>


class test_wasserflut : public QObject
{
    Q_OBJECT

    abstract_wasserflut *cut_; // Class Under Test

public:
    test_wasserflut();

    // Dictates the answer of the temperatursensor mockup
    static double WASSERSTAND_SENSOR_WERT;

private slots:

    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases
    void test_check_wasserstand();
};

