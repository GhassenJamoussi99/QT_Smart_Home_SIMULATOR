#pragma once

#include "abstract_alarm.h"

#include <iostream>
#include <string.h>
#include <vector>

#include "singleton.h"

class ParameterException {}; //For testing purposes

class alarm_mockup : public abstract_alarm, public Singleton<alarm_mockup>
{   
    public:
    alarm_mockup();
    void remove_message(std::string msg);
    void add_message(std::string msg);
    std::vector<std::string> get_message();
    bool get_alarm_status();
    void an();
    void aus();
    void update();
    void clear_messages();
    bool is_message_empty();
    bool get_fenstersicherung_status();
    bool get_rauchmelder_status();
    virtual ~alarm_mockup(){};

    private:
    std::vector<std::string> messages_; 
    bool alarm_status = false;
    bool fenstersicherung_status;
    bool rauchmelder_status;
};
