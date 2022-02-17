#include "authentifizierung_window.h"
#include "ui_authentifizierung_window.h"

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QDebug>
#include <QDialog>

#include "alarm.h"
#include "led.h"
#include "raum.h"
#include "macros.h"

authentifizierung_window::authentifizierung_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentifizierung_window)
{
    qDebug()<<"Im Auth_window Konstruktor...";
    ui->setupUi(this);
    auth_ = authentifizierung::get_instance();
    connect(auth_, SIGNAL(objectsUpdatedauth()), this, SLOT(auth_pushButton_update()));
}

void authentifizierung_window::auth_pushButton_update()
{
    if (SECURE_PASSWORD == auth_->getPasswort()) {
        QMessageBox::information(this, "Login", "Erfolgreich angemeldet\n"
                                                "Tür ist offen\n"
                                                "Willkommen!\n");
        ui->pushButton_Login->hide();
    }
    else
    {
        //Wenn das Passwot dreimal falsch eingegeben wurde, dann setzte block=1
        QMessageBox::warning(this,"Login", "Passwort ist nicht korrekt\n"
                                           "Tür ist geschlossen\n");
        if (auth_->getTryouts() >= 3)
        {
            QMessageBox::warning(this,"Login", "Passwort 3mal falsch eingegeben\n"
                                               "Tür bleibt geschlossen und wird verschlossen");
            qDebug()<<"Passwort wird 3 mal falsch eingegeben";
            ui->pushButton_Login->hide();
        }
     }

    home_widget->update_home(raum::get_instance());
}

void authentifizierung_window::on_pushButton_Login_clicked()
{
    QString passwort = ui->lineEdit_passwort->text();
    auth_->setPasswort(passwort.toStdString());
    auth_->login_password();
}

authentifizierung_window::~authentifizierung_window()
{
    SAFE_DELETE(ui);

    auth_->delete_instance();
    auth_ = 0;
}

