#pragma once

#include "abstract_fenstersicherung.h"

#define PIR_THRESHOLD false

class alarm;
class ParameterExceptionFS{};
class abstract_fenstersicherung;


class fenstersicherung_mockup : public abstract_fenstersicherung
{
    private:
    bool PIR_Sensor_zustand;

    public:
    fenstersicherung_mockup();
    bool get_fenster_zustand();
    void check_PIR(abstract_alarm *al);

    ~fenstersicherung_mockup(){}
};
