#include "home_simulation.h"
#include "switcher.h"

#include <QPushButton>
#include <QLineEdit>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {class switcher_window;}
QT_END_NAMESPACE

class home_simulation;
extern home_simulation *home_widget;

class switcher_window: public QDialog
{
    Q_OBJECT
	
	private:
    Ui::switcher_window *ui;
    switcher *swit_;
    QString zimmer;
    gluehbirne *licht;
	
public slots:
    void on_On_clicked();
    void on_Off_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_rooms_list_currentTextChanged(QString room_name);	
    void on_reset_clicked();
	
public:
    explicit switcher_window(QWidget *parent = nullptr);
    virtual ~switcher_window();
};
