#pragma once

#include "fenstersicherung.h"
#include "abstract_fenstersicherung.h"

#include <QObject>
#include <QtTest/QTest>

#include "abstract_alarm.h"
#include "alarm_mockup.h"
#include "pir_sensor.h"

class test_fenstersicherung_alarm : public QObject
{

    Q_OBJECT

    // Class Under Test

        abstract_fenstersicherung *cut_fenstersicherung;        // Class 1 Under Test
        abstract_alarm *cut_alarm;                  // Class 2 Under Test
        pir_sensor *cut_pirsensor; // Class 3 Under Test

        //Choosing which implementation to run
        fenstersicherung *fs_;
        alarm_mockup *alrm_;

    public:
        test_fenstersicherung_alarm();

        // Some special values for testing
        const bool an_status = true;
        const bool aus_status = false;

    private slots:

        // Executed by QtTest before and after test suite
        void initTestCase() {};
        void cleanupTestCase() {};

        // Executed by QtTest before and after each test
        void init();
        void cleanup();

   // Test_Methode
   void test_checkout_fenstersicherung();

};
