#pragma once

#include <iostream>
#include "singleton.h"

class pir_sensor : public Singleton<pir_sensor>
{
  bool pir_sensor_zustand_;

public:
  pir_sensor();// = default;
  void set_sensor_value(bool m_pirsensor);
  bool get_sensor_value();
  virtual ~pir_sensor() {}
};
