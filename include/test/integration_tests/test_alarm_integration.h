#ifndef TEST_ALARM_INTEGRATION_H
#define TEST_ALARM_INTEGRATION_H

#include "alarm.h"
#include "abstract_alarm.h"

#include <QObject>
#include <QtTest/QTest>
#include <iostream>

#include "authentifizierung.h"
#include "abstract_authentifizierung.h"
#include "wasserstandssensor.h"
#include "temperatursensor.h"
#include "pir_sensor.h"

class test_alarm_integration : public QObject
{
    Q_OBJECT

    // Classes Under Test
    alarm  *cut_alarm;
    authentifizierung *cut_authentifizierung;
    wasserstandssensor *cut_wasserstandssensor;
    temperatursensor *cut_temperatursensor;
    pir_sensor *cut_pirsensor;

    /* Note : here we're not going to use the abstract declarations(e.g abstract_alarm)
     * because it's not needed and because we're going to test the default immplementation
     * and not mockups.
     */

public:
    test_alarm_integration();

    // Some special values for testing
    const double wasserstand_gueltig = WASSERSTAND_THRESHOLD - 1;
    const double wasserstand_ungueltig = WASSERSTAND_THRESHOLD + 1;
    
    const int temperatur_gueltig  = RAUCHMELDER_THRESHOLD - 20;    
    const int temperatur_ungueltig  = RAUCHMELDER_THRESHOLD + 20;

    const bool pirsensor_gueltig = false;
    const bool pirsensor_ungueltig = true;

    const string passwort_gueltig = SECURE_PASSWORD;
    const string passwort_ungueltig = "$ÄasQw>=?";

    const int tryouts_gueltig_0 = 0;
    const int tryouts_gueltig_1 = 1;
    const int tryouts_gueltig_2 = 2;
    const int tryouts_ungueltig = 3;

private slots:
    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases
    void test_update();

};

#endif // TEST_ALARM_INTEGRATION_H
