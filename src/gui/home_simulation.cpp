#include "home_simulation.h"
#include "ui_home_simulation.h"

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QEvent>
#include <QResizeEvent>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>

#include "view.h"
#include "led.h"
#include "alarm.h"
#include "gluehbirne.h"
#include "raum.h"
#include "fenstersicherung.h"
#include "rauchmelder.h"
#include "authentifizierung.h"
#include "wasserflut.h"
#include "macros.h"

QGraphicsScene *scene_ = nullptr;
QGraphicsPixmapItem *wohnzimmer_licht_an = nullptr;
QGraphicsPixmapItem *schlafzimmer_licht_an = nullptr;
QGraphicsPixmapItem *kueche_licht_an = nullptr;
QGraphicsPixmapItem *keller_licht_an = nullptr;
QGraphicsPixmapItem *badezimmer_licht_an = nullptr;
QGraphicsPixmapItem *alarm_state = nullptr;
QGraphicsPixmapItem *led_state = nullptr;
QGraphicsPixmapItem *pirsensor_state = nullptr;
QGraphicsPixmapItem *tempratursensor_state = nullptr;
QGraphicsPixmapItem *wasserstand_state = nullptr;

authentifizierung *authentifizierung_;

bool alarm_status = 0; //For better code security
vector<pair<string,bool>> sensors_states = { {"fenstersicherung",false} , {"rauchmelder",false} }; //For better code security

using namespace std;

home_simulation::home_simulation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::home_simulation)
{
    qDebug() << "Home constructor" << this;

    //Initialization
    ui->setupUi(this);
    this->setWindowTitle("Home simulator");

    //Instantiate objects
    scene_ = new QGraphicsScene();
    authentifizierung_ = authentifizierung::get_instance();
    alarm_ = alarm::get_instance();
    wasserstand_ = wasserstandssensor::get_instance();
    led_ = led::get_instance();

    //create home and update it for the first time
    this->create_home();
    this->update_home(nullptr);
}

void home_simulation::create_home()
{
    qDebug() << this;
    //For managing a large number of 2D graphical items
    scene_->setSceneRect(-628,-283,1062,623);
    this->setFixedSize(1062,623);

    v = new view(this);
    v->setScene(scene_);

    //das Haus gestalten
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::black);

    QGraphicsTextItem *room1 = scene_->addText("Badezimmer");
    room1->setPos(-420,0);

    QGraphicsTextItem *room2 = scene_->addText("Küche");
    room2->setPos(-420,200);

    QGraphicsTextItem *room3 = scene_->addText("Schlafzimmer");
    room3->setPos(200, 0);

    QGraphicsTextItem *room4 = scene_->addText("Keller");
    room4->setPos(200, 200);

    QGraphicsTextItem *room5 = scene_->addText("Wohnzimmer");
    room5->setPos(-100,37);

    QGraphicsRectItem *rectItem1 = new QGraphicsRectItem();
    rectItem1->setRect(-484,-174,800,400);
    rectItem1->setPen(mPen);

    QGraphicsRectItem *rectItem2 = new QGraphicsRectItem(); //Upper Left Corner room - Badezimmer
    rectItem2->setRect(-484,-174,200,200);
    rectItem2->setPen(mPen);

    QGraphicsRectItem *rectItem3 = new QGraphicsRectItem(); //Bottom Left Corner room - Kueche
    rectItem3->setRect(-484,26,200,200);
    rectItem3->setPen(mPen);

    QGraphicsRectItem *rectItem4 = new QGraphicsRectItem(); //Upper Right Corner room - Schlafzimmer
    rectItem4->setRect(116,-174,200,200);
    rectItem4->setPen(mPen);

    QGraphicsRectItem *rectItem5 = new QGraphicsRectItem(); //Bottom Right Corner room - Keller
    rectItem5->setRect(116,26,200,200);
    rectItem5->setPen(mPen);

    scene_->addItem(rectItem1);
    scene_->addItem(rectItem2);
    scene_->addItem(rectItem3);
    scene_->addItem(rectItem4);
    scene_->addItem(rectItem5);

    ///////////////////////////////////Komponente hinzufügen///////////////////////////////////////////////

    //Alarm
    QPixmap Pix(":/imgs/smart devices/alarm.png");
    QGraphicsPixmapItem *alarm = scene_->addPixmap(Pix.scaled(40, 40, Qt::IgnoreAspectRatio));
    alarm->setPos(-91,-138);

    //LED
    QPixmap LED(":/imgs/smart devices/doorbell_aus.png");
    QGraphicsPixmapItem *led = scene_->addPixmap(LED.scaled(60, 60, Qt::IgnoreAspectRatio));
    led->setPos(-185,195);

    //Toilette
    QPixmap Pix1(":/imgs/smart devices/toilet.png");
    QGraphicsPixmapItem *toilet = scene_->addPixmap(Pix1.scaled(40, 40, Qt::IgnoreAspectRatio));
    toilet->setPos(-480,-111);

    //Fenster
    QPixmap Fen(":/imgs/smart devices/fenster.png");
    QGraphicsPixmapItem *fenster = scene_->addPixmap(Fen.scaled(50, 50, Qt::IgnoreAspectRatio));
    fenster->setPos(-196,-219);

    //Badezimmer
    QPixmap badezimmer(":/imgs/smart devices/00_helligkeit.png");
    QGraphicsPixmapItem *bade_licht = scene_->addPixmap(badezimmer.scaled(40, 40, Qt::IgnoreAspectRatio));
    bade_licht->setPos(-382,-139);

    //Keller
    QPixmap keller(":/imgs/smart devices/00_helligkeit.png");
    QGraphicsPixmapItem *keller_licht = scene_->addPixmap(keller.scaled(40, 40, Qt::IgnoreAspectRatio));
    keller_licht->setPos(218,69);

    //Kueche
    QPixmap kueche(":/imgs/smart devices/00_helligkeit.png");
    QGraphicsPixmapItem *kueche_licht = scene_->addPixmap(kueche.scaled(40, 40, Qt::IgnoreAspectRatio));
    kueche_licht->setPos(-394,51);

    //Wohnzimmer
    QPixmap wohnzimmer(":/imgs/smart devices/00_helligkeit.png");
    QGraphicsPixmapItem *wohnzimmer_licht = scene_->addPixmap(wohnzimmer.scaled(40, 40, Qt::IgnoreAspectRatio));
    wohnzimmer_licht->setPos(-71,-6);

    //Schlafzimmer
    QPixmap schlafzimmer(":/imgs/smart devices/00_helligkeit.png");
    QGraphicsPixmapItem *schlafzimmer_licht = scene_->addPixmap(schlafzimmer.scaled(40, 40, Qt::IgnoreAspectRatio));
    schlafzimmer_licht->setPos(213,-141);

    //Wasserstandssensor
    QPixmap wasserstand(":/imgs/smart devices/wasserstandssensor.png");
    QGraphicsPixmapItem *wasserstand_sensor = scene_->addPixmap(wasserstand.scaled(80, 70, Qt::IgnoreAspectRatio));
    wasserstand_sensor->setPos(34,140);

    // Rauchmelder
    QPixmap tempsensor(":/imgs/smart devices/rauchmelder_aus.png");
    QGraphicsPixmapItem *temp_sensor = scene_->addPixmap(tempsensor.scaled(40, 40, Qt::IgnoreAspectRatio));
    temp_sensor->setPos(9,-141);

    // Fenstersicherung
    QPixmap pirsensor(":/imgs/smart devices/pir_sensor_aus.png");
    QGraphicsPixmapItem *pir_sensor = scene_->addPixmap(pirsensor.scaled(40, 40, Qt::IgnoreAspectRatio));
    pir_sensor->setPos(-188,-225);
}


void home_simulation::update_home(raum *room)
{
    ///////////////////////////////////Lichter steuern///////////////////////////////////////////////

    if (room)
    {
        std::vector<std::pair<QString, gluehbirne *>> r_lichter = room->get_rauemelicht_vector();
        QString second;

        qDebug() <<this->metaObject()->className()<< ":Testing the vector";
        for (int i = 0; i<NUMBER_OF_ROOMS; i++)
        {
              const QString first = r_lichter[i].first;
              if(r_lichter[i].second)
                  second = QString::number(r_lichter[i].second->get_licht());
              else
                  second = "not set";
              qDebug() << first << " " << second;
        }

        qDebug() <<this->metaObject()->className()<< ":GUI ...";

        for (int i = 0; i<NUMBER_OF_ROOMS; i++)
            {
              if(r_lichter[i].first == "Wohnzimmer" && r_lichter[i].second)
               {
                  if (r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==1) //Falls Wohnzimmer an
                  {
                     remove_gui_object(&wohnzimmer_licht_an);
                     qDebug() <<this->metaObject()->className()<< ": Wohnzimmer Helligkeit bzw licht ist 1 ";
                     QPixmap a(":/imgs/smart devices/11_helligkeit.png");
                     wohnzimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                     wohnzimmer_licht_an->setPos(-71,-6);
                  }
                  else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==2)
                   {
                     remove_gui_object(&wohnzimmer_licht_an);
                     qDebug() <<this->metaObject()->className()<< ": Wohnzimmer Helligkeit bzw licht ist 2 ";
                     QPixmap a(":/imgs/smart devices/22_helligkeit.png");
                     wohnzimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                     wohnzimmer_licht_an->setPos(-71,-6);
                   }
                   else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==3)
                   {
                     remove_gui_object(&wohnzimmer_licht_an);
                     qDebug() <<this->metaObject()->className()<< ": Wohnzimmer Helligkeit bzw licht ist 3 ";
                     QPixmap a(":/imgs/smart devices/33_helligkeit.png");
                     wohnzimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                     wohnzimmer_licht_an->setPos(-71,-6);
                   }
                   else if (r_lichter[i].second->get_licht()==0)
                   {
                      qDebug() <<this->metaObject()->className()<< ": Wohnzimmer licht ist aus ";
                      remove_gui_object(&wohnzimmer_licht_an);
                   }
               }
              else if(r_lichter[i].first == "Badezimmer" && r_lichter[i].second)
              {
                  qDebug() << "gluehbirne defined";
                  if (r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==1)
                  {
                      remove_gui_object(&badezimmer_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Badezimmer helligkeit ist 1";
                      QPixmap a(":/imgs/smart devices/11_helligkeit.png");
                      badezimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      badezimmer_licht_an->setPos(-382,-139);
                   }
                   else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==2)
                    {
                      remove_gui_object(&badezimmer_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Badezimmer helligkeit ist 2";
                      QPixmap a(":/imgs/smart devices/22_helligkeit.png");
                      badezimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      badezimmer_licht_an->setPos(-382,-139);
                    }
                    else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==3)
                    {
                      remove_gui_object(&badezimmer_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Badezimmer helligkeit ist 3";
                      QPixmap a(":/imgs/smart devices/33_helligkeit.png");
                      badezimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      badezimmer_licht_an->setPos(-382,-139);
                    }
                    else if (r_lichter[i].second->get_licht()==0)
                    {
                       qDebug() <<this->metaObject()->className()<< ": Badezimmer licht ist aus ";
                       remove_gui_object(&badezimmer_licht_an);
                    }
              }
              else if(r_lichter[i].first == "Kueche" && r_lichter[i].second)
              {
                  qDebug() << "gluehbirne defined";
                  if (r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==1)
                    {
                      remove_gui_object(&kueche_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Kueche helligkeit ist 1";
                      QPixmap a(":/imgs/smart devices/11_helligkeit.png");
                      kueche_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      kueche_licht_an->setPos(-394,51);
                    }
                   else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==2)
                    {
                      remove_gui_object(&kueche_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Kueche helligkeit ist 2";
                      QPixmap a(":/imgs/smart devices/22_helligkeit.png");
                      kueche_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      kueche_licht_an->setPos(-394,51);
                    }
                    else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==3)
                    {
                      remove_gui_object(&kueche_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Kueche helligkeit ist 3";
                      QPixmap a(":/imgs/smart devices/33_helligkeit.png");
                      kueche_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      kueche_licht_an->setPos(-394,51);
                    }
                    else if (r_lichter[i].second->get_licht()==0)
                    {
                       qDebug() <<this->metaObject()->className()<< ": Kuecher licht ist aus ";
                       remove_gui_object(&kueche_licht_an);
                    }
              }
              else if(r_lichter[i].first == "Keller" && r_lichter[i].second)
              {
                  qDebug() << "gluehbirne defined";
                  if (r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==1)
                   {
                      remove_gui_object(&keller_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Keller helligkeit ist 1 ";
                      QPixmap a(":/imgs/smart devices/11_helligkeit.png");
                      keller_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      keller_licht_an->setPos(218,69);
                   }
                   else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==2)
                    {
                      remove_gui_object(&keller_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Keller helligkeit ist 2 ";
                      QPixmap a(":/imgs/smart devices/22_helligkeit.png");
                      keller_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      keller_licht_an->setPos(218,69);
                    }
                    else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==3)
                    {
                      remove_gui_object(&keller_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Keller helligkeit ist 3 ";
                      QPixmap a(":/imgs/smart devices/33_helligkeit.png");
                      keller_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      keller_licht_an->setPos(218,69);
                    }
                    else if (r_lichter[i].second->get_licht()==0)
                    {
                       qDebug() <<this->metaObject()->className()<< ": Keller licht ist aus ";
                       remove_gui_object(&keller_licht_an);
                    }
              }
              else if(r_lichter[i].first == "Schlafzimmer" && r_lichter[i].second)
              {
                  qDebug() << "gluehbirne defined";

                   if (r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==1)
                   {
                      remove_gui_object(&schlafzimmer_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Schlafzimmer helligkeit ist 1 ";
                      QPixmap a(":/imgs/smart devices/11_helligkeit.png");
                      schlafzimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      schlafzimmer_licht_an->setPos(213,-141);
                   }
                   else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==2)
                   {
                      remove_gui_object(&schlafzimmer_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Schlafzimmer helligkeit ist 2 ";
                      QPixmap a(":/imgs/smart devices/22_helligkeit.png");
                      schlafzimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      schlafzimmer_licht_an->setPos(213,-141);
                   }
                   else if(r_lichter[i].second->get_licht() && r_lichter[i].second->get_helligkeit()==3)
                   {
                      remove_gui_object(&schlafzimmer_licht_an);
                      qDebug() <<this->metaObject()->className()<< ": Schlafzimmer helligkeit ist 3 ";
                      QPixmap a(":/imgs/smart devices/33_helligkeit.png");
                      schlafzimmer_licht_an = scene_->addPixmap(a.scaled(40, 40, Qt::IgnoreAspectRatio));
                      schlafzimmer_licht_an->setPos(213,-141);
                   }
                   else if (r_lichter[i].second->get_licht()==0)
                   {
                      qDebug() <<this->metaObject()->className()<< ": Schlafzimmer licht ist aus ";
                      remove_gui_object(&schlafzimmer_licht_an);
                   }
              }
            }
    }

    ///////////////////////////////////Alarm System///////////////////////////////////////////////

    if (alarm_)
    {
        alarm_->update();

        if (1 == alarm_->get_alarm_status())
        {
            if (alarm_status == false)
            {
                QPixmap Pix1(":/imgs/smart devices/alarm_an.png");
                alarm_state = new QGraphicsPixmapItem();
                alarm_state = scene_->addPixmap(Pix1.scaled(40, 40, Qt::IgnoreAspectRatio));
                alarm_state->setPos(-91,-138);
                alarm_status = true;
            }
            // prüfe Fenstericherung status
           if (1 == alarm_->get_fenstersicherung_status())
           {
               if (!sensors_states[0].second)
               {
                   QPixmap Pix2(":/imgs/smart devices/pir_sensor_an.png");
                   pirsensor_state = new QGraphicsPixmapItem();
                   pirsensor_state = scene_->addPixmap(Pix2.scaled(40, 40, Qt::IgnoreAspectRatio));
                   pirsensor_state->setPos(-188,-225);
                   sensors_states[0].second = true;
               }
           }
           else {
               if (sensors_states[0].second)
               {
                   remove_gui_object(&pirsensor_state);
                   sensors_states[0].second = false;
               }
           }
           // prüfe Rauchmelder status
           if (1 == alarm_->get_rauchmelder_status())
           {
               if (!sensors_states[1].second)
               {
                   QPixmap Pix3(":/imgs/smart devices/rauchmelder_an.png");
                   tempratursensor_state = new QGraphicsPixmapItem();
                   tempratursensor_state = scene_->addPixmap(Pix3.scaled(40, 40, Qt::IgnoreAspectRatio));
                   tempratursensor_state->setPos(9,-141);
                   sensors_states[1].second = true;
               }
           }
           else
           {
               if (sensors_states[1].second)
               {
                   remove_gui_object(&tempratursensor_state);
                   sensors_states[1].second = false;
               }
           }
        }
        else
        {

            if ( true == sensors_states[1].second  )
            {
                remove_gui_object(&tempratursensor_state);
                sensors_states[1].second = false;
            }

            if ( true == sensors_states[0].second )
            {
                remove_gui_object(&pirsensor_state);
                sensors_states[0].second = false;
            }

            if (alarm_status)
            {
                remove_gui_object(&alarm_state);
                alarm_status = false;
            }
        }
    }

    if (led_){
        led_->update();

        if (led_->getGreen()==1){
            qDebug() <<" LED grün ";
            QPixmap LED(":/imgs/smart devices/doorbell_an.png");
            led_state = new QGraphicsPixmapItem();
            led_state = scene_->addPixmap(LED.scaled(60, 60, Qt::IgnoreAspectRatio));
            led_state->setPos(-185,195);
        }
        else{
            remove_gui_object(&led_state); //Standard state
        }
    }

    if (wasserstand_)
    {
       double wasserstand_value_ = wasserstand_->get_sensor_value();

       if (wasserstand_value_ == 0)
       {
           remove_gui_object(&wasserstand_state);
       }

       else if (wasserstand_value_ < WASSERSTAND_THRESHOLD)
       {
           remove_gui_object(&wasserstand_state);
           QPixmap wasserstand_unt(":/imgs/smart devices/wasserstandssensor _UNDER_T.png");
           wasserstand_state = new QGraphicsPixmapItem();
           wasserstand_state = scene_->addPixmap(wasserstand_unt.scaled(80, 70, Qt::IgnoreAspectRatio));
           wasserstand_state->setPos(34,140);

       }
       else if (wasserstand_value_ == WASSERSTAND_THRESHOLD)
       {
           remove_gui_object(&wasserstand_state);
           QPixmap wasserstand_t(":/imgs/smart devices/wasserstandssensor _T.png");
           wasserstand_state = new QGraphicsPixmapItem();
           wasserstand_state = scene_->addPixmap(wasserstand_t.scaled(80, 70, Qt::IgnoreAspectRatio));
           wasserstand_state->setPos(34,140);

       }
       else if (wasserstand_value_ <= 2*WASSERSTAND_THRESHOLD && wasserstand_value_>WASSERSTAND_THRESHOLD)
       {
           remove_gui_object(&wasserstand_state);
           QPixmap wasserstand_un2t_ovt(":/imgs/smart devices/wasserstandssensor_OVER_T_UNDER_2T.png");
           wasserstand_state = new QGraphicsPixmapItem();
           wasserstand_state = scene_->addPixmap(wasserstand_un2t_ovt.scaled(80, 70, Qt::IgnoreAspectRatio));
           wasserstand_state->setPos(34,140);

       }
       else if (wasserstand_value_ > 2*WASSERSTAND_THRESHOLD)
       {
           remove_gui_object(&wasserstand_state);
           QPixmap wasserstand_ov2t(":/imgs/smart devices/wasserstandssensor _OVER_2T.png");
           wasserstand_state = new QGraphicsPixmapItem();
           wasserstand_state = scene_->addPixmap(wasserstand_ov2t.scaled(80, 70, Qt::IgnoreAspectRatio));
           wasserstand_state->setPos(34,140);

       }
    }
}

void home_simulation::remove_gui_object(QGraphicsPixmapItem **obj)
{
    if (*obj)
    {
        scene_->removeItem(*obj);

        //Falls removeItem obj nicht geloscht hat
        if (*obj)
        {
            delete *obj;             //reicht nicht mit QGraphicsPixmapItem aus
        }

        *obj = nullptr;
    }
}

home_simulation::~home_simulation()
{
    SAFE_DELETE(ui);
    SAFE_DELETE(v);
    SAFE_DELETE(scene_);

    authentifizierung_->delete_instance();
    alarm_->delete_instance();
    wasserstand_->delete_instance();
    led_->delete_instance();

    authentifizierung_ = 0;
    alarm_ = 0;
    wasserstand_ = 0;
    led_ = 0;
}

/*
void home_simulation::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Widget resized , old size : " << event->oldSize(); //When resizing prints this message
        qDebug() << " new size : " << event->size();
}
*/
