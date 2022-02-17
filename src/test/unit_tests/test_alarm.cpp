#include "test_alarm.h"
#include <vector>
#include <iostream>

// Dictates behaviors of classes
bool test_alarm::wasserflut_status = false;
bool test_alarm::rauchmelder_status = false;
bool test_alarm::fenstersicherung_status = false;
bool test_alarm::authentifizierung_status = false;

std::vector<std::string> messages_;

test_alarm::test_alarm() : QObject(nullptr) {}

void test_alarm::init()
{

    alarm_mockup al;
    cut_ = &al;
    cut_->clear_messages();
    QVERIFY(cut_->is_message_empty() == 1);
}

void test_alarm::cleanup()
{
    cut_ = 0;
}

void test_alarm::test_add_message()
{
    cut_->clear_messages();

    try {
        cut_->add_message(message_1);
        cut_->add_message(message_2);
        cut_->add_message(message_3);
    } catch (ParameterException & pe) {
        QFAIL("ParameterException thrown");
    }

    messages_ = cut_->get_message();

    qDebug() << "Printing test vector";
    for (unsigned i=0; i< messages_.size() ;i++)
    {
        qDebug() << QString::fromStdString(messages_[i]);
    }

    QVERIFY(messages_[0] == message_1 );
    QVERIFY(messages_[1] == message_2 );
    QVERIFY(messages_[2] == message_3 );
}

void test_alarm::test_remove_message()
{
    cut_->clear_messages();

    try {
        cut_->add_message(message_1);
        cut_->add_message(message_2);
        cut_->add_message(message_3);
        cut_->remove_message(message_2);
    } catch (ParameterException & pe) {
        QFAIL("ParameterException thrown");
    }

    messages_ = cut_->get_message();

    qDebug() << "Printing removed Vector";
    for (unsigned i=0; i< messages_.size() ;i++)
    {
        qDebug() << QString::fromStdString(messages_[i]);
    }

    QVERIFY(messages_[0] == message_1 );
    QVERIFY(messages_[1] == message_3 );
}

void test_alarm::test_remove_messages()
{
    cut_->clear_messages();

    try {
        cut_->add_message(message_1);
        cut_->add_message(message_2);
        cut_->add_message(message_3);
        cut_->remove_message(message_1);
        cut_->remove_message(message_2);
        cut_->remove_message(message_3);
    } catch (ParameterException & pe) {
        QFAIL("ParameterException thrown");
    }

    messages_ = cut_->get_message();

    qDebug() << "Printing removed Vector";
    for (unsigned i=0; i< messages_.size() ;i++)
    {
        qDebug() << QString::fromStdString(messages_[i]);
    }

    QVERIFY(cut_->is_message_empty() == 1);
}

void test_alarm::test_update()
{
    wasserflut_status = true;
    rauchmelder_status = true;
    fenstersicherung_status = true;
    authentifizierung_status = true;

    try {
        cut_->update();
    } catch (ParameterException & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_alarm_status() == true );
    qDebug() << "Done";

   /*-------------------------------------------*/
    wasserflut_status = false;
    rauchmelder_status = false;
    fenstersicherung_status = false;
    authentifizierung_status = false;

    try {
        cut_->update();
    } catch (ParameterException & pe) {
        QFAIL("ParameterException thrown");
    }

    QVERIFY(cut_->get_alarm_status() == false );
    qDebug() << "Done";

   /*-------------------------------------------*/
     wasserflut_status = false;
     rauchmelder_status = false;
     fenstersicherung_status = false;
     authentifizierung_status = true;

     try {
         cut_->update();
     } catch (ParameterException & pe) {
         QFAIL("ParameterException thrown");
     }

     QVERIFY(cut_->get_alarm_status() == true );
     qDebug() << "Done";
    /*-------------------------------------------*/
}


