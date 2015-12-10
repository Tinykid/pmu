#ifndef PMUNEIGHBORPAGE_H
#define PMUNEIGHBORPAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>

class PmuNeighborPage : public QWidget
{
    Q_OBJECT
public:
    PmuNeighborPage(int width,int height);
    void initVariable();
    void constructIHM();
    void setConnections();

    QPushButton *returnButton;
private:
    QWidget *titleBar;
    QWidget *optionBar;
    QListWidget *neighborCourse;

    QPushButton *Button1;
    QLabel *titleLabel;

    QPushButton *shoppingCartButton;
    QPushButton *searchButton;
    QVBoxLayout *pageLayout;
    QHBoxLayout *optionLayout;
    QHBoxLayout *titleLayout;

    int width;
    int height;
signals:

public slots:
};

#endif // PMUNEIGHBORPAGE_H
