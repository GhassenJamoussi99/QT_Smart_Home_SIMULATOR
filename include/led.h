#pragma once

#include <iostream>
#include <string>

#include "authentifizierung.h"
#include "home_simulation.h"
#include "singleton.h"
#include "ui_authentifizierung_window.h"

using namespace std;
class ParameterExcept {};


class authentifizierung;

class led : public Singleton<led>
{
private:
   bool redLED = 0 ;
   bool greenLED = 0;
   authentifizierung *auth_;

public:
   led();
   void setRed(bool state);
   void setGreen(bool state);
   void update();
   bool getRed();
   bool getGreen();
   ~led();
};

