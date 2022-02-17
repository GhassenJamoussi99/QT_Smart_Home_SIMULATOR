#pragma once

#include "wasserstandssensor.h"
#include "abstract_wasserflut.h"

#include "alarm.h"
#include "abstract_alarm.h"
#include "macros.h"

class ParameterExceptionWF{};

class wasserflut : public abstract_wasserflut
{   
    private:
    wasserstandssensor *ws_;
    bool wasserflut_zustand;

    public:
    wasserflut();

    void check_wasserstand(abstract_alarm *al);
    bool get_zustand();
    virtual ~wasserflut();
};
