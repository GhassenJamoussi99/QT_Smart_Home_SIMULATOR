#include "test_wasserflut_alarm.h"
#include "macros.h"

test_wasserflut_alarm::test_wasserflut_alarm() : QObject(nullptr) {}

void test_wasserflut_alarm::init()
{
    wf = new wasserflut();
    al = new alarm_mockup();

    try {
        cut_wasserstandssensor = wasserstandssensor::get_instance();
        cut_wasserflut = wf;
        cut_alarm = al;
    }  catch (ParameterExceptionWF &pe) {
        QFAIL("Failed to create instances");
    }

}

void test_wasserflut_alarm::cleanup()
{
    cut_wasserstandssensor->delete_instance();
    SAFE_DELETE(al);
    SAFE_DELETE(wf);

    cut_wasserflut = 0;
    cut_alarm = 0;
    cut_wasserstandssensor = 0;
}

void test_wasserflut_alarm::test_check_wasserstand()
{
    cut_alarm->aus();
    cut_wasserstandssensor->set_sensor_value(wasserstand_1_GUELTIG);
    cut_wasserflut->check_wasserstand(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 0);

    ////////////////////////////////////////////

    cut_alarm->aus();
    cut_wasserstandssensor->set_sensor_value(wasserstand_2_UNGUELTIG);
    cut_wasserflut->check_wasserstand(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 1);

    ////////////////////////////////////////////

    cut_alarm->an();
    cut_wasserstandssensor->set_sensor_value(wasserstand_2_UNGUELTIG);
    cut_wasserflut->check_wasserstand(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 1);

    ////////////////////////////////////////////

    cut_alarm->an();
    cut_wasserstandssensor->set_sensor_value(wasserstand_1_GUELTIG);
    cut_wasserflut->check_wasserstand(cut_alarm);
    QVERIFY(cut_alarm->get_alarm_status() == 0);
}
