#ifndef MYRSSCOURSE_H
#define MYRSSCOURSE_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include "PmuTitleBar.h"

class MyRssCourse: public QWidget
{
public:
    MyRssCourse(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnections();
private:
    PmuTitleBar *titleBarWidget;
    int width;
    int height;

    QVBoxLayout *myRssCoursePageLayout;
    QListWidget *myRssCourseWidget;
private slots:

};

#endif // MYRSSCOURSE_H
