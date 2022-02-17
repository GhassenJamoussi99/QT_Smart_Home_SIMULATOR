#pragma once

#include "abstract_rauchmelder.h"
#include "abstract_alarm.h"

#define RAUCHMELDER_THRESHOLD 50

class ParameterExceptionRM{};
class abstract_wasserflut;
class alarm;

class rauchmelder_mockup : public abstract_rauchmelder
{
  bool rauchmelder_zustand_;

  public:
  rauchmelder_mockup();
  void check_temperatur(abstract_alarm *al);
  bool get_rauchmelder_zustand();
   ~rauchmelder_mockup(){}
};
