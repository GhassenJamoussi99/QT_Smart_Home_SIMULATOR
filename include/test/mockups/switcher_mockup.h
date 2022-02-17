#pragma once
#include <QDialog>

#include"abstract_switcher.h"
class ParameterException {}; //For testing purposes

class switcher_mockup: public abstract_switcher
{
private:
	
public :
switcher_mockup(QWidget *parent);
void on_On_clicked();
void on_Off_clicked();
void on_horizontalSlider_valueChanged(int value);
void on_rooms_list_currentTextChanged(QString room_name);
switcher_mockup();
};
