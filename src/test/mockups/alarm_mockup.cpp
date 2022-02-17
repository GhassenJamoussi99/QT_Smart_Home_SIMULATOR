#include "alarm_mockup.h"
#include "test_alarm.h"
#include <QDebug>

alarm_mockup::alarm_mockup()
{
    qDebug()<<"alarm Constructor";
}

void alarm_mockup::update()
{
    //Checking sensors
    qDebug() << "--------------------------Checking mockup sensors---------------------------";

    alarm_status = test_alarm::wasserflut_status || test_alarm::rauchmelder_status || test_alarm::fenstersicherung_status || test_alarm::authentifizierung_status;

    qDebug() << "------------------All sensors have been checked----------------------";
}

void alarm_mockup::add_message(std::string msg)
{
    bool ok = 0;
    QString qstr = QString::fromStdString(msg);
    qDebug() << "Adding a new message : " << qstr;

    for (unsigned i=0; i < messages_.size(); i++)
    {
        if (messages_[i] == msg)
        {
           ok = 1;
           break;
        }
    }

    if (ok == 0)
        messages_.push_back(msg);
}

void alarm_mockup::remove_message(std::string msg)
{
    int idx = 0;

    for (unsigned i=0; i < messages_.size();i++)
    {
        if (messages_[i] == msg)
        {
            idx = i;
            messages_.erase(messages_.begin()+idx); 
            break;
        }
    }
}

bool alarm_mockup::is_message_empty()
{
    if (messages_.empty())
        return true;
    else
        return false;
}

void alarm_mockup::an()
{
    alarm_status = true;
    qDebug()<<"Alarm On";
}

void alarm_mockup::clear_messages()
{
    messages_.clear();
}

void alarm_mockup::aus()
{
    alarm_status = false;
    if (this->is_message_empty())
        qDebug() << "Alarm Off";
}

bool alarm_mockup::get_fenstersicherung_status()
{
    return fenstersicherung_status;
}

bool alarm_mockup::get_rauchmelder_status()
{
    return rauchmelder_status;
}

std::vector<std::string> alarm_mockup::get_message()
{
    return messages_;
}

bool alarm_mockup::get_alarm_status()
{
    return alarm_status;
}

