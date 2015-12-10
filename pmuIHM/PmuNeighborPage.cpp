#include "PmuNeighborPage.h"

PmuNeighborPage::PmuNeighborPage(int width,int height) : QWidget(){
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    this->setConnections();

}

//!----------------------------------------------------------------------------
//!
//! \brief PmuNeighborPage::initVariable
//!
void PmuNeighborPage::initVariable(){
    this->setStyleSheet("background-color:aliceblue)");

}

//!----------------------------------------------------------------------------
//!
//! \brief PmuNeighborPage::constructIHM
//!
void PmuNeighborPage::constructIHM(){
//    this->returnButton = new QPushButton();
//    this->returnButton->setIcon(QIcon(":/images/homePage.png"));
//    this->returnButton->setIconSize(QSize(width*0.1, height*0.08));
//    this->returnButton->setFixedSize(width*0.1, height*0.08);
//    this->returnButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue; Alignment:AlignVCenter}"
//                                      "QPushButton:focus{padding: -2;}");

    this->titleLabel = new QLabel("附近");
    this->titleLabel->setFixedWidth(width*0.7);
    this->titleLabel->setFont(QFont("Segoe UI",18,QFont::Normal,false));
    this->titleLabel->setAlignment(Qt::AlignCenter);
    this->titleLabel->setStyleSheet("border: 0px ;border-radius: 0px;padding: 22px;background-color: transparent; color: #363636");

    this->titleBar = new QWidget();
    this->titleBar->setFixedSize(width,height*0.08);
    this->titleBar->setStyleSheet("border:0px; border-bottom:1px solid aliceblue");

    this->shoppingCartButton = new QPushButton();

    this->searchButton = new QPushButton();

    this->titleLayout = new QHBoxLayout(titleBar);
//    this->titleLayout->addWidget(returnButton);
    this->titleLayout->addWidget(titleLabel);  
    this->titleLayout->addWidget(shoppingCartButton);
    this->titleLayout->addWidget(searchButton);
    this->titleLayout->setMargin(0);
    this->titleLayout->setSpacing(5);

    Button1=new QPushButton();
    Button1->setFixedSize(width,height*0.06);
    this->optionBar = new QWidget();
    this->optionBar->setFixedHeight(height*0.06);
    this->optionBar->setStyleSheet("border: 0px ;border-radius: 0px;padding: 22px;background-color: transparent; color: AliceBlue");

    this->optionLayout =new QHBoxLayout(optionBar);
    this->optionLayout->addWidget(Button1);
    this->optionLayout->setMargin(0);
    this->optionLayout->setSpacing(0);
    this->neighborCourse = new QListWidget();

    this->pageLayout =new QVBoxLayout(this);
    this->pageLayout->addWidget(titleBar);
    this->pageLayout->addWidget(optionBar);
    this->pageLayout->addWidget(neighborCourse);
    this->pageLayout->setMargin(0);
    this->pageLayout->setSpacing(0);
}

//!----------------------------------------------------------------------------
//!
//! \brief PmuNeighborPage::setConnections
//!
void PmuNeighborPage::setConnections(){
    this->connect(this->returnButton, SIGNAL(clicked()), this, SLOT(remove()));
}
