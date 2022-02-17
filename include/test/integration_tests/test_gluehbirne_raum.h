#pragma once
#include "gluehbirne.h"

#include <QObject>
#include <QtTest/QTest>
#include <string>

#include "raum.h"
#include "switcher.h"

class test_gluehbirne_raum: public QObject
{
    Q_OBJECT

    // Classes Under Test
    raum *ra_;
    gluehbirne *cut_gluehbirne;

public:
    test_gluehbirne_raum();

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
    void test_checkout_gluehbirne_raum();

};
