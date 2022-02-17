#pragma once

#include "rauchmelder.h"
#include "abstract_rauchmelder.h"

#include <QObject>
#include <QtTest/QTest>

#include "alarm_mockup.h"
#include "temperatursensor.h"
#include "abstract_alarm.h"

class test_rauchmelder_alarm : public QObject
{

    Q_OBJECT

    // Class Under Test

        abstract_rauchmelder *cut_rauchmelder;        // Class 1 Under Test
        abstract_alarm *cut_alarm;                  // Class 2 Under Test

        temperatursensor *cut_tempratursensor; // Class 3 Under Test

        //Choosing which implementation to run
        rauchmelder *rm_;
        alarm_mockup *alrm_;

    public:
        test_rauchmelder_alarm();

        // Some special values for testing
        const int tempratursensor_1_HOCH = RAUCHMELDER_THRESHOLD +150 ;
        const int tempratursensor_1_NORMAL = RAUCHMELDER_THRESHOLD - 30;
        const int tempratursensor_1_MINUS = RAUCHMELDER_THRESHOLD - 200;

    private slots:

        // Executed by QtTest before and after test suite
        void initTestCase() {};
        void cleanupTestCase() {};

        // Executed by QtTest before and after each test
        void init();
        void cleanup();

   // Test_Methode
   void test_checkout_rauchmelder();

};
