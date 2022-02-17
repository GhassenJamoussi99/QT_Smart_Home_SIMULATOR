#pragma once

#include "ui_authentifizierung_window.h"
#include "authentifizierung.h"
#include "alarm.h"
#include "haustuer.h"
#include "led.h"
#include "home_simulation.h"

#include <iostream>
#include <string>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {class authentifizierung_window;}
QT_END_NAMESPACE

class home_simulation;
extern home_simulation *home_widget;


class authentifizierung_window: public QDialog
{
    Q_OBJECT

    authentifizierung *auth_;

    private:
       string passwort_= "not set";
       Ui::authentifizierung_window *ui;


    public slots:
       void auth_pushButton_update();
       void on_pushButton_Login_clicked();

    public:
       authentifizierung_window(QWidget *parent = nullptr);
       ~authentifizierung_window();
};
