#include "switcher_window.h"
#include "ui_switcher_window.h"
#include "switcher.h"

#include <QGraphicsPixmapItem>
#include <iostream>
#include <string>
#include <QDebug>

#include "gluehbirne.h"
#include "raum.h"
#include "macros.h"

switcher_window::switcher_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::switcher_window)
{
    ui->setupUi(this);
    this->setFixedSize(380,200);
    ui->rooms_list->addItem("Wohnzimmer");
    ui->rooms_list->addItem("Schlafzimmer");
    ui->rooms_list->addItem("Badezimmer");
    ui->rooms_list->addItem("Keller");
    ui->rooms_list->addItem("Kueche");
    swit_ = new switcher();
    qDebug()<<"In Lichte (bzw switcher_window Dialog() )";
}

void switcher_window::on_On_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": On ";

    zimmer = ui->rooms_list->currentText();
    swit_->set_zimmer_name(zimmer);
    swit_->setup_licht_an();
    home_widget->update_home(raum::get_instance());
}

void switcher_window::on_Off_clicked()
{
    qDebug() <<this->metaObject()->className()<< ": Off ";

    zimmer = ui->rooms_list->currentText();
    swit_->set_zimmer_name(zimmer);
    swit_->setup_licht_aus();
    home_widget->update_home(raum::get_instance());
}

void switcher_window::on_horizontalSlider_valueChanged(int value)
{
    ui->lcdNumber->display(value);

    QString zimmer = ui->rooms_list->currentText();
    qDebug() << zimmer;
    swit_->set_zimmer_name(zimmer);
    swit_->setup_helligkeit(value);
    home_widget->update_home(raum::get_instance());

}

void switcher_window::on_rooms_list_currentTextChanged(QString room_name)
{
    qDebug() << "Room changed";
    licht = swit_->get_zimmer_gluehbirne(room_name);
    ui->horizontalSlider->setSliderPosition(licht->get_helligkeit());
}

void switcher_window::on_reset_clicked()
{
    swit_->reset_lights();
    licht = swit_->get_zimmer_gluehbirne(zimmer);
    ui->horizontalSlider->setSliderPosition(licht->get_helligkeit());
    home_widget->update_home(raum::get_instance());
}

switcher_window::~switcher_window()
{
    SAFE_DELETE(ui);
    SAFE_DELETE(swit_);
}
