#include "PmuTitleBar.h"

PmuTitleBar::PmuTitleBar(int width, int height, QString titleName) : QWidget()
{
    this->width = width;
    this->height = height;
    this->titleName = titleName;
    this->constructIHM();
}

//!---------------------------------------------------------------------------------------------
//!
//! \brief PmuTitleBar::constructIHM
//!
void PmuTitleBar::constructIHM(){
    this->returnButton = new QPushButton();
    this->returnButton->setIcon(QIcon(":/images/return.png"));
    this->returnButton->setIconSize(QSize(0.12*width,0.06*height));
    this->returnButton->setFixedWidth(0.12*width);
    this->returnButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue}"
                                      "QPushButton:focus{padding: -2;}");

    this->titleLabel = new QLabel(titleName);
    this->titleLabel->setFont(QFont("Segoe UI",18,QFont::Normal,false));
    this->titleLabel->setAlignment(Qt::AlignVCenter);
    this->titleLabel->setStyleSheet("border: 0px ;border-radius: 0px;padding: 22px;background-color: transparent; color: AliceBlue");

    this->setFixedSize(width, height*0.07);
    this->titleBarLayout = new QHBoxLayout(this);
    this->titleBarLayout->addWidget(returnButton);
    this->titleBarLayout->addWidget(titleLabel);
    this->titleBarLayout->setMargin(0);
    this->titleBarLayout->setSpacing(0);
}
