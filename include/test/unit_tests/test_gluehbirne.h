#pragma once

#include "gluehbirne.h"

#include <QObject>
#include <QtTest/QTest>
#include <string>

class test_gluehbirne : public QObject
{
    Q_OBJECT

    // Class Under Test
    gluehbirne * glu_;
public:
    test_gluehbirne();

    // Some special values for testing

    const int helligkeit_1 = 1;
    const int helligkeit_high = 6;
    const int helligkeit_low = -1;

private slots:

    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases

 void test_checkout_helligkeit();
};
