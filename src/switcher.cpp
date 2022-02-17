#include "switcher.h"

#include <iostream>
#include <string>
#include <QDebug>
#include <QString>

#include "gluehbirne.h"
#include "raum.h"
#include "macros.h"

switcher::switcher()
{
    qDebug()<<"In Lichte (bzw Switcher Dialog() )";
}

void switcher::setup_licht_an()
{
    if (!zimmer_.isEmpty())
    {
        qDebug() << "Zimmer = " << zimmer_;
        licht_ = raum::get_instance()->get_licht_zimmer(zimmer_);
        if (licht_)
        {
            licht_->an();
            raum::get_instance()->set_raum_licht(licht_,zimmer_);
        }
    }
}

void switcher::setup_licht_aus()
{
    if (!zimmer_.isEmpty())
    {
        qDebug() << "Zimmer = " << zimmer_;
        licht_ = raum::get_instance()->get_licht_zimmer(zimmer_);
        if (licht_)
        {
            licht_->aus();
            raum::get_instance()->set_raum_licht(licht_,zimmer_);
        }
    }
}

void switcher::setup_helligkeit(int value)
{    
    bool ok = false;
    
    if (!zimmer_.isEmpty())
    {
        QString raum_name = zimmer_;

        //Retrieve the same "licht" object from the room
        std::vector<std::pair<QString, gluehbirne *>> raueme_licht = raum::get_instance()->get_rauemelicht_vector();

        for (int i = 0; i<NUMBER_OF_ROOMS; i++)
        {
          if(raueme_licht[i].first == raum_name)
          {
              if(raueme_licht[i].second != nullptr)
              {
                  ok = true;
                  licht_ = raueme_licht[i].second;
                  break;
              }
          }
        }

        //Add helligkeit to the same object licht
        if (ok)
        {
            licht_->set_helligkeit(value);

            raum::get_instance()->set_raum_licht(licht_,zimmer_);
    
        }
    }
}

gluehbirne* switcher::get_zimmer_gluehbirne(QString room_name)
{
    //Retrieve the same "licht" object from the room
    std::vector<std::pair<QString, gluehbirne *>> raueme_licht = raum::get_instance()->get_rauemelicht_vector();

    for (int i = 0; i<NUMBER_OF_ROOMS; i++)
    {
      if(raueme_licht[i].first == room_name)
      {
         licht_ = raueme_licht[i].second;
         break;
      }
    }

    return licht_;
}

void switcher::set_zimmer_name(QString m_zimmer)
{
    zimmer_ = m_zimmer;
}

void switcher::reset_lights()
{
    std::vector<std::pair<QString, gluehbirne *>> raueme_licht = raum::get_instance()->get_rauemelicht_vector();

    for (int i = 0; i<NUMBER_OF_ROOMS; i++)
    {
      raueme_licht[i].second->aus();
      raueme_licht[i].second->set_helligkeit(1);
    }
}

QString switcher::get_zimmer_name()
{
    return zimmer_;
}

switcher::~switcher()
{
    licht_ = nullptr;
    raum::get_instance()->delete_instance();
}
