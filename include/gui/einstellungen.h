#pragma once
#include "home_simulation.h"
#include "wasserstandssensor.h"
#include "pir_sensor.h"
#include "temperatursensor.h"

#include <QDialog>

extern home_simulation *home_widget;

QT_BEGIN_NAMESPACE
namespace Ui {class einstellungen;}
QT_END_NAMESPACE

class einstellungen : public QDialog
{
  Q_OBJECT
  
  private slots:
    void on_apply_button_clicked();

  private:
  Ui::einstellungen *ui;
  wasserstandssensor *ws_;
  pir_sensor *pir_;
  temperatursensor *temp_;


  public:
  einstellungen(QWidget *parent = nullptr);
  virtual ~einstellungen();
};


