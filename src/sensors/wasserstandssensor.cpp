#include "wasserstandssensor.h"
#include <QDebug>

wasserstandssensor::wasserstandssensor()
{
    wasserstand_= 0;
}

double wasserstandssensor::get_sensor_value()
{
    return wasserstand_;
}

void wasserstandssensor::set_sensor_value(const double m_wasserstand)
{
    wasserstand_ = m_wasserstand;
}
