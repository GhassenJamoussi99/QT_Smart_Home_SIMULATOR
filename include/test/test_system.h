#pragma once

#include <QObject>
#include <QtTest>
#include <QString>

#include "alarm.h"
#include "wasserstandssensor.h"
#include "temperatursensor.h"
#include "pir_sensor.h"
#include "raum.h"
#include "gluehbirne.h"
#include "haustuer.h"
#include "led.h"
#include "switcher.h"


class test_system : public QObject
{
    Q_OBJECT

    // Classes Under Test
    alarm *cut_alarm;
    wasserstandssensor *cut_wasserstandssensor;
    temperatursensor *cut_temperatursensor;
    pir_sensor *cut_pirsensor;
    authentifizierung *cut_authentifizierung;
    switcher *cut_switch;
    haustuer *cut_haustuer;
    led *cut_led;
    gluehbirne *cut_gluehbirne;

public:
    test_system();

    // Some special values for testing the success Scenario
    const QString zimmer_1_gueltig = "Wohnzimmer";
    const QString zimmer_2_gueltig = "Schlafzimmer";
    const QString zimmer_3_gueltig = "Badezimmer";
    const QString zimmer_4_gueltig = "Keller";
    const QString zimmer_5_gueltig = "Kueche";

    const int helligkeit_1_gueltig = 1;
    const int helligkeit_2_gueltig = 2;
    const int helligkeit_3_gueltig = 3;

    const int tryouts_gueltig = 0;

    const string passwort_gueltig = SECURE_PASSWORD;

    const bool pir_sensor_triggered = true;
    const float wasserstand_sensor_triggered = WASSERSTAND_THRESHOLD;
    const int temperatur_sensor_triggered = RAUCHMELDER_THRESHOLD;

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
