#pragma once

#include "home_simulation.h"

#include <QDialog>
#include <QGraphicsScene>
#include <memory>


class ParameterExceptionSW{};

class raum;
class home_simulation;
extern home_simulation *home_widget;
class gluehbirne;

namespace Ui {
class switcher;
}

class switcher : public QObject
{
    Q_OBJECT

private:
    Ui::switcher *ui;
    gluehbirne *licht_;
    QString zimmer_;
    int value_;

public:
    void setup_licht_an();
    void setup_licht_aus();
    void setup_helligkeit(int value);
    gluehbirne* get_zimmer_gluehbirne(QString room_name);
    void set_zimmer_name(QString m_zimmer);
    void reset_lights();
    QString get_zimmer_name();

public:
    switcher();
    virtual ~switcher();
};
