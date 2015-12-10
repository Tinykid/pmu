#include "MyOwnPage.h"

MyOwnPage::MyOwnPage(int width, int height)
    : QWidget()
{
    this->width = width;
    this->height = height;
    this->initial();
    this->constructIHM();
    this->setConnections();
}

MyOwnPage::~MyOwnPage(){}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::modifierPersonnelImage
//!
void MyOwnPage::modifierPersonnelImage(){
    this->createDialog();
    this->optionDialog->show();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::createDialog
//!
void MyOwnPage::createDialog(){
    this->selectFromCamera = new CLabel();
    this->selectFromCamera->setText("拍 照");
    this->selectFromCamera->setFont(QFont("Segoe UI",20,QFont::Normal,false));
    this->selectFromCamera->setAlignment(Qt::AlignCenter);
    this->selectFromCamera->setStyleSheet("color: aliceblue; border-bottom: 1px solid white");

    this->selectFromPhotos = new CLabel();
    this->selectFromPhotos->setText("從相冊選擇");
    this->selectFromPhotos->setFont(QFont("Segoe UI",20,QFont::Normal,false));
    this->selectFromPhotos->setAlignment(Qt::AlignCenter);
    this->selectFromPhotos->setStyleSheet("color: aliceblue; border-top: 1px solid white");

    this->optionDialog = new QDialog();
    this->optionDialog->setStyleSheet("background-color:#6495ED; color:AliceBlue; ");
    this->optionDialog->setAttribute(Qt::WA_ShowModal, true);
    this->optionDialog->setFixedSize(width*0.6, height*0.22);
    this->optionDialogLayout = new QVBoxLayout(optionDialog);
    this->optionDialogLayout->addWidget(selectFromCamera);
    this->optionDialogLayout->addWidget(selectFromPhotos);
    this->optionDialogLayout->setMargin(0);
    this->optionDialogLayout->setSpacing(0);

}


//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::initial
//!
void MyOwnPage::initial(){
    characterStyle = new QFont("Segoe UI" , 18, QFont::Normal, false);
    toolButtonStyle = "QToolButton{padding-top:" + QString::number(height*0.02) + ";padding-bottom:" + QString::number(height*0.02) + ";border:none;color:rgb(135,209,199);background-color:transparent;}";
    this->myRssCourse = new MyRssCourse(width, height);
    this->mySchedulePage = new MySchedulePage(width, height);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::constructIHM
//!
void MyOwnPage::constructIHM(){

    idAvatarCLabel = new CLabel();
    idAvatarCLabel->setAlignment(Qt::AlignCenter);
    idAvatarCLabel->setFixedSize(width*0.32,height*0.2);
    idAvatarCLabel->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px;border-image:url(:/images/avatar.png)");

    idAccountLabel = new QLabel("姓名");
    idAccountLabel->setFont(*characterStyle);
    idAccountLabel->setAlignment(Qt::AlignCenter);

    idEmailLabel = new QLabel("电子邮件地址");
    idEmailLabel->setFont(*characterStyle);
    idEmailLabel->setAlignment(Qt::AlignCenter);

    idWidget = new QWidget();
    idWidget->setFixedHeight(0.556*height);
    idWidget->setStyleSheet("background-color:#9999CC");
    idLayout = new QVBoxLayout(idWidget);
    idLayout->setAlignment(Qt::AlignCenter);
    idLayout->addWidget(idAvatarCLabel);
    idLayout->addWidget(idAccountLabel);
    idLayout->addWidget(idEmailLabel);

    myPublishedButton = new QToolButton(this);
    myPublishedButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    myPublishedButton->setIcon(QIcon(":/images/publishCourse.png"));
    myPublishedButton->setIconSize(QSize(0.25*width, 0.08*height));
    myPublishedButton->setText("我發布的課程");
    myPublishedButton->setStyleSheet(toolButtonStyle);
    myPublishedButton->setFixedSize(0.5*width, 0.192*height);

    myRssButton = new QToolButton(this);
    myRssButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    myRssButton->setIcon(QIcon(":/images/rss.png"));
    myRssButton->setIconSize(QSize(0.25*width, 0.08*height));
    myRssButton->setText("我訂閱的課程");
    myRssButton->setStyleSheet(toolButtonStyle);
    myRssButton->setFixedSize(0.5*width, 0.192*height);

    myScheduleButton = new QToolButton(this);
    myScheduleButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    myScheduleButton->setIcon(QIcon(":/images/schedule.png"));
    myScheduleButton->setIconSize(QSize(0.25*width, 0.08*height));
    myScheduleButton->setText("我的課程表");
    myScheduleButton->setStyleSheet(toolButtonStyle);
    myScheduleButton->setFixedSize(0.5*width, 0.192*height);

    historyButton = new QToolButton(this);
    historyButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    historyButton->setIcon(QIcon(":/images/history.png"));
    historyButton->setIconSize(QSize(0.25*width, 0.08*height));
    historyButton->setText("瀏覽歷史");
    historyButton->setStyleSheet(toolButtonStyle);

    historyButton->setFixedSize(0.5*width, 0.192*height);

    myPublishedWidget = new QWidget();
    myPublishedWidget->setStyleSheet("background-color:transparent;border-bottom:1px solid Gray;border-right:1px solid Gray");
    myPublishedLayout = new QVBoxLayout(myPublishedWidget);
    myPublishedLayout->setSpacing(0);
    myPublishedLayout->setMargin(0);
    myPublishedLayout->setAlignment(Qt::AlignCenter);
    myPublishedLayout->addWidget(myPublishedButton);

    myRssWidget = new QWidget();
    myRssWidget->setStyleSheet("background-color:transparent; border-bottom:1px solid Gray");
    myRssLayout = new QVBoxLayout(myRssWidget);
    myRssLayout->setSpacing(0);
    myRssLayout->setMargin(0);
    myRssLayout->addWidget(myRssButton);

    myScheduleWidget = new QWidget();
    myScheduleWidget->setStyleSheet("background-color:transparent; border-right:1px solid Gray");
    myScheduleLayout = new QVBoxLayout(myScheduleWidget);
    myScheduleLayout->setMargin(0);
    myScheduleLayout->setSpacing(0);
    myScheduleLayout->addWidget(myScheduleButton);

    historyWidget = new QWidget();
    historyWidget->setStyleSheet("background-color:transparent;");
    historyLayout = new QVBoxLayout(historyWidget);
    historyLayout->setMargin(0);
    historyLayout->setSpacing(0);
    historyLayout->addWidget(historyButton);

    courseInfoWidget = new QWidget();
    //courseInfoWidget->setStyleSheet("background-color:transparent");
    courseInfoWidget->setFixedHeight(0.384*height);
    coursesLayout =new QGridLayout(courseInfoWidget);
    coursesLayout->addWidget(myPublishedWidget,0,0);
    coursesLayout->addWidget(myRssWidget,0,1);
    coursesLayout->addWidget(myScheduleWidget,1,0);
    coursesLayout->addWidget(historyWidget,1,1);
    coursesLayout->setSpacing(0);
    coursesLayout->setMargin(0);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(idWidget);
    mainLayout->addWidget(courseInfoWidget);
    mainLayout->setMargin(2);
    mainLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::setConnections
//!
void MyOwnPage::setConnections(){
    connect(this->myRssButton, SIGNAL(clicked()), this->myRssCourse, SLOT(show()));
    connect(this->myScheduleButton, SIGNAL(clicked()), this->mySchedulePage, SLOT(show()));
    connect(this->idAvatarCLabel, SIGNAL(clicked()), this, SLOT(modifierPersonnelImage()));
}

//!-----------------------------------------------------------------------------------------
