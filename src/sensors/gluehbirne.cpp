#include "gluehbirne.h"
#include <QDebug>

gluehbirne::gluehbirne()
{
    licht = false;
    helligkeit = 1;
}

void gluehbirne::an()
{
    qDebug()<< "Licht an";
    licht = true;
}

void gluehbirne::aus()
{
    qDebug()<< "Licht aus";
    licht = false;
}

void gluehbirne::set_licht(bool li)
{
   licht = li;
}
bool gluehbirne::get_licht()
{
    return licht;  
}

void gluehbirne::set_helligkeit(int m_helligkeit)
{
    if(m_helligkeit >= 3 )
    {
        helligkeit= 3 ;
    }
    else if(m_helligkeit <= 0)
    {
        helligkeit= 1;
    }
    else
    {
        helligkeit= m_helligkeit;
    }

    qDebug() << "helligkeit = " << helligkeit;
}

int gluehbirne::get_helligkeit()
{
    return helligkeit;
}


