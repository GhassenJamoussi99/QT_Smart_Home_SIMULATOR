#ifndef TEST_AUTHENTIFIZIERUNG_H
#define TEST_AUTHENTIFIZIERUNG_H

#include "authentifizierung_mockup.h"
#include "abstract_authentifizierung.h"

#include <QObject>
#include <QtTest/QTest>
#include <string>

using namespace std;

class test_authentifizierung : public QObject
{
    Q_OBJECT

    //Class under test
    abstract_authentifizierung *cut_;

    //Choosing which implementation to run
    authentifizierung_mockup *auth;

public:
    test_authentifizierung();

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

    // Testcases
    void test_passwort_fuer_alarm();
    void test_passwort_fuer_led();
};


#endif // TEST_AUTHENTIFIZIERUNG_H
