#pragma once
#include <QObject>
#include <QtTest/QTest>
#include <QString>

#include "switcher.h"
#include "gluehbirne.h"
#include "raum.h"

class test_switcher_integration : public QObject
{
    Q_OBJECT

    // Classes Under Test
    switcher *cut_switcher;
    gluehbirne *cut_gluehbirne;

public:
    test_switcher_integration();

    // Some special values for testing
    const QString zimmer_gueltig = "Wohnzimmer";
    const QString zimmer_ungueltig = "Babyzimmer";

    const int helligkeit_1_gueltig = 1 ;
    const int helligkeit_ungueltig_low = -6 ;
    const int helligkeit_ungueltig_high = 6 ;

private slots:
    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases
    void test_integration_switcher();
};
