#pragma once

#include "alarm.h"

#include <QDialog>
#include <iostream>
#include <string.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {class alarm_window;}
QT_END_NAMESPACE

class alarm_window : public QDialog
{   
    Q_OBJECT
    
    alarm *alarm_;

    public:
    explicit alarm_window(QWidget *parent = nullptr);
    void update_gui_messages();
    virtual ~alarm_window();

    private:
    Ui::alarm_window *ui;

    public slots:
    void update_gui_alarm();
};
