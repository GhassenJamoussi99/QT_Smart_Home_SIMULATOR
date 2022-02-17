#include "wasserflut.h"
#include <QDebug>


wasserflut::wasserflut()
{
    ws_ = wasserstandssensor::get_instance();
}

void wasserflut::check_wasserstand(abstract_alarm *al)
{
    double wasserstand_ = ws_->get_sensor_value();
    qDebug() << "wassetstand = " << wasserstand_; ;

    if (wasserstand_ >= WASSERSTAND_THRESHOLD)
    {
        qDebug() << "wasserstand  >= WASSERSTAND_THRESHOLD/n";
        al->add_message("Achtung! Wasserstand zu hoch");
        al->an();
        wasserflut_zustand = true;

    }
    else if (wasserstand_ < WASSERSTAND_THRESHOLD)
    {
        qDebug() << "wasserstand  < WASSERSTAND_THRESHOLD/n";
        al->remove_message("Achtung! Wasserstand zu hoch");
        if (al->is_message_empty())
        {
            qDebug()<< "Keine Nachrichten";
            al->aus();
        }
        wasserflut_zustand = false;
    }
}

bool wasserflut::get_zustand()
{
    return wasserflut_zustand;
}

wasserflut::~wasserflut()
{
    ws_->delete_instance();
    ws_ = 0;
}
