#include "test_switcher_integration.h"
#include "macros.h"

test_switcher_integration::test_switcher_integration() : QObject(nullptr) {}

void test_switcher_integration::init()
{
    try {
        cut_switcher = new switcher();
    }  catch (ParameterExceptionSW &pe) {
        QFAIL("Failed to create instances");
    }
}

void test_switcher_integration::cleanup()
{
    SAFE_DELETE(cut_switcher);
    cut_gluehbirne = nullptr;
}

void test_switcher_integration::test_integration_switcher()
{
     //Zimmer gueltig
     cut_switcher->set_zimmer_name(zimmer_gueltig);
     cut_switcher->setup_licht_an();
     cut_switcher->setup_helligkeit(helligkeit_1_gueltig);
     cut_gluehbirne = cut_switcher->get_zimmer_gluehbirne(zimmer_gueltig);

     QVERIFY(cut_gluehbirne->get_licht() == true );
     QVERIFY(cut_gluehbirne->get_helligkeit() == 1);
     qDebug() << "Testcase 1 done";

     //Zimmer ungueltig
     cut_switcher->set_zimmer_name(zimmer_ungueltig);
     cut_switcher->setup_licht_an();
     cut_switcher->setup_helligkeit(helligkeit_1_gueltig);
     cut_gluehbirne = cut_switcher->get_zimmer_gluehbirne(zimmer_ungueltig);

     QVERIFY(cut_gluehbirne == nullptr );
     qDebug() << "Testcase 2 done";

     //Helligkeit ungueltig < 1
     cut_switcher->set_zimmer_name(zimmer_gueltig);
     cut_switcher->setup_licht_an();
     cut_switcher->setup_helligkeit(helligkeit_ungueltig_low);
     cut_gluehbirne = cut_switcher->get_zimmer_gluehbirne(zimmer_gueltig);

     QVERIFY(cut_gluehbirne->get_licht() == true );
     QVERIFY(cut_gluehbirne->get_helligkeit() == 1);
     qDebug() << "Testcase 3 done";

     //Helligkeit ungueltig >3
     cut_switcher->set_zimmer_name(zimmer_gueltig);
     cut_switcher->setup_licht_an();
     cut_switcher->setup_helligkeit(helligkeit_ungueltig_high);
     cut_gluehbirne = cut_switcher->get_zimmer_gluehbirne(zimmer_gueltig);

     QVERIFY(cut_gluehbirne->get_licht() == true );
     QVERIFY(cut_gluehbirne->get_helligkeit() == 3);
     qDebug() << "Testcase 4 done";

     //Zimmer gueltig
     cut_switcher->set_zimmer_name(zimmer_gueltig);
     cut_switcher->setup_licht_an();
     cut_switcher->setup_helligkeit(helligkeit_1_gueltig);
     cut_switcher->reset_lights();
     cut_gluehbirne = cut_switcher->get_zimmer_gluehbirne(zimmer_gueltig);

     QVERIFY(cut_gluehbirne->get_licht() == false );
     QVERIFY(cut_gluehbirne->get_helligkeit() == 1);
     qDebug() << "Testcase 5 done";
}
