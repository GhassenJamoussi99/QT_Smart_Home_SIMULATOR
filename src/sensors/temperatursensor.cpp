#include "temperatursensor.h"

temperatursensor::temperatursensor()
{
   tempraturwert_ = 0;
}

void temperatursensor::set_sensor_value(int m_temperatur)
{
    tempraturwert_ = m_temperatur;
}

int temperatursensor::get_sensor_value()
{
    return tempraturwert_;
}
