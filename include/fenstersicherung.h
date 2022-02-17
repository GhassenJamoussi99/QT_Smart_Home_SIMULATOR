#pragma once

#include "abstract_fenstersicherung.h"

#include <string>

#include "pir_sensor.h"
#include "abstract_alarm.h"

using namespace std;

class fenstersicherung : public abstract_fenstersicherung
{
  private:
  string nachricht;
  pir_sensor *pir_sensor_;
  bool fenst_zustand;
  public:

  fenstersicherung();
  void setMessage(string m_nachricht);
  string getMessage();
  bool get_fenster_zustand();
  void check_PIR(abstract_alarm *al);
  virtual ~fenstersicherung();

 };


