#pragma once
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class about; }
QT_END_NAMESPACE

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = nullptr);
    ~about();

private:
    Ui::about *ui;
};

