#ifndef SELECTPAGE_H
#define SELECTPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>

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
    QWidget *OptrionBarWidget;
    QListWidget *selectListWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *titleBarLayout;
    QLabel *areaOneLabel;
    QLabel *areaTwoLabel;
    QLabel *nameLabel;
    QPushButton *shoppingCartButton;
    QPushButton *scanCodeButton;

signals:

public slots:
};

#endif // SELECTPAGE_H
