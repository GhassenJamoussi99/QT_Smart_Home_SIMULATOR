#include "test_fenstersicherung.h"

#include <vector>
#include <iostream>

// Dictates behaviour of validator
bool test_fenstersicherung::PIR_SENSOR_WERT=0;

test_fenstersicherung::test_fenstersicherung() : QObject(nullptr) {}

void test_fenstersicherung::init()
{
    fenstersicherung_mockup fnst;
    cut_ = &fnst;
}

void test_fenstersicherung::cleanup()
{
    cut_ = 0;
}

void test_fenstersicherung::test_check_pirsensor()
{
    /**************************************/
    PIR_SENSOR_WERT = PIR_THRESHOLD  ;

    try {
    cut_->check_PIR(nullptr);
    } catch (ParameterExceptionFS & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_fenster_zustand() == false);

    /**************************************/
    PIR_SENSOR_WERT = !PIR_THRESHOLD;

    try {
    cut_->check_PIR(nullptr);
    } catch (ParameterExceptionFS & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_fenster_zustand() == true);

}
