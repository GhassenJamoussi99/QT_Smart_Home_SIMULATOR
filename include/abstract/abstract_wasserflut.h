#pragma once

class abstract_alarm;

class abstract_wasserflut
{
    public:
    virtual void check_wasserstand(abstract_alarm *al) = 0;
    virtual bool get_zustand() = 0;
};
