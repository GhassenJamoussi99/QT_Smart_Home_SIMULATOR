#pragma once

#include "abstract_wasserflut.h"

#define WASSERSTAND_THRESHOLD 4.5

class ParameterExceptionWFM{}; //For testing purposes

class alarm_mockup;
class abstract_wasserflut;


class wasserflut_mockup : public abstract_wasserflut
{   
    private:
    bool wasserflut_zustand;

    public:
    wasserflut_mockup();
    void check_wasserstand(abstract_alarm *al);
    bool get_zustand();
    ~wasserflut_mockup(){}
};
