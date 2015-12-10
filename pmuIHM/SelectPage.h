#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class SelectPage : public QWidget
{
    Q_OBJECT
public:
    explicit SelectPage(int width, int height);
    void initialVirtal();
    void constructIHM();
    void setConnections();

private:
    int width;
    int height;

    QWidget *titleBar;
    QWidget *selectMainWidget;
    QVBoxLayout *mainLayout;



signals:

public slots:
};

#endif // SELECTPAGE_H
