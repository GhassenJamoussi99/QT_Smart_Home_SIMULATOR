#pragma once
#include "authentifizierung.h"
#include "authentifizierung_window.h"
#include "switcher.h"
#include "alarm.h"
#include "alarm_window.h"
#include "switcher_window.h"
#include "home_simulation.h"
#include "einstellungen.h"
#include "about.h"

#include <QMainWindow>

//extern home_simulation *home_widget;

QT_BEGIN_NAMESPACE
namespace Ui { class app; }
QT_END_NAMESPACE

class app : public QMainWindow
{   
     Q_OBJECT

     private:
     Ui::app *ui;
     switcher_window *lichter_dialog;
     alarm_window *alarm_dialog;
     authentifizierung_window *auth_dialog;
     einstellungen *einstellung_dialog;
     about *about_dialog;


     private slots:
     void on_lichter_steuern_clicked();
     void on_alarm_status_clicked();
     void on_einstellungen_clicked();
     void on_passwort_clicked();
     void on_home_clicked();
     void on_about_clicked();

     public:
     app(QWidget *parent  = nullptr);
     ~app();

    /* For GUI Debugging
    protected:
    void resizeEvent(QResizeEvent *event) override;
    */
};


