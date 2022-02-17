#pragma once

class abstract_alarm;

class abstract_rauchmelder
{
    public:
    virtual void check_temperatur(abstract_alarm *al) = 0;
    virtual bool get_rauchmelder_zustand() = 0;
};
