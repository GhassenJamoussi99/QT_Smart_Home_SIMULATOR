#include "rauchmelder.h"
#include <QDebug>

rauchmelder::rauchmelder()
{
    temperatur_sensor_ = temperatursensor::get_instance();
}

void rauchmelder::check_temperatur(abstract_alarm *al)
{
    int temp = temperatur_sensor_->get_sensor_value();

    if (temp >= RAUCHMELDER_THRESHOLD)
    {
        al->add_message("Achtung! Temperatur zu hoch");
        al->an();
        rauchmelder_zustand = true;
    }
    else if (temp < RAUCHMELDER_THRESHOLD){
        al->remove_message("Achtung! Temperatur zu hoch");
        if (al->is_message_empty())
        {
            qDebug()<< "Keine Nachrichten";
            al->aus();
        }
        rauchmelder_zustand = false;
    }

}
bool rauchmelder::get_rauchmelder_zustand(){
    return  rauchmelder_zustand;
}

void rauchmelder::setMessage(string m_nachricht){
    nachricht = m_nachricht;
}

string rauchmelder ::getMessage(){
    return nachricht;
}

rauchmelder::~rauchmelder()
{
  temperatur_sensor_->delete_instance();
  temperatur_sensor_ = 0;
}

