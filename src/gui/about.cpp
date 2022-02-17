#include "about.h"
#include "ui_about.h"

#include "macros.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

about::~about()
{
    SAFE_DELETE(ui);
}
