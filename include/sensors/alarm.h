#pragma once

#include <iostream>
#include <string.h>
#include <vector>
#include <QDialog>

#include "wasserflut.h"
#include "authentifizierung.h"
#include "fenstersicherung.h"
#include "rauchmelder.h"
#include "abstract_alarm.h"
#include "singleton.h"

class ParameterExceptionAL {};

class wasserflut;
class fenstersicherung;
class rauchmelder;
class authentifizierung;
class led;


class alarm : public QObject, public abstract_alarm, public Singleton<alarm>
{   
    Q_OBJECT

    public:
    alarm();
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
    ~alarm();

    signals:
    void objectsUpdated();

    private:
    wasserflut *wasserflut_;
    fenstersicherung *fenstersicherung_;
    rauchmelder *rauchmelder_;
    authentifizierung *auth_;
    std::vector<std::string> messages_; 
    bool alarm_status = false;
    bool fenstersicherung_status;
    bool rauchmelder_status;
};
