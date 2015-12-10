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
    this->titleBar->setFixedSize(width, height*0.08);
    this->titleBar->setStyleSheet("background-color:yellow");

    this->selectMainWidget = new QWidget();
    this->selectMainWidget->setStyleSheet("background-color:green");

    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->addWidget(titleBar);
    this->mainLayout->addWidget(selectMainWidget);

}

//!----------------------------------------------------------------------------
//!
//! \brief setConnections
//!
void SelectPage::setConnections(){

}
