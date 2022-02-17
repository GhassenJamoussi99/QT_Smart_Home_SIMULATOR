#include "test_system.h"

test_system::test_system() : QObject(nullptr) {}

void test_system::init()
{
    try
    {
    cut_alarm = alarm::get_instance();
    cut_wasserstandssensor = wasserstandssensor::get_instance();
    cut_temperatursensor = temperatursensor::get_instance();
    cut_pirsensor = pir_sensor::get_instance();
    cut_authentifizierung = authentifizierung::get_instance();
    cut_haustuer = haustuer::get_instance();
    cut_led = led::get_instance();
    cut_switch = new switcher();
    } catch (ParameterExceptionAL & pe) {
    QFAIL("Cannot create instances");
    }
}

void test_system::cleanup()
{
    cut_alarm->delete_instance();
    cut_wasserstandssensor->delete_instance();
    cut_temperatursensor->delete_instance();
    cut_pirsensor->delete_instance();
    cut_authentifizierung->delete_instance();
    cut_haustuer->delete_instance();
    cut_led->delete_instance();
    SAFE_DELETE(cut_switch);

    cut_alarm = 0;
    cut_wasserstandssensor = 0;
    cut_temperatursensor = 0;
    cut_pirsensor = 0;
    cut_authentifizierung = 0;
    cut_haustuer = 0;
    cut_led = 0;
    cut_gluehbirne = 0;
}


void test_system::test_update()
{
    //----------------Erfolgsszenario testen--------------//

    //init
    std::vector<std::string> messages_;
    std::vector<std::string> messages_test_;
    cut_alarm->clear_messages();

    //Passwort eingeben
    cut_authentifizierung->setPasswort(passwort_gueltig);
    cut_authentifizierung->setTryouts(tryouts_gueltig);
    cut_authentifizierung->login_password();

    //Alle Lichter von den Räumen testen
    cut_switch->set_zimmer_name(zimmer_1_gueltig);
    cut_switch->setup_licht_an();
    cut_switch->setup_helligkeit(helligkeit_3_gueltig);
    cut_gluehbirne = cut_switch->get_zimmer_gluehbirne(zimmer_1_gueltig);

    QVERIFY( cut_gluehbirne->get_licht() == true );
    QVERIFY( cut_gluehbirne->get_helligkeit() == 3 );

    cut_switch->set_zimmer_name(zimmer_2_gueltig);
    cut_switch->setup_licht_an();
    cut_switch->setup_helligkeit(helligkeit_1_gueltig);
    cut_gluehbirne = cut_switch->get_zimmer_gluehbirne(zimmer_2_gueltig);

    QVERIFY( cut_gluehbirne->get_licht() == true );
    QVERIFY( cut_gluehbirne->get_helligkeit() == 1 );

    cut_switch->set_zimmer_name(zimmer_3_gueltig);
    cut_switch->setup_licht_aus();
    cut_switch->setup_helligkeit(helligkeit_2_gueltig);
    cut_gluehbirne = cut_switch->get_zimmer_gluehbirne(zimmer_3_gueltig);

    QVERIFY( cut_gluehbirne->get_licht() == false );
    QVERIFY( cut_gluehbirne->get_helligkeit() == 2 );

    cut_switch->set_zimmer_name(zimmer_4_gueltig);
    cut_switch->setup_licht_an();
    cut_switch->setup_helligkeit(helligkeit_1_gueltig);
    cut_gluehbirne = cut_switch->get_zimmer_gluehbirne(zimmer_4_gueltig);

    QVERIFY( cut_gluehbirne->get_licht() == true );
    QVERIFY( cut_gluehbirne->get_helligkeit() == 1 );

    cut_switch->set_zimmer_name(zimmer_5_gueltig);
    cut_switch->setup_licht_an();
    cut_switch->setup_helligkeit(helligkeit_3_gueltig);
    cut_gluehbirne = cut_switch->get_zimmer_gluehbirne(zimmer_5_gueltig);

    QVERIFY( cut_gluehbirne->get_licht() == true );
    QVERIFY( cut_gluehbirne->get_helligkeit() == 3 );

    cut_switch->set_zimmer_name(zimmer_5_gueltig);
    cut_switch->setup_licht_an();
    cut_switch->setup_helligkeit(helligkeit_3_gueltig);
    cut_switch->reset_lights();
    cut_gluehbirne = cut_switch->get_zimmer_gluehbirne(zimmer_5_gueltig);

    QVERIFY( cut_gluehbirne->get_licht() == false );
    QVERIFY( cut_gluehbirne->get_helligkeit() == 1 );

    //Sensoren testen
    cut_pirsensor->set_sensor_value(pir_sensor_triggered);
    cut_wasserstandssensor->set_sensor_value(wasserstand_sensor_triggered);
    cut_temperatursensor->set_sensor_value(temperatur_sensor_triggered);

    //cut updaten
    cut_alarm->update();
    cut_led->update();

    //Nachrichten testen
    messages_ = cut_alarm->get_message();
    messages_test_.push_back("Achtung! Wasserstand zu hoch");
    messages_test_.push_back("Achtung! Temperatur zu hoch");
    messages_test_.push_back("Achtung! EINBRECHER !");

    //Tuer Zustaende checken
    QVERIFY(cut_haustuer->getTuer() == offen);
    QVERIFY(cut_led->getGreen() == true);
    QVERIFY(cut_led->getRed() == false);

    //Alarmstatus checken
    QVERIFY( cut_alarm->get_alarm_status() == true);
    QVERIFY( messages_ == messages_test_);
}
