#pragma once

#include "abstract_authentifizierung.h"

#include <iostream>
#include <string>
#include <QDialog>

#include "haustuer.h"
#include "led.h"
#include "singleton.h"
#include "macros.h"

using namespace std;
class abstract_alarm;
class alarm;
class haustuer;
class led;

class Parameter_Exception_auth {}; //For testing purposes

class authentifizierung : public QObject, public Singleton<authentifizierung>, public abstract_authentifizierung
{
    Q_OBJECT

    private:

       pass_state auth_zustand; //for testing purposes
       int tryouts = 0;
       bool block = false;
       bool led_status = false;
       std::string passwort_= "not set";
       std::vector<std::string> messages_;
       haustuer *haustuer_;
       led *led_;
       authentifizierung *pass_;

    public:
       authentifizierung();
       void check_passwort_fuer_alarm(abstract_alarm *al);
       void check_passwort_fuer_led(led *led_);
       void login_password();
       void setPasswort(string passwort);
       string getPasswort();
       void setTryouts(int m_tryouts);
       int getTryouts();
       pass_state get_auth_zustand();  //For testing purposes
       void clear_auth_states();       //For testing purposes
       virtual ~authentifizierung();

    signals:
       void objectsUpdatedauth();
};
