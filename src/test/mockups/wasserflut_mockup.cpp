#include "test_wasserflut.h"
#include "wasserflut_mockup.h"
#include <QDebug>
#include "alarm.h"


wasserflut_mockup::wasserflut_mockup() {}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
void wasserflut_mockup::check_wasserstand(abstract_alarm *al)
{
#pragma GCC diagnostic pop
    al = nullptr; //To remove syntax warnings
    double wasserstand_ = test_wasserflut::WASSERSTAND_SENSOR_WERT;

    if (wasserstand_ >= WASSERSTAND_THRESHOLD)
    {
        qDebug() << "wasserstand  >= WASSERSTAND_THRESHOLD/n";
        wasserflut_zustand = true;
    }
    else if (wasserstand_ < WASSERSTAND_THRESHOLD)
    {
        qDebug() << "wasserstand  < WASSERSTAND_THRESHOLD/n";
        wasserflut_zustand = false;
    }
}

bool wasserflut_mockup::get_zustand()
{
    return wasserflut_zustand;
}
