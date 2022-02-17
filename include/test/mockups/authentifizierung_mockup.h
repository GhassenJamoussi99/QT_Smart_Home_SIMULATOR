#pragma once

#include "abstract_authentifizierung.h"

#include <iostream>
#include <string>
#include <QDialog>

#include "singleton.h"

#define SECURE_PASSWORD "azer"

using namespace std;

class abstract_alarm;
class led;

class Parameter_Exception {}; //For testing purposes

class authentifizierung_mockup : public QObject, public Singleton<authentifizierung_mockup>, public abstract_authentifizierung
{
    Q_OBJECT

    private:
       int tryouts = 0;
       pass_state auth_zustand; //For testing purposes : True when passwort is correct or not entered 3 times incorrectly , false when passwort is 3 times enetred incorrectly.
       bool try_3_zustand = false;
       bool block = false;
       bool led_status = false;
       std::string passwort_= "not set";
       std::vector<std::string> messages_;


    public:
       authentifizierung_mockup();
       void setPasswort(string passwort);
       string getPasswort();
       void check_passwort_fuer_alarm(abstract_alarm *al);
       void login_password();
       void check_passwort_fuer_led(led *led_);
       void setTryouts(int m_tryouts);          //For testing purposes
       int getTryouts();                        //For testing purposes
       void clear_auth_states();                     //For testing purposes
       pass_state get_auth_zustand();
       virtual ~authentifizierung_mockup();

    signals:
       void objectsUpdatedauth();
};
