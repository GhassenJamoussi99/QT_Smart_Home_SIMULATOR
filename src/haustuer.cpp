#include "haustuer.h"

#include <iostream>
#include <string>

#include "authentifizierung.h"

using namespace std;

haustuer::haustuer()
{
    tuer = geschlossen;
    qDebug() << "haustuer Konstrutor :" << this;
}

void haustuer::setState(Zustand tuer_){
  qDebug() << "Tuer_Zustand =" << tuer_;
  this->tuer = tuer_;
}

Zustand haustuer::getTuer()
{
   qDebug() << "Getting tuer Zustand" << this;
   return tuer;
}
