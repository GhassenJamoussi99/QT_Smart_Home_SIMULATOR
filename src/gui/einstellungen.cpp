#include "einstellungen.h"
#include "ui_einstellungen.h"

#include <QDebug>

#include "macros.h"

einstellungen::einstellungen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::einstellungen)
{
    ui->setupUi(this);
    qDebug()<<"Einstellungen Konstruktor..." << this << "...";

    ws_ = wasserstandssensor::get_instance();
    pir_= pir_sensor::get_instance();
    temp_= temperatursensor::get_instance();

    ui->wasser_spinbox->setValue(ws_->get_sensor_value());
    ui->pir_spinbox->setValue(pir_->get_sensor_value());
    ui->temp_spinbox->setValue(temp_->get_sensor_value());
}

void einstellungen::on_apply_button_clicked()
{
    ws_->set_sensor_value(ui->wasser_spinbox->value());
    pir_->set_sensor_value(ui->pir_spinbox->value());
    temp_->set_sensor_value(ui->temp_spinbox->value());

    home_widget->update_home(nullptr);
}

einstellungen::~einstellungen()
{
    SAFE_DELETE(ui);
    ws_->delete_instance();
    pir_->delete_instance();
    temp_->delete_instance();

    ws_ = 0;
    pir_ = 0;
    temp_ = 0;
}
