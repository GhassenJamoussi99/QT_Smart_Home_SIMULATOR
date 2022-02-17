#include "test_alarm_integration.h"

test_alarm_integration::test_alarm_integration() : QObject(nullptr) {}

void test_alarm_integration::init()
{
    try
    {
        cut_alarm = alarm::get_instance();
        cut_authentifizierung = authentifizierung::get_instance();
        cut_wasserstandssensor = wasserstandssensor::get_instance();
        cut_temperatursensor = temperatursensor::get_instance();
        cut_pirsensor = pir_sensor::get_instance();
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("Cannot create instances");
    }
}

void test_alarm_integration::cleanup()
{
    cut_alarm->delete_instance();
    cut_authentifizierung->delete_instance();
    cut_wasserstandssensor->delete_instance();
    cut_temperatursensor->delete_instance();
    cut_pirsensor->delete_instance();

    cut_alarm = 0;
    cut_wasserstandssensor = 0;
    cut_temperatursensor = 0;
    cut_pirsensor = 0;
    cut_authentifizierung = 0;
}

void test_alarm_integration::test_update()
{
    //---------------init----------------------------
    cut_alarm->clear_messages();

    std::vector<std::string> messages_;
    std::vector<std::string> messages_test_;

    //-----------Testing sucess scenario-------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_gueltig);
        cut_temperatursensor->set_sensor_value(temperatur_gueltig);
        cut_pirsensor->set_sensor_value(pirsensor_gueltig);
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 0);
    QVERIFY(messages_ == messages_test_);

    //----------------Testing password--------------

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_gueltig);
        cut_temperatursensor->set_sensor_value(temperatur_gueltig);
        cut_pirsensor->set_sensor_value(pirsensor_gueltig);
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_ungueltig);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
        messages_test_.push_back("Achtung! Passwort dreimal falsch eingegeben!");
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == true);
    QVERIFY(messages_ == messages_test_);

    //----------Testing password tryouts-------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_gueltig);
        cut_temperatursensor->set_sensor_value(temperatur_gueltig);
        cut_pirsensor->set_sensor_value(pirsensor_gueltig);
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_ungueltig);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 0);
    QVERIFY(messages_ == messages_test_);

    //--------------Testing PIR Sensor----------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_gueltig);
        cut_temperatursensor->set_sensor_value(temperatur_gueltig);
        cut_pirsensor->set_sensor_value(pirsensor_ungueltig);
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
        messages_test_.push_back("Achtung! EINBRECHER !");
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 1);
    QVERIFY(messages_ == messages_test_);

    //--------------Testing Rauchmelder Sensor----------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_gueltig);
        cut_temperatursensor->set_sensor_value(temperatur_ungueltig);
        cut_pirsensor->set_sensor_value(pirsensor_gueltig);
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
        messages_test_.push_back("Achtung! Temperatur zu hoch");
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 1);
    QVERIFY(messages_ == messages_test_);

    //--------------Testing Wasserstandssensor ----------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_ungueltig);
        cut_temperatursensor->set_sensor_value(temperatur_gueltig);
        cut_pirsensor->set_sensor_value(pirsensor_gueltig);
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
        messages_test_.push_back("Achtung! Wasserstand zu hoch");
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 1);
    QVERIFY(messages_ == messages_test_);

    //--------------Testing 3 sensors ----------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_ungueltig);
        cut_temperatursensor->set_sensor_value(temperatur_ungueltig);
        cut_pirsensor->set_sensor_value(pirsensor_ungueltig);
        cut_authentifizierung->setPasswort(passwort_gueltig);
        cut_authentifizierung->setTryouts(tryouts_gueltig_0);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
        messages_test_.push_back("Achtung! Wasserstand zu hoch");
        messages_test_.push_back("Achtung! Temperatur zu hoch");
        messages_test_.push_back("Achtung! EINBRECHER !");
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 1);
    QVERIFY(messages_ == messages_test_);

    //--------------Testing 4 sensors ----------------

    cut_alarm->clear_messages();

    messages_.clear();
    messages_test_.clear();

    try
    {
        cut_wasserstandssensor->set_sensor_value(wasserstand_ungueltig);
        cut_temperatursensor->set_sensor_value(temperatur_ungueltig);
        cut_pirsensor->set_sensor_value(pirsensor_ungueltig);
        cut_authentifizierung->setPasswort(passwort_ungueltig);
        cut_authentifizierung->setTryouts(tryouts_ungueltig);
        cut_authentifizierung->login_password();
        cut_alarm->update();
        messages_ = cut_alarm->get_message();
        messages_test_.push_back("Achtung! Wasserstand zu hoch");
        messages_test_.push_back("Achtung! Temperatur zu hoch");
        messages_test_.push_back("Achtung! EINBRECHER !");
        messages_test_.push_back("Achtung! Passwort dreimal falsch eingegeben!");
    }
    catch (ParameterExceptionAL &pe)
    {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_alarm->get_alarm_status() == 1);
    QVERIFY(messages_ == messages_test_);

    qDebug() << "Finished testcases";
}
