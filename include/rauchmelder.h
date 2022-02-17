#pragma once

#include "abstract_rauchmelder.h"

#include <string>

#include "temperatursensor.h"
#include "abstract_alarm.h"
#include "macros.h"

using namespace std;

class rauchmelder : public abstract_rauchmelder

{
private:
  temperatursensor *temperatur_sensor_;
  string nachricht;
  bool rauchmelder_zustand;
  public:
  rauchmelder();
  void setMessage(string m_nachricht);
  string getMessage();

  void check_temperatur(abstract_alarm *al);
  bool get_rauchmelder_zustand();
  virtual ~rauchmelder();
 };


