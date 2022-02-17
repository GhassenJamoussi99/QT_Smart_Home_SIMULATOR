#pragma once

class abstract_alarm;

class abstract_fenstersicherung
{
    public:
    virtual void check_PIR(abstract_alarm *al) = 0;
    virtual bool get_fenster_zustand() = 0;
};
