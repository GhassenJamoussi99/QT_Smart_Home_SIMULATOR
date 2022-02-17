#include "pir_sensor.h"

pir_sensor::pir_sensor()
{
    pir_sensor_zustand_ = false;
}

void pir_sensor::set_sensor_value(bool m_pirsensor)
{
    pir_sensor_zustand_ = m_pirsensor;
}

bool pir_sensor::get_sensor_value()
{
    return pir_sensor_zustand_;
}

