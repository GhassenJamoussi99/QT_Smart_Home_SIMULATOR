#include "test_gluehbirne_raum.h"
#include "macros.h"


test_gluehbirne_raum::test_gluehbirne_raum() : QObject(nullptr) {}

void test_gluehbirne_raum::init()
{
    try {
       ra_ = raum::get_instance();
    }  catch (ParameterExceptionSW &pe) {
        QFAIL("Failed to create instances");
    }

}

void test_gluehbirne_raum::cleanup()
{
    ra_->delete_instance();

    cut_gluehbirne = 0;
    ra_ = 0;
}

void test_gluehbirne_raum::test_checkout_gluehbirne_raum()
{
     ///////////////////////////////////////////////////////
     cut_gluehbirne = ra_->get_licht_zimmer(zimmer_gueltig);
     cut_gluehbirne->aus();
     cut_gluehbirne->set_helligkeit(helligkeit_1_gueltig);
     ra_->set_raum_licht(cut_gluehbirne,zimmer_gueltig);


     QVERIFY(ra_->get_licht_zimmer(zimmer_gueltig)->get_licht() == false );
     QVERIFY(ra_->get_licht_zimmer(zimmer_gueltig)->get_helligkeit()==1);
     qDebug() << "Testcase 1 done";

     ///////////////////////////////////////////////////////

     cut_gluehbirne = ra_->get_licht_zimmer(zimmer_gueltig);
     cut_gluehbirne->aus();
     cut_gluehbirne->set_helligkeit(helligkeit_ungueltig_low);
     ra_->set_raum_licht(cut_gluehbirne,zimmer_gueltig);


     QVERIFY(ra_->get_licht_zimmer(zimmer_gueltig)->get_licht() == false );
     QVERIFY(ra_->get_licht_zimmer(zimmer_gueltig)->get_helligkeit()==1);
     qDebug() << "Testcase 2 done";

     ///////////////////////////////////////////////////////

     cut_gluehbirne = ra_->get_licht_zimmer(zimmer_ungueltig);

     QVERIFY(cut_gluehbirne == nullptr );
     qDebug() << "Testcase 3 done";

     ///////////////////////////////////////////////////////

     cut_gluehbirne = ra_->get_licht_zimmer(zimmer_gueltig);
     cut_gluehbirne->aus();
     cut_gluehbirne->set_helligkeit(helligkeit_ungueltig_high);
     ra_->set_raum_licht(cut_gluehbirne,zimmer_gueltig);

     QVERIFY(ra_->get_licht_zimmer(zimmer_gueltig)->get_licht() == false );
     QVERIFY(ra_->get_licht_zimmer(zimmer_gueltig)->get_helligkeit()==3);
     qDebug() << "Testcase 4 done";
}
