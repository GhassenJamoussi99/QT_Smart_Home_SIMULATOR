#include "test_rauchmelder_alarm.h"
#include "macros.h"

test_rauchmelder_alarm::test_rauchmelder_alarm() : QObject(nullptr) {}

void test_rauchmelder_alarm::init()
{
    rm_ = new rauchmelder();
    alrm_ = new alarm_mockup();

    try {

        cut_tempratursensor = temperatursensor::get_instance();
        cut_rauchmelder = rm_;
        cut_alarm = alrm_;

    }  catch (ParameterException &pe) {
        QFAIL("Failed to create instances");
    }

}

void test_rauchmelder_alarm::cleanup()
{
    SAFE_DELETE(rm_);
    SAFE_DELETE(alrm_);
    cut_tempratursensor->delete_instance();

    cut_alarm = 0;
    cut_rauchmelder = 0;
    cut_tempratursensor = 0;

}

void test_rauchmelder_alarm::test_checkout_rauchmelder()
{
    alrm_->aus();
    cut_tempratursensor->set_sensor_value(tempratursensor_1_NORMAL);
    cut_rauchmelder->check_temperatur(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 0);

    ////////////////////////////////////////////

    alrm_->an();
    cut_tempratursensor->set_sensor_value(tempratursensor_1_HOCH);
    cut_rauchmelder->check_temperatur(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 1);


    ////////////////////////////////////////////

    alrm_->an();
    cut_tempratursensor->set_sensor_value(tempratursensor_1_MINUS);
    cut_rauchmelder->check_temperatur(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 0);
}
