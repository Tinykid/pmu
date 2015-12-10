#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QScreen>
#include <QFont>
#include <QDialog>
#include <QToolButton>
#include "MyRssCourse.h"
#include "MySchedulePage.h"
#include "CLabel.h"

class MyOwnPage : public QWidget
{
    Q_OBJECT

public:
    MyOwnPage(int width, int height);
    ~MyOwnPage();

    void initial();
    void constructIHM();
    void setConnections();
    void createDialog();
private:
    MyRssCourse *myRssCourse;
    MySchedulePage *mySchedulePage;

    CLabel* idAvatarCLabel;
    QLabel* idAccountLabel;
    QLabel* idEmailLabel;

    QWidget* idWidget;
    QWidget* courseInfoWidget;
    QWidget* myPublishedWidget;
    QWidget* myRssWidget;
    QWidget* myScheduleWidget;
    QWidget* historyWidget;

    QToolButton* myPublishedButton;
    QToolButton* myRssButton;
    QToolButton* myScheduleButton;
    QToolButton* historyButton;

    QVBoxLayout* mainLayout;
    QVBoxLayout* idLayout;
    QVBoxLayout* myPublishedLayout;
    QVBoxLayout* myRssLayout;
    QVBoxLayout* myScheduleLayout;
    QVBoxLayout* historyLayout;
    QVBoxLayout* fBLayout;
    QGridLayout* coursesLayout;
    QVBoxLayout *optionDialogLayout;

    QDialog *optionDialog;
    CLabel *selectFromCamera;
    CLabel *selectFromPhotos;

    QFont *characterStyle;
    QString toolButtonStyle;
    int width;
    int height;
    QScreen* screen;

private slots:
    void modifierPersonnelImage();

};

#endif // PERSONALINFORMATION_H
