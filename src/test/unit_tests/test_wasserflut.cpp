#include "test_wasserflut.h"

#include <vector>
#include <iostream>

// Dictates behaviour of wasserflut
double test_wasserflut::WASSERSTAND_SENSOR_WERT = 0;

test_wasserflut::test_wasserflut() : QObject(nullptr) {}

void test_wasserflut::init()
{
    wasserflut_mockup wf;
    cut_ = &wf;
}

void test_wasserflut::cleanup()
{
    cut_ = 0;
}

void test_wasserflut::test_check_wasserstand()
{
    /*-------------------------------------------*/

    WASSERSTAND_SENSOR_WERT = WASSERSTAND_THRESHOLD + 1;

    try {
    cut_->check_wasserstand(nullptr);
    } catch (ParameterExceptionWFM & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_zustand() == true);

    /*-------------------------------------------*/

    WASSERSTAND_SENSOR_WERT = WASSERSTAND_THRESHOLD - 1;

    try {
    cut_->check_wasserstand(nullptr);
    } catch (ParameterExceptionWFM & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_zustand() == false);
}
