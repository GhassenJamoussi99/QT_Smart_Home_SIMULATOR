#include "app.h"
#include "ui_app.h"

#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QPalette>
#include <QPixmap>
#include <string.h>

#include "home_simulation.h"
#include "raum.h"
#include "macros.h"

home_simulation *home_widget;

app::app(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::app)
{
    qDebug() << "App constructor";
    ui->setupUi(this);

    //Set background for the app
    QPixmap bkgnd(":/imgs/bg2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    home_widget = new home_simulation();

    //Set fixed size
    this->setFixedSize(750,600);
    this->setWindowTitle("App");

    //initialize the buttons
    lichter_dialog = new switcher_window();
    alarm_dialog = new alarm_window();
    auth_dialog = new authentifizierung_window();
    einstellung_dialog = new einstellungen();
    about_dialog = new about();
}

/*
void app::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized , old size : " << event->oldSize(); //When resizing prints this message
        qDebug() << " new size : " << event->size();
}
*/

void app::on_lichter_steuern_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Im Licht_steuern Fenster ";
    lichter_dialog->show();
}

void app::on_passwort_clicked()
{
    qDebug() <<this->metaObject()->className()<< " Passwort eingeben ";
    auth_dialog->show();
}

void app::on_alarm_status_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Im alarm_status Fenster ";
    alarm_dialog->show();
}

void app::on_einstellungen_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Im einstellungen Fenster ";
    einstellung_dialog->show();
}

void app::on_home_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Home Widget ";
    home_widget->show();
}

void app::on_about_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Im about Fenster ";
    about_dialog->show();
}

app::~app()
{
    SAFE_DELETE(lichter_dialog);
    SAFE_DELETE(alarm_dialog);
    SAFE_DELETE(auth_dialog);
    SAFE_DELETE(einstellung_dialog);
    SAFE_DELETE(about_dialog);
    SAFE_DELETE(ui);
}
