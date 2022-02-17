#pragma once
#include <string.h>
#include <iostream>

class abstract_alarm;
class led;

struct pass_state //for testing purposes
{
 bool pass_state = false;
 bool tryouts_max = false;
};

class abstract_authentifizierung
{
    public:
    virtual void check_passwort_fuer_alarm(abstract_alarm *al) = 0;
    virtual void check_passwort_fuer_led(led *led_) = 0;
    virtual void setPasswort(std::string passwort) = 0;
    virtual std::string getPasswort() = 0;
    virtual void login_password() = 0;
    virtual void setTryouts(int m_tryouts) = 0;
    virtual int getTryouts() = 0;
    virtual void clear_auth_states() = 0;
    virtual pass_state get_auth_zustand() = 0;
};
