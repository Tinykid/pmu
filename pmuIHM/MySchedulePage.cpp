#include "MySchedulePage.h"

MySchedulePage::MySchedulePage(int width, int height) : QWidget()
{
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MySchedulePage::initVariable
//!
void MySchedulePage::initVariable(){
    this->titleBarWidget = new PmuTitleBar(width, height, "我的課程表");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MySchedulePage::constructIHM
//!
void MySchedulePage::constructIHM(){

    this->searchLineEdit = new QLineEdit();
    this->searchLineEdit->setFixedSize(width*0.55, height*0.053);
    this->searchLineEdit->setPlaceholderText("輸入關鍵字");
    this->searchLineEdit->setStyleSheet("QLineEdit{color:AliceBlue; border: 0px solid Gray; border-radius: 0px; color:rgb(0, 0, 0); background-color: azure; padding:0} "
                                        "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 0px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");

    this->searchButton = new QPushButton();
    this->searchButton->setFixedSize(width*0.092,height*0.053);
    this->searchButton->setIconSize(QSize(width*0.092,height*0.053));
    this->searchButton->setStyleSheet("QPushButton{border-image: url(:/images/searchButton.png); background-color:AliceBlue;border: 0px;}"
                                      "QPushButton:pressed{border-image: url(:/images/searchButton1.png);background-color:AliceBlue;border: 0px;}"
                                      "QPushButton:focus{padding: -2;}");

    this->sortComboBox = new QComboBox();
    this->sortComboBox->setFixedSize(width*0.3, height*0.053);
    this->sortComboBox->insertItem(0,"按時間排序");
    this->sortComboBox->insertItem(1,"按老師排序");
    this->sortComboBox->insertItem(2,"按課程排序");
    this->sortComboBox->setStyleSheet( "QComboBox{color:gray;background-color:aliceblue;border:0px;border-radius:0px;padding:0px;}"
                                       //"QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                       "QComboBox::drop-down{width: 88px;border: 0px;border-color:trantransparent;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                       "QComboBox::down-arrow{image: url(:/images/down.png);}"
                                       "QComboBox::down-arrow{width:72; height:72}"
                                       "QComboBox::down-arrow:on { top: 1px;left: 1px;}");

    this->searchBarWidget = new QWidget();
    this->searchBarWidget->setFixedSize(width, height*0.07);
    this->searchBarLayout = new QHBoxLayout(searchBarWidget);
    this->searchBarLayout->addStretch();
    this->searchBarLayout->addWidget(searchLineEdit);
    this->searchBarLayout->addWidget(searchButton);
    this->searchBarLayout->addStretch();
    this->searchBarLayout->addWidget(sortComboBox);
    this->searchBarLayout->addStretch();
    this->searchBarLayout->setMargin(0);
    this->searchBarLayout->setSpacing(0);

    this->scheduleWidget = new QWidget();

    this->mySchedulePageLayout = new QVBoxLayout(this);
    this->mySchedulePageLayout->addWidget(titleBarWidget);
    this->mySchedulePageLayout->addWidget(searchBarWidget);
    this->mySchedulePageLayout->addWidget(scheduleWidget);
    this->mySchedulePageLayout->setMargin(0);
    this->mySchedulePageLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MySchedulePage::setConnections
//!
void MySchedulePage::setConnections(){
    this->connect(this->titleBarWidget->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
