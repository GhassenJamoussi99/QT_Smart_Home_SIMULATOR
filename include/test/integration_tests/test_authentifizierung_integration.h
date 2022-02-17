#pragma once

#include "authentifizierung.h"
#include <QObject>
#include <QtTest/QTest>
#include <string>

class test_authentifizierung_integration : public QObject
{
    Q_OBJECT

    authentifizierung * cut_authentifizierung; // Class Under Test
    alarm *cut_alarm;
    haustuer *cut_haustuer;
    led *cut_led;

public:
    test_authentifizierung_integration();

    // Some special values for testing
    const string passwort_gueltig = SECURE_PASSWORD;
    const string passwort_ungueltig = "zzz";

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

    // Test addition of two valid values
    // Expected: 23 + 23 = 46
    void test_passwort_fuer_alarm();
    void test_passwort_fuer_led();

};

