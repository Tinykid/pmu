#ifndef CLABEL_H
#define CLABEL_H

#include <QLabel>

class CLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent*event);

public slots:
};

#endif // CLABEL_H
