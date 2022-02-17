#include "test_gluehbirne.h"
#include "macros.h"

test_gluehbirne::test_gluehbirne() : QObject(nullptr) {}

void test_gluehbirne::init()
{
    try {
        glu_ = new gluehbirne();
    }  catch (ParameterExcept_gl &p) {
        QFAIL("Failed to create instances");
    }
}

void test_gluehbirne::cleanup()
{
    SAFE_DELETE(glu_);
}

void test_gluehbirne::test_checkout_helligkeit()
{
    ///////////////////////////////////////
    glu_->set_helligkeit(helligkeit_1);
    QVERIFY( glu_->get_helligkeit() == 1 );

    ///////////////////////////////////////
    glu_->set_helligkeit(helligkeit_high);
    QVERIFY( glu_->get_helligkeit() == 3 );

    ///////////////////////////////////////
    glu_->set_helligkeit(helligkeit_low);
    QVERIFY( glu_->get_helligkeit() == 1 );
}
