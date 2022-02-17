#pragma once

#include "alarm_mockup.h"
#include "abstract_alarm.h"
#include "wasserflut.h"
#include "abstract_wasserflut.h"
#include "wasserstandssensor.h"

#include <QObject>
#include <QtTest>

class test_wasserflut_alarm : public QObject
{
    Q_OBJECT

    abstract_wasserflut *cut_wasserflut;        // Class 1 Under Test
    abstract_alarm *cut_alarm;                  // Class 2 Under Test
    wasserstandssensor *cut_wasserstandssensor; // Class 3 Under Test

    //Choosing which implementation to run
    wasserflut *wf;
    alarm_mockup *al;

public:
    test_wasserflut_alarm();

    // Some special values for testing
    const double wasserstand_1_GUELTIG = WASSERSTAND_THRESHOLD - 1;
    const double wasserstand_2_UNGUELTIG = WASSERSTAND_THRESHOLD + 1;

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
