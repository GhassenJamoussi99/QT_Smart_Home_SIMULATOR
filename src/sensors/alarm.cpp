#include "alarm.h"

#include <QDebug>

#include "macros.h"

alarm::alarm()
{
    qDebug()<<"alarm Constructor..."<< this <<"...";

    wasserflut_ = new wasserflut();
    rauchmelder_ = new rauchmelder();
    fenstersicherung_ = new fenstersicherung();
    auth_ = authentifizierung::get_instance();
}

void alarm::update()
{
    //Default state
    qDebug() << "--------------------------Checking sensors----"<<this<<"---------------------";

    //Checking sensors
    qDebug()<<"Wasserflut checken";
    wasserflut_->check_wasserstand(this);

    qDebug()<<"Rauchmelder checken";
    rauchmelder_->check_temperatur(this);
    rauchmelder_status = rauchmelder_->get_rauchmelder_zustand();
    
    qDebug()<<"Fenstersicherung checken";
    fenstersicherung_->check_PIR(this);
    fenstersicherung_status = fenstersicherung_->get_fenster_zustand();

    qDebug()<<"Authentifizierung checken";
    auth_->check_passwort_fuer_alarm(this);

    qDebug() << "------------------All sensors have been checked----------------------";

    emit objectsUpdated();
}

void alarm::add_message(std::string msg)
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

void alarm::remove_message(std::string msg)
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

bool alarm::is_message_empty()
{
    if (messages_.empty())
        return true;
    else
        return false;
}

void alarm::an()
{
    alarm_status = true;
    qDebug()<<"Alarm On";
}

void alarm::clear_messages()
{
    messages_.clear();
}

void alarm::aus()
{
    alarm_status = false;
    if (this->is_message_empty())
        qDebug() << "Alarm Off";
}

bool alarm::get_fenstersicherung_status()
{
    return fenstersicherung_status;
}

bool alarm::get_rauchmelder_status()
{
    return rauchmelder_status;
}

std::vector<std::string> alarm::get_message()
{
    return messages_;
}

bool alarm::get_alarm_status()
{
    return alarm_status;
}

alarm::~alarm()
{
    SAFE_DELETE(wasserflut_);
    SAFE_DELETE(rauchmelder_);
    SAFE_DELETE(fenstersicherung_);
    auth_->delete_instance();
}
