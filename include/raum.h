#pragma once

#include "gluehbirne.h"
#include "singleton.h"

#include <iostream>
#include <string.h>
#include <vector>
#include <QString>

#define NUMBER_OF_ROOMS 5

class raum : public Singleton<raum>
{
    private:
    std::vector<std::pair<QString, gluehbirne *>> raueme_licht;
    //Gluehbrine für alle Zimmer
    gluehbirne *badezimmer_licht;
    gluehbirne *schlafzimmer_licht;
    gluehbirne *wohnzimmer_licht;
    gluehbirne *keller_licht;
    gluehbirne *kueche_licht;

    public:
    raum();
    std::vector<std::pair<QString, gluehbirne *>> get_rauemelicht_vector() { return raueme_licht; }
    void set_raum_licht(gluehbirne *a,QString raum_name);
    gluehbirne* get_licht_zimmer(QString raum_name); 
    ~raum();
};
