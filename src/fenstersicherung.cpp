#include "fenstersicherung.h"
#include <QDebug>

fenstersicherung::fenstersicherung()
{
    pir_sensor_ = pir_sensor::get_instance();
}

void fenstersicherung::check_PIR(abstract_alarm *al) {
    bool fenster_zustand = pir_sensor_->get_sensor_value();

    if (fenster_zustand == true)
    {
        qDebug() << "Pir is " << fenster_zustand;
        al->add_message("Achtung! EINBRECHER !");
        al->an();
        fenst_zustand = true;
    }
    else if (fenster_zustand == false)
    {
        qDebug() << "Pir is " << fenster_zustand;
        al->remove_message("Achtung! EINBRECHER !");
        if (al->is_message_empty())
        {
            qDebug()<< "Keine Nachrichten";
            al->aus();
            fenst_zustand = false;
        }

    }
}
bool fenstersicherung::get_fenster_zustand(){
    return fenst_zustand;;
}

void fenstersicherung::setMessage(string msg){
    nachricht = msg;
}

string fenstersicherung::getMessage(){
    return nachricht;
}

fenstersicherung::~fenstersicherung()
{
   pir_sensor_->delete_instance();
   pir_sensor_ = 0;
}
