#pragma once

#include <iostream>
#include <vector>

class abstract_alarm
{
    public:
    virtual void remove_message(std::string msg) = 0;
    virtual void add_message(std::string msg) = 0;
    virtual std::vector<std::string> get_message() = 0;
    virtual bool get_alarm_status() = 0;
    virtual void update() = 0;
    virtual void an() = 0;
    virtual void aus() = 0;
    virtual void clear_messages() = 0;
    virtual bool is_message_empty() = 0;
    virtual bool get_fenstersicherung_status() = 0;
    virtual bool get_rauchmelder_status() = 0;
};
