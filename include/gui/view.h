#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class view : public QGraphicsView
{
    Q_OBJECT
public:
    explicit view(QWidget *parent = nullptr);

signals:

public slots:

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // VIEW_H
