#ifndef HOME_SIMULATION_H
#define HOME_SIMULATION_H

#include "view.h"
#include "switcher.h"
#include "alarm.h"
#include "wasserstandssensor.h"

#include <QWidget>


extern QGraphicsScene *scene_;

class gluehbirne;
class raum;
class alarm;
class authentifizierung;
class led;

QT_BEGIN_NAMESPACE
namespace Ui { class home_simulation; }
QT_END_NAMESPACE

class home_simulation : public QWidget
{
     Q_OBJECT

     private:
     Ui::home_simulation *ui;
     alarm *alarm_;
     led *led_;
     wasserstandssensor *wasserstand_;
     view *v;

     public:
     explicit home_simulation(QWidget *parent  = nullptr);
     void create_home();
     void update_home(raum *room = nullptr);
     void remove_gui_object(QGraphicsPixmapItem **obj);
     ~home_simulation();

     //protected:
     //void resizeEvent(QResizeEvent *event) override; For GUI debugging 
};

#endif // HOME_SIMULATION_H
