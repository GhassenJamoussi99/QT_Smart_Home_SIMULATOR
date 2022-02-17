#include "test_authentifizierung.h"


test_authentifizierung::test_authentifizierung() : QObject(nullptr) {}

void test_authentifizierung::init()
{
    auth = new authentifizierung_mockup();
    cut_ = auth;
}

void test_authentifizierung::cleanup()
{
    delete auth;
    cut_ = 0;
}

void test_authentifizierung::test_passwort_fuer_alarm()
{
    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_gueltig);
        cut_->setTryouts(tryouts_gueltig_0);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == true);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() << "Testcase 1 Done";

    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_gueltig);
        cut_->setTryouts(tryouts_gueltig_1);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == true);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() << "Testcase 2 Done";

    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_gueltig);
        cut_->setTryouts(tryouts_gueltig_2);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }
    qDebug() <<  "test3";

    QVERIFY( cut_->get_auth_zustand().pass_state == true);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() << "Testcase 3 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_gueltig_0);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() << "Testcase 4 Done";

    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_gueltig_1);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() <<  "Testcase 5 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_gueltig_2);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    //Tryouts will be 3(threshold) after entering a false password
    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == true); 
    qDebug() <<  "Testcase 6 Done";

    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_ungueltig);
        cut_->login_password();
        cut_->check_passwort_fuer_alarm(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == true);
    qDebug() <<  "Testcase 7 Done";

}

void test_authentifizierung::test_passwort_fuer_led()
{
    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_gueltig);
        cut_->setTryouts(tryouts_gueltig_0);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == true);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() <<  "Testcase 1 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_gueltig);
        cut_->setTryouts(tryouts_gueltig_1);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == true);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() <<  "Testcase 2 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_gueltig);
        cut_->setTryouts(tryouts_gueltig_2);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }


    QVERIFY( cut_->get_auth_zustand().pass_state == true);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() <<  "Testcase 3 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_gueltig_0);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() <<  "Testcase 4 Done";

    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_gueltig_1);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == false);
    qDebug() <<  "Testcase 5 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_gueltig_2);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    //Tryouts will be 3(threshold) after entering a false password
    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == true); 
    qDebug() <<  "Testcase 6 Done";


    ////////////////////////////////////////////

    try {
        //setup
        cut_->clear_auth_states();
        cut_->setTryouts(0);
        //start
        cut_->setPasswort(passwort_ungueltig);
        cut_->setTryouts(tryouts_ungueltig);
        cut_->login_password();
        cut_->check_passwort_fuer_led(nullptr);
    } catch (Parameter_Exception & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY( cut_->get_auth_zustand().pass_state == false);
    QVERIFY( cut_->get_auth_zustand().tryouts_max == true);
    qDebug() <<  "Testcase 7 Done";

}
