#include "alarm_window.h"
#include "ui_alarm_window.h"

#include <QDebug>

#include "macros.h"

QString off_state = "Aus";
QString on_state = "An";

alarm_window::alarm_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarm_window)
{
    qDebug()<<"alarm_window Constructor";
    alarm_ = alarm::get_instance();
    ui->setupUi(this);
    ui->alarm_status->setText(off_state);
    this->setFixedSize(519,415);

    connect(alarm::get_instance(), SIGNAL(objectsUpdated()), this, SLOT(update_gui_alarm()));
}

void alarm_window::update_gui_alarm()
{
    qDebug() << "Updating gui window for alarm status...";
    std::vector<std::string> messages_ = alarm_->get_message();

    if(alarm_->get_alarm_status())
        ui->alarm_status->setText(on_state);
    else
        ui->alarm_status->setText(off_state);

    if (!messages_.empty())
    {
        ui->textBrowser->clear();
        qDebug()<<"Vector messages not empty";
        qDebug()<<"Messages vector:";
        qDebug()<<"---------------------------------------------\n\n";
        for (size_t i =0;i<messages_.size();i++)
        {
            ui->textBrowser->append(QString::fromStdString(messages_[i]));
            qDebug() << QString::fromStdString(messages_[i]);
        }

        qDebug()<<"---------------------------------------------\n\n";
    }
    else
    {
       ui->textBrowser->clear();
    }
}

alarm_window::~alarm_window()
{
   SAFE_DELETE(ui);
   alarm_->delete_instance();
}
