#include "authentifizierung.h"
#include "led.h"
#include <iostream>
#include <string>
#include <QDebug>
#include "ui_authentifizierung_window.h"

using namespace std;

led::led()
{
    this->setRed(true);
    this->setGreen(false);
    qDebug() << "led constructor "<< this;

}

void led::update()
{
    qDebug() << "Updating LED";
    auth_ = authentifizierung::get_instance();
    auth_->check_passwort_fuer_led(this);
}

void led::setRed(bool state)
{
    redLED = state;
}

void led::setGreen(bool state)
{
    greenLED = state;
}

bool led::getRed()
{
    return redLED;
}

bool led::getGreen()
{
    return greenLED;
}

led::~led(){}
