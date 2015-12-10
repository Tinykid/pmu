#ifndef PMUTITLEBAR_H
#define PMUTITLEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class PmuTitleBar : public QWidget
{
    Q_OBJECT
public:
    PmuTitleBar(int width, int height, QString titleName);

    void constructIHM();
    QPushButton *returnButton;
private:
    int width;
    int height;
    QString titleName;

    QHBoxLayout *titleBarLayout;

    QWidget *titleBarWidget;
    QLabel *titleLabel;

signals:

public slots:
};

#endif // PMUTITLEBAR_H
