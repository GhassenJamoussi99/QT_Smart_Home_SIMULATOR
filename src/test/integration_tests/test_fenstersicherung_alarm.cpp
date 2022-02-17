#include "test_fenstersicherung_alarm.h"
#include "macros.h"

test_fenstersicherung_alarm::test_fenstersicherung_alarm() : QObject(nullptr) {}

void test_fenstersicherung_alarm::init()
{
    fs_ = new fenstersicherung();
    alrm_ = new alarm_mockup();

    try {

        cut_pirsensor = pir_sensor::get_instance();
        cut_fenstersicherung = fs_;
        cut_alarm = alrm_;

    }  catch (ParameterException &pe) {
        QFAIL("Failed to create instances");
    }

}

void test_fenstersicherung_alarm::cleanup()
{
    SAFE_DELETE(fs_);
    SAFE_DELETE(alrm_);
    cut_pirsensor->delete_instance();

    cut_alarm = 0;
    cut_fenstersicherung = 0;
    cut_pirsensor = 0;

}

void test_fenstersicherung_alarm::test_checkout_fenstersicherung()
{
    cut_alarm->an(); //Vorbedingung
    cut_pirsensor->set_sensor_value(aus_status);
    cut_fenstersicherung->check_PIR(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 0);

    ////////////////////////////////////////////

    cut_alarm->aus(); //Vorbedingung
    cut_pirsensor->set_sensor_value(an_status);
    cut_fenstersicherung->check_PIR(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 1);

}
