#include "authentifizierung.h"

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QDebug>

#include "led.h"
#include "raum.h"
#include "alarm.h"
#include "abstract_alarm.h"
#include "macros.h"

using namespace std;

authentifizierung::authentifizierung()
{
    qDebug()<<"Im Auth Konstruktor...";

    haustuer_ = haustuer::get_instance();
    led_ = led::get_instance();
}

void authentifizierung::login_password()
{
    if (passwort_==SECURE_PASSWORD){
        block = false;
        led_status = true;
        tryouts = 0;
        haustuer_->setState(offen);
        led_->setGreen(true);
        auth_zustand.pass_state = true; //for testing purposes
    }
    else
    {
        //Wenn das Passwot dreimal falsch eingegeben wurde, dann setzte block=1
        led_status = false;
        block = false;
        haustuer_->setState(geschlossen);
        auth_zustand.pass_state = false; //for testing purposes
        tryouts++;
        qDebug()<<"tryouts = " << tryouts;
        led_->setRed(true);
        if (tryouts >= 3)
        {
            haustuer_->setState(verschlossen);
            qDebug()<<"Passwort wird 3 mal falsch eingegeben";
            block = true;
            auth_zustand.tryouts_max = true; //for testing purposes
        }
     }

    emit objectsUpdatedauth(); 
}

void authentifizierung::check_passwort_fuer_alarm(abstract_alarm *al){
    qDebug()<<"Checking Passwort ...";

    if (block){
        qDebug() << "Tryouts exceeded/ block =" << block;
        al->add_message("Achtung! Passwort dreimal falsch eingegeben!");
        al->an();
        auth_zustand.tryouts_max = true; //for testing purposes
    }
    else{
        qDebug() << "Tryouts not exceeded/ block =" << block;
        al->remove_message("Achtung! Passwort dreimal falsch eingegeben!");
        auth_zustand.tryouts_max = false; //for testing purposes
        if (al->is_message_empty())
        {
            qDebug()<< "Keine Nachrichten";
            al->aus();
        }
    }
}

void authentifizierung::check_passwort_fuer_led(led *led_)
{
    qDebug()<<"Checking LED state ...";

    if (led_status){
        qDebug()<<"LED grün ...";
        led_->setRed(false);
        led_->setGreen(true);
        auth_zustand.pass_state = true; //for testing purposes
    }
    else{
        qDebug()<< "LED bleibt rot , tuer bleibt geschlossen";
        led_->setGreen(false);
        led_->setRed(true);
        auth_zustand.pass_state = false ; //for testing purposes
    }
}

pass_state authentifizierung::get_auth_zustand()
{
   return auth_zustand;
}

void authentifizierung::setPasswort(string passwort)
{
    passwort_ = passwort;
}

string authentifizierung::getPasswort()
{
    return passwort_;
}

void authentifizierung::setTryouts(int m_tryouts)
{
    tryouts = m_tryouts;
}

//for testing purposes
void authentifizierung::clear_auth_states() 
{
    auth_zustand.pass_state = false;
    auth_zustand.tryouts_max = false;
}

int authentifizierung::getTryouts()
{
    return tryouts;
}

authentifizierung::~authentifizierung()
{
    haustuer_->delete_instance();
    led_->delete_instance();

    haustuer_ = 0;
    led_ = 0;
}
