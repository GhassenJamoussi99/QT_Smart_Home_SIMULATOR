#include "test_authentifizierung.h"
#include "authentifizierung_mockup.h"

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QDebug>

using namespace std;

authentifizierung_mockup::authentifizierung_mockup()
{
    qDebug()<<"Im Auth Konstruktor...";
}

void authentifizierung_mockup::login_password()
{
    if (passwort_ == SECURE_PASSWORD){
        qDebug() <<"passwort ist korrekt";
        block = false;
        led_status = true;
        tryouts = 0;
        auth_zustand.pass_state = true;
    }
    else{
        //Wenn das Passwot dreimal falsch eingegeben wurde, dann setzte block=1
        qDebug() <<"passwort ist falsch";
        led_status = false;
        block = false;
        auth_zustand.pass_state = false;
        tryouts++;
        qDebug()<<"tryouts = " << tryouts;
        if (tryouts >= 3)
        {
            qDebug()<<"Passwort wird 3 mal falsch eingegeben";
            block = true;
            auth_zustand.tryouts_max = true;
        }
     }

    emit objectsUpdatedauth();
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
void authentifizierung_mockup::check_passwort_fuer_alarm(abstract_alarm *al)
{
#pragma GCC diagnostic pop
    al = nullptr;
    qDebug()<<"Checking Passwort ...";

    if (block){ //Check if block=true(means the passwort was entered 3 times incorrectly)
        qDebug() <<"Passwort entered 3 times incorrectly therefore door blocked";
        auth_zustand.tryouts_max = true;
    }
    else if(passwort_ == SECURE_PASSWORD){
        qDebug() <<"Passwort correct";
        auth_zustand.pass_state = true;
    }
    else{
        qDebug() <<"Passwort false but not entered 3 times incorrectly";
        auth_zustand.pass_state = false;
        auth_zustand.tryouts_max = false;
    }
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
void authentifizierung_mockup::check_passwort_fuer_led(led *led_)
{
#pragma GCC diagnostic pop
    qDebug()<<"Checking LED state ...";
    led_ = nullptr;
    if (led_status){
        qDebug()<<"LED grün ...";
        auth_zustand.pass_state = true ;     //Tür offen bzw Passwort richtig
    }
    else{
        qDebug()<< "LED bleibt rot , tuer bleibt geschlossen";
        auth_zustand.pass_state = false ;   //Tür zu bzw. Passwort falsch
    }
}

pass_state authentifizierung_mockup::get_auth_zustand()
{
   return auth_zustand;
}

void authentifizierung_mockup::setPasswort(string passwort)
{
    passwort_ = passwort;
}

string authentifizierung_mockup::getPasswort()
{
    return passwort_;
}

void authentifizierung_mockup::setTryouts(int m_tryouts)
{
    tryouts = m_tryouts;
}

int authentifizierung_mockup::getTryouts()
{
    return tryouts;
}

void authentifizierung_mockup::clear_auth_states()
{
    auth_zustand.pass_state = false;
    auth_zustand.tryouts_max = false;
}

authentifizierung_mockup::~authentifizierung_mockup(){}
