#pragma once

#include "alarm_mockup.h"
#include "abstract_alarm.h"

#include <QObject>
#include <QtTest>
#include <string.h>

class test_alarm : public QObject
{
    Q_OBJECT

    abstract_alarm *cut_; // Class Under Test

public:
    test_alarm();

    // Some special values for testing
    const std::string message_1 = "12345";
    const std::string message_2 = "azerty";
    const std::string message_3 = "######";

    // Dictates the behavior of classes
    static bool wasserflut_status;
    static bool rauchmelder_status;
    static bool fenstersicherung_status;
    static bool authentifizierung_status;

private slots:

    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases
    void test_add_message();
    void test_remove_message();
    void test_remove_messages();
    void test_update();
};

