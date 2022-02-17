#include <QtTest/QTest>
#include <QApplication>

//Unittests
#include "test_authentifizierung.h"
#include "test_alarm.h"
#include "test_wasserflut.h"
#include "test_fenstersicherung.h"
#include "test_rauchmelder.h"
#include "test_gluehbirne.h"

//Integrationtests
#include "test_alarm_integration.h"
#include "test_wasserflut_alarm.h"
#include "test_fenstersicherung_alarm.h"
#include "test_switcher_integration.h"
#include "test_rauchmelder_alarm.h"
#include "test_gluehbirne_raum.h"
#include "test_authentifizierung_integration.h"

//Systemtest
#include "test_system.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    //Unittests
    test_authentifizierung testcases_authentifizierung;
    test_alarm testcases_alarm;
    test_wasserflut testcases_wasserflut;
    test_fenstersicherung testcases_fenstersicherung;
    test_rauchmelder testcases_rauchmelder;
    test_gluehbirne testcases_gluehbirne;

    //Integrationtests
    test_wasserflut_alarm testcases_wasserflut_alarm;
    test_alarm_integration testcases_alarm_integration;
    test_authentifizierung_integration testcases_authentifizierung_integration;
    test_fenstersicherung_alarm testcases_fenstersicherung_alarm;
    test_rauchmelder_alarm testcases_rauchmelder_alarm;
    test_switcher_integration testcases_switcher_integration;
    test_gluehbirne_raum testcases_test_gluehbirne_raum;

    //Systemtest
    test_system testcase_system;


    /* QTest::qExec(&test) returns 0 if no tests failed, or a value other than 0
     * if one or more tests failed or in case of unhandled exceptions.
     */

    //-----------> Run tests

    //---> Unittests
    if (QTest::qExec(&testcases_wasserflut, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_alarm, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_gluehbirne, argc, argv))
           return 1;
    else if (QTest::qExec(&testcases_authentifizierung, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_fenstersicherung, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_rauchmelder, argc, argv))
        return 1;
    //---> Integrationtests
    else if (QTest::qExec(&testcases_wasserflut_alarm, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_alarm_integration, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_fenstersicherung_alarm, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_rauchmelder_alarm, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_switcher_integration, argc, argv))
        return 1;
    else if (QTest::qExec(&testcases_test_gluehbirne_raum, argc, argv))
        return 1;
    else if(QTest::qExec(&testcases_authentifizierung_integration, argc, argv))
        return 1;
    //---> Systemtest
    else if(QTest::qExec(&testcase_system, argc, argv))
        return 1;
    else
        return 0;
}
