#pragma once

#include <iostream>
#include <string.h>

#include "singleton.h"

class wasserstandssensor : public Singleton<wasserstandssensor>
{   

    private:
    double wasserstand_;

    public:
    wasserstandssensor();
    double get_sensor_value();
    void set_sensor_value(const double m_wasserstand);
    ~wasserstandssensor(){}
};
