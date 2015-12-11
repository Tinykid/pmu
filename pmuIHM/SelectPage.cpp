#include "SelectPage.h"


SelectPage::SelectPage(int width, int height) : QWidget()
{
    this->width = width;
    this->height = height;
    this->initialVirtal();
    this->constructIHM();
    this->setConnections();
}

//!----------------------------------------------------------------------------
//!
//! \brief initialVirtal
//!
void SelectPage::initialVirtal(){


}

//!----------------------------------------------------------------------------
//!
//! \brief constructIHM
//!
void SelectPage::constructIHM(){

    this->titleBar = new QWidget();
    this->titleBar->setFixedSize(width, height*0.05);
    this->titleBar->setStyleSheet("background-color:#00BFFF");

    this->areaOneLabel = new QLabel();
    this->areaOneLabel->setFixedSize(width*0.12,height*0.05);

    this->areaTwoLabel = new QLabel();
    this->areaTwoLabel->setFixedSize(width*0.12,height*0.05);

    this->nameLabel = new QLabel("精 選");
    this->nameLabel->setAlignment(Qt::AlignCenter);

    this->nameLabel->setFont(QFont("Segoe UI",17,QFont::Normal,false));
    this->nameLabel->setFixedHeight(height*0.05);
    this->nameLabel->setStyleSheet("background-color:transparent;color:aliceblue");

    this->shoppingCartButton = new QPushButton();
    this->shoppingCartButton->setFixedSize(width*0.12, height*0.048);
    this->shoppingCartButton->setIcon(QIcon(":/images/shoppingCart.png"));
    this->shoppingCartButton->setIconSize(QSize(width*0.12, height*0.045));
    this->shoppingCartButton->setStyleSheet("QPushButton{background-color:transparent; color:AliceBlue; border: 0px;}"
                                            "QPushButton:focus{padding: -2;}");
    this->scanCodeButton = new QPushButton();
    this->scanCodeButton->setFixedSize(width*0.12,height*0.048);
    this->scanCodeButton->setIcon(QIcon(":/images/scanning.png"));
    this->scanCodeButton->setIconSize(QSize(width*0.12, height*0.045));
    this->scanCodeButton->setStyleSheet("QPushButton{background-color:transparent; color:AliceBlue; border: 0px;}"
                                        "QPushButton:focus{padding: -2;}");

    this->titleBarLayout = new QHBoxLayout(this->titleBar);
    this->titleBarLayout->addWidget(areaOneLabel);
    this->titleBarLayout->addWidget(areaTwoLabel);
    this->titleBarLayout->addWidget(nameLabel);
    this->titleBarLayout->addWidget(shoppingCartButton);
    this->titleBarLayout->addWidget(scanCodeButton);
    this->titleBarLayout->setMargin(0);
    this->titleBarLayout->setSpacing(0);

    this->OptrionBarWidget = new QWidget();
    this->OptrionBarWidget->setFixedSize(width, height*0.07);
    this->OptrionBarWidget->setStyleSheet("background-color:gray");

    this->selectListWidget = new QListWidget();
    this->selectListWidget->setFixedSize(width, height*0.88);
    this->selectListWidget->setStyleSheet("background-color:red");


    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->addWidget(titleBar);
    this->mainLayout->addWidget(OptrionBarWidget);
    this->mainLayout->addWidget(selectListWidget);
    this->mainLayout->setMargin(0);
    this->mainLayout->setSpacing(0);
}

//!----------------------------------------------------------------------------
//!
//! \brief setConnections
//!
void SelectPage::setConnections(){

}
