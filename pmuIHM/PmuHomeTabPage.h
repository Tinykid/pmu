#ifndef PMUHOMETABPAGE_H
#define PMUHOMETABPAGE_H

#include <QWidget>
#include <QFont>
#include <QTabWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include "PmuMainPage.h"
#include "MyOwnPage.h"
#include "PmuNeighborPage.h"
#include "SelectPage.h"

class PmuHomeTabPage : public QTabWidget
{
    Q_OBJECT
public:
    PmuHomeTabPage(int width, int height, QFont *caracterStyle);
    void initVariable();
    void constructIHM();
    void setConnections();
    void drawBackground();
private:
    int width;
    int height;
    SelectPage *selectPage;

    QPixmap* pixmap;
    QFont *caracterStyle;

    PmuMainPage *pmumainPage;
    PmuNeighborPage *neighborPage;
    MyOwnPage *myOwnPage;

signals:

public slots:
    void optionClicked(int index);

};

#endif // PMUHOMETABPAGE_H
