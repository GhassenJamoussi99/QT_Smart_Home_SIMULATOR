#include "fenstersicherung_mockup.h"
#include "test_fenstersicherung.h"
#include <QDebug>
#include "alarm.h"

fenstersicherung_mockup::fenstersicherung_mockup(){}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
void fenstersicherung_mockup::check_PIR(abstract_alarm *al)
{
#pragma GCC diagnostic pop
    al = nullptr; //To remove warnings

    bool pir_status_ = test_fenstersicherung::PIR_SENSOR_WERT;
    if (pir_status_ != PIR_THRESHOLD)
    {
        qDebug() << "Pir_zustand ist true/n";
        PIR_Sensor_zustand = true;
    }
    else if (pir_status_ == PIR_THRESHOLD)
    {
        qDebug() << "Pir_zustand ist false/n";
        PIR_Sensor_zustand = false;
    }
}

bool fenstersicherung_mockup::get_fenster_zustand()
{
    return PIR_Sensor_zustand ;
}
