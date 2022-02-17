#pragma once

#include "fenstersicherung_mockup.h"
#include "abstract_fenstersicherung.h"

#include <QObject>
#include <QtTest/QTest>
#include <string>

class test_fenstersicherung : public QObject
{
    Q_OBJECT

    abstract_fenstersicherung *cut_; // Class Under Test

public:
    test_fenstersicherung();

    // Dictates the answer of the temperatursensor mockup
    static bool PIR_SENSOR_WERT;

private slots:

    // Executed by QtTest before and after test suite
    void initTestCase() {};
    void cleanupTestCase() {};

    // Executed by QtTest before and after each test
    void init();
    void cleanup();

    // Testcases
    void test_check_pirsensor();
};

