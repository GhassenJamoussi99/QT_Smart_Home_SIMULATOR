#pragma once

#include <iostream>
#include <string>

#include "authentifizierung.h"
#include "singleton.h"

using namespace std;

class ParaException{};

enum Zustand
{
 offen = 0,
 geschlossen,
 verschlossen
};

class haustuer : public Singleton<haustuer>
{
   Zustand tuer;

public:
   haustuer();
   Zustand getTuer();
   void setState(Zustand tuer);
   ~haustuer(){}
};
