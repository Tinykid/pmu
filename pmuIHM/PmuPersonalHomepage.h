#ifndef PMUPERSONALHOMEPAGE_H
#define PMUPERSONALHOMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include "CLabel.h"
#include "PmuTitleBar.h"


class PmuPersonalHomepage : public QWidget
{
    Q_OBJECT
public:
    explicit PmuPersonalHomepage(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnections();
    void creatDialog();
private:
    int width;
    int height;
    PmuTitleBar *titleBarWidget;

    QVBoxLayout *personalHomepageLayout;
    QVBoxLayout *personalInfoLayout;

    QHBoxLayout *avatarLabelLayout;

    QWidget *somethingElth;

    CLabel *personalInofLabel;
    CLabel *avatarLabel;
    CLabel *avatarCenterLabel;
    CLabel *userNameLabel;

signals:

public slots:


};

#endif // PMUPERSONALHOMEPAGE_H
