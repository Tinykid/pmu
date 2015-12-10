#include "MyRssCourse.h"

MyRssCourse::MyRssCourse(int width, int height): QWidget()
{
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

void MyRssCourse::initVariable(){
    this->titleBarWidget = new PmuTitleBar(width, height, "我訂閱的課程");
}


//!-----------------------------------------------------------------------------------------
//!
//! \brief MyRssCourse::constructIHM
//!
void MyRssCourse::constructIHM(){

    this->myRssCourseWidget = new QListWidget();

    this->myRssCoursePageLayout = new QVBoxLayout(this);
    this->myRssCoursePageLayout->addWidget(titleBarWidget);
    this->myRssCoursePageLayout->addWidget(myRssCourseWidget);
    this->myRssCoursePageLayout->setMargin(0);
    this->myRssCoursePageLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyRssCourse::setConnections
//!
void MyRssCourse::setConnections(){
    this->connect(this->titleBarWidget->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
