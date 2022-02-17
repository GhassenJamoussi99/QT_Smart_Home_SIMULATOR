#include "rauchmelder_mockup.h"
#include "test_rauchmelder.h"
#include <QDebug>
#include "alarm.h"


rauchmelder_mockup::rauchmelder_mockup(){}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"

void rauchmelder_mockup::check_temperatur(abstract_alarm *al)
{
#pragma GCC diagnostic pop
    al = nullptr; //To remove syntax warnings

    int tempraturstatus_ = test_rauchmelder::TEMPERATUR_SENSOR_VALUE;

    if (tempraturstatus_ > RAUCHMELDER_THRESHOLD)
    {
        qDebug() << "tempraturstatus_ > RAUCHMELDER_THRESHOLD/n";
        rauchmelder_zustand_ = true;
    }
    else if (tempraturstatus_ <= RAUCHMELDER_THRESHOLD)
    {
        qDebug() << "tempraturstatus_ <= RAUCHMELDER_THRESHOLD/n";
        rauchmelder_zustand_ = false;
    }
}


bool rauchmelder_mockup::get_rauchmelder_zustand()
{
    return rauchmelder_zustand_;
}
