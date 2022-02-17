#include "test_authentifizierung_integration.h"


test_authentifizierung_integration::test_authentifizierung_integration() : QObject(nullptr) {}

void test_authentifizierung_integration::init()
{
    cut_authentifizierung = authentifizierung::get_instance();
    cut_alarm = alarm::get_instance();
    cut_haustuer = haustuer::get_instance();
    cut_led = led::get_instance();
}

void test_authentifizierung_integration::cleanup()
{
    cut_authentifizierung->delete_instance();
    cut_alarm->delete_instance();
    cut_haustuer->delete_instance();
    cut_led->delete_instance();

    cut_authentifizierung = 0;
    cut_alarm = 0;
    cut_haustuer = 0;
    cut_led = 0;
}

void test_authentifizierung_integration::test_passwort_fuer_alarm()
{

    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_alarm->get_alarm_status() == false);
    QVERIFY( cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 1 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_1);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_alarm->get_alarm_status() == false);
    QVERIFY( cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 2 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_2);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_alarm->get_alarm_status() == false);
    QVERIFY( cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 3 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_alarm->get_alarm_status() == false);
    QVERIFY( cut_haustuer->getTuer() == geschlossen);
    qDebug() << "Testcase 4 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_1);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_alarm->get_alarm_status() == false);
    QVERIFY( cut_haustuer->getTuer() == geschlossen);
    qDebug() <<  "Testcase 5 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_2);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    //Tryouts will be 3(threshold) after entering a false password
    QVERIFY( cut_alarm->get_alarm_status() == true);
    QVERIFY( cut_haustuer->getTuer() == verschlossen);
    qDebug() <<  "Testcase 6 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_ungueltig);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_alarm(cut_alarm);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_alarm->get_alarm_status() == true);
    QVERIFY( cut_haustuer->getTuer() == verschlossen);
    qDebug() <<  "Testcase 7 Done";

}

void test_authentifizierung_integration::test_passwort_fuer_led()
{
    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }
    QVERIFY(cut_led->getGreen() == true);
    QVERIFY(cut_led->getRed() == false);
    QVERIFY(cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 1 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_1);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_led->getGreen() == true);
    QVERIFY(cut_led->getRed() == false);
    QVERIFY( cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 2 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_2);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_led->getGreen() == true);
    QVERIFY(cut_led->getRed() == false);
    QVERIFY( cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 3 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_led->getGreen() == true);
    QVERIFY(cut_led->getRed() == false);
    QVERIFY( cut_haustuer->getTuer() == offen);
    qDebug() << "Testcase 4 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_1);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_led->getGreen() == false);
    QVERIFY(cut_led->getRed() == true);
    QVERIFY( cut_haustuer->getTuer() == geschlossen);
    qDebug() <<  "Testcase 5 Done";

    ////////////////////////////////////////////

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_2);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_led->getGreen() == false);
    QVERIFY(cut_led->getRed() == true);
    QVERIFY( cut_haustuer->getTuer() == verschlossen);
    qDebug() <<  "Testcase 6 Done";

    ////////////////////////////////////////////

    cut_authentifizierung->setPasswort(passwort_ungueltig);
    cut_authentifizierung->setTryouts(tryouts_ungueltig);

    try {
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_ungueltig);
        cut_authentifizierung->login_password();
        cut_authentifizierung->check_passwort_fuer_led(cut_led);
    } catch (Parameter_Exception_auth & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_led->getGreen() == false);
    QVERIFY(cut_led->getRed() == true);
    QVERIFY( cut_haustuer->getTuer() == verschlossen);
    qDebug() <<  "Testcase 7 Done";
}
