#include "raum.h"
#include <QDebug>
#include "macros.h"

raum::raum()
{
    //Init vector
    badezimmer_licht = new gluehbirne();
    schlafzimmer_licht = new gluehbirne();
    wohnzimmer_licht = new gluehbirne();
    keller_licht = new gluehbirne();
    kueche_licht = new gluehbirne();

    raueme_licht.push_back(std::make_pair("Badezimmer",badezimmer_licht));
    raueme_licht.push_back(std::make_pair("Schlafzimmer",schlafzimmer_licht));
    raueme_licht.push_back(std::make_pair("Wohnzimmer",wohnzimmer_licht));
    raueme_licht.push_back(std::make_pair("Keller",keller_licht));
    raueme_licht.push_back(std::make_pair("Kueche",kueche_licht));
}

gluehbirne* raum::get_licht_zimmer(QString raum_name)
{
    for (int i = 0; i<NUMBER_OF_ROOMS; i++)
    {
      if(raueme_licht[i].first == raum_name)
      {
          return raueme_licht[i].second;
      }
    }

    return nullptr;
}

void raum::set_raum_licht(gluehbirne *a,QString raum_name)
{
    for (int i = 0; i<NUMBER_OF_ROOMS; i++)
    {
      if(raueme_licht[i].first == raum_name)
          raueme_licht[i].second = a;
    }
}

raum::~raum()
{
    SAFE_DELETE(badezimmer_licht);
    SAFE_DELETE(schlafzimmer_licht);
    SAFE_DELETE(wohnzimmer_licht);
    SAFE_DELETE(keller_licht);
    SAFE_DELETE(kueche_licht);
}
