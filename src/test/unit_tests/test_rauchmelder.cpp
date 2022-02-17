#include "test_rauchmelder.h"
#include <vector>
#include <iostream>

// Dictates behaviour of wasserflut
int test_rauchmelder::TEMPERATUR_SENSOR_VALUE = 0;

test_rauchmelder::test_rauchmelder(): QObject(nullptr) {}

void test_rauchmelder::init()
{
    rauchmelder_mockup rm;
    cut_= &rm;

}

void test_rauchmelder::cleanup()
{
    cut_ = 0;
}

void test_rauchmelder::test_check_temperatur()
{
    /*-------------------------------------------*/

    TEMPERATUR_SENSOR_VALUE = RAUCHMELDER_THRESHOLD +77 ;

    try {
    cut_->check_temperatur(nullptr);
    } catch (ParameterExceptionRM & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_rauchmelder_zustand() == true);

    /*-------------------------------------------*/

    TEMPERATUR_SENSOR_VALUE = RAUCHMELDER_THRESHOLD -55 ;

    try {
    cut_->check_temperatur(nullptr);
    } catch (ParameterExceptionRM & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_rauchmelder_zustand() == false);
}

