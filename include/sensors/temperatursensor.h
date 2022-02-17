#pragma once

#include "singleton.h"

class temperatursensor : public Singleton<temperatursensor>
{
  int tempraturwert_;

public:
  temperatursensor();
  void set_sensor_value(int m_temperatur);
  int get_sensor_value();
  virtual ~temperatursensor() {}
};
