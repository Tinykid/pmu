#include "PmuEnterPage.h"

PmuEnterPage::PmuEnterPage(ConnectToServer* connectToServer,CurrentAction* currentAction)
    : QWidget()
{
    this->connectToServer = connectToServer;
    this->currentAction = currentAction;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->drawBackground();
}

PmuEnterPage::~PmuEnterPage(){}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::initVariable
//!
void PmuEnterPage::initVariable(){
    this->flag = true;
    this->screen = QApplication::screens().at(0);
    this->height = screen->availableSize().height();
    this->width = screen->availableSize().width();
    this->caracterStyle = new QFont("Segoe UI", 17, QFont::AnyStyle, false);

    this->regAndSignPage = new RegAndSignPage(width, height, flag, this->connectToServer, this->currentAction);
    this->pmuHomeTabPage = new PmuHomeTabPage(width, height, caracterStyle);
    //this->regAndSignPage = new RegAndSignPage(width, height, flag);
    this->coursePublishPage = new CoursePublishPage(width, height, caracterStyle);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::setConnections
//!
void PmuEnterPage::setConnections(){
    this->connect(this->enterHomePageButton, SIGNAL(clicked()), pmuHomeTabPage, SLOT(show()));
    this->connect(this->signInButton, SIGNAL(clicked()), this, SLOT(showSignInPage()));
    this->connect(this->signUpButton, SIGNAL(clicked()), this, SLOT(showSignUpPage()));
    this->connect(this->coursePublishButton, SIGNAL(clicked()),this,SLOT(showDialog()));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::constructIHM
//!
void PmuEnterPage::constructIHM(){
    //--------------------------------------------------------------------------------------
    //titleBar layout
    //--------------------------------------------------------------------------------------
    this->titleBarItem = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->coursePublishButton = new QPushButton("發布課程");
    this->coursePublishButton->setDefault (false);
    this->coursePublishButton->setFont(*caracterStyle);
    this->coursePublishButton->setStyleSheet("QPushButton{background-color:transparent; color:AliceBlue; border: 0px;}"
                                             "QPushButton:focus{padding: -2;}");

    this->helpButton = new QPushButton("幫助");
    this->helpButton->setFont(*caracterStyle);
    this->helpButton->setFlat(true);
    this->helpButton->setStyleSheet("QPushButton{background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;}"
                                    "QPushButton:focus{padding: -2;}");

    this->signInButton = new QPushButton("登錄");
    this->signInButton->setFont(*caracterStyle);
    this->signInButton->setStyleSheet("QPushButton{background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;}"
                                      "QPushButton:focus{padding: -2;}");

    this->signUpButton = new QPushButton("註冊");
    this->signUpButton->setFont(*caracterStyle);
    this->signUpButton->setStyleSheet("QPushButton{background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding-right: 20px;}"
                                      "QPushButton:focus{padding: -2;}");

    this->titleBar = new QWidget();
    this->titleBar->setStyleSheet("background-color:transparent");
    this->titleBar->setFixedHeight(height*0.08);
    this->titleBarLayout = new QHBoxLayout(titleBar);
    this->titleBarLayout->addItem(titleBarItem);
    this->titleBarLayout->addWidget(coursePublishButton);
    this->titleBarLayout->addWidget(helpButton);
    this->titleBarLayout->addWidget(signInButton);
    this->titleBarLayout->addWidget(signUpButton);
    this->titleBarLayout->setSpacing(20);
    this->titleBarLayout->setMargin(0);

    //--------------------------------------------------------------------------------------
    //centerplantform layout
    //--------------------------------------------------------------------------------------
    this->welcomLabel = new QLabel("學  滴  野");
   // this->welcomLabel->setFixedHeight(height * 0.2);
    this->welcomLabel->setFont(QFont("华文行楷", 50, QFont::Bold, false));
    this->welcomLabel->setStyleSheet("background-color:transparent; color: AliceBlue");
    this->welcomLabel->setAlignment(Qt::AlignCenter);

    this->searchingLineEdit = new QLineEdit();
    this->searchingLineEdit->setFixedHeight(height*0.053);
    this->searchingLineEdit->setPlaceholderText("輸入學科、分類");
    this->searchingLineEdit->setStyleSheet("QLineEdit { color:AliceBlue; border: 0px solid Gray; border-radius: 15px; color:rgb(0, 0, 0); background-color: silver aerogel; } "
                                           "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 15px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");

    this->searchingButton = new QPushButton();
    this->searchingButton->setFixedSize(width*0.092,height*0.053);
    this->searchingButton->setIconSize(QSize(width*0.092,height*0.053));
    this->searchingButton->setStyleSheet("QPushButton{border-image: url(:/images/search.png); color:AliceBlue;background-color:AliceBlue;border: 0px; border-radius: 15px;}"
                                         "QPushButton:pressed{border-image: url(:/images/search1.png);color:AliceBlue;background-color:silver aerogel;border: 0px;border-radius: 15px;}"
                                         "QPushButton:focus{padding: -2;}");

    this->optionCombox = new QComboBox();
    this->optionCombox->setFixedSize(width*0.16, height*0.053);
    this->optionCombox->setFont(*caracterStyle);
    this->optionCombox->insertItem(0,"語言");
    this->optionCombox->insertItem(1,"音樂");
    this->optionCombox->insertItem(2,"舞蹈");
    this->optionCombox->setStyleSheet( "QComboBox{color:gray;background-color:silver aerogel;border:0px;border-radius:15px;padding:0px;}"
                                       //"QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                       "QComboBox::drop-down{width: 50px;border: 0px;border-radius:15px;border-color:AliceBlue;border-bottom-right-radius: 15px;border-top-right-radius:15px;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                       "QComboBox::down-arrow{image: url(:/images/down.png);}"
                                       "QComboBox::down-arrow{width:40; height:40}");
    this->searchingBar = new QFrame();
    this->searchingBar->setStyleSheet("background-color:AliceBlue; color:AliceBlue; border: 1px solid aliceblue ;border-radius:15px; ");
    this->searchingBar->setFixedHeight(height*0.053);
    this->searchingBarLayout = new QHBoxLayout(this->searchingBar);
    this->searchingBarLayout->addWidget(this->searchingLineEdit);
    this->searchingBarLayout->addWidget(this->searchingButton);
    this->searchingBarLayout->addWidget(this->optionCombox);
    this->searchingBarLayout->setSpacing(0);
    this->searchingBarLayout->setMargin(0);

    this->enterHomePageButton = new QPushButton("進入主頁");
    this->enterHomePageButton->setStyleSheet("QPushButton{background-color:silver aerogel; color: aliceblue; border: 1px solid white; border-radius:16px}"
                                             "QPushButton:focus{padding: -3;}");
    this->enterHomePageButton->setFixedSize(width*0.28,height*0.053);

    this->enterHomePageWidget =new QWidget();
    //this->enterHomePageWidget->setFixedHeight(height*0.5);
    this->enterHomePageWidget->setStyleSheet("background-color:transparent;");
    this->enterHomePageWidgetLayout = new QHBoxLayout(this->enterHomePageWidget);
    this->enterHomePageWidgetLayout->addWidget(this->enterHomePageButton);

    this->centerPlantform = new QWidget();
    this->centerPlantform->setStyleSheet("background-color:transparent");
    this->centerPlantform->setFixedSize(width*0.74, height*0.53);
    this->centerPlantformLayout = new QVBoxLayout(centerPlantform);
    this->centerPlantformLayout->addWidget(this->welcomLabel);
//    this->centerPlantformLayout->addStretch();
    this->centerPlantformLayout->addWidget(this->searchingBar);
//    this->centerPlantformLayout->addStretch();
    this->centerPlantformLayout->addWidget(this->enterHomePageWidget);
    this->centerPlantformLayout->setSpacing(0);
    this->centerPlantformLayout->setMargin(0);

    //--------------------------------------------------------------------------------------
    //mainplantform layout
    //--------------------------------------------------------------------------------------
    this->mainPlantform = new QWidget();
    this->mainPlantform->setStyleSheet("background-color:transparent");
    this->mainPlantformLayout = new QHBoxLayout(this->mainPlantform);
    this->mainPlantformLayout->addWidget(this->centerPlantform);
    //--------------------------------------------------------------------------------------
    //main layout
    //--------------------------------------------------------------------------------------
    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->addWidget(this->titleBar);
    this->mainLayout->addWidget(this->mainPlantform);
    this->mainLayout->setSpacing(0);
    this->mainLayout->setMargin(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief pmuEnterPage::drawBackground
//!
void PmuEnterPage::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuEnterPage::showSignIpPage
//!
void PmuEnterPage::showSignInPage(){
    //this->flag = true;
    this->regAndSignPage->setState(false);
    this->regAndSignPage->showSignUpInformation();
    this->regAndSignPage->show();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuEnterPage::showSignUpPage
//!
void PmuEnterPage::showSignUpPage(){
    //this->flag = false;
    this->regAndSignPage->setState(true);
    this->regAndSignPage->showSignUpInformation();
    this->regAndSignPage->show();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuEnterPage::creatDialogWidget
//!
void PmuEnterPage::creatDialogWidget(){
    this->optionInfoLabel = new QLabel("請 問 您 是 ?");
    this->optionInfoLabel->setFixedHeight(height*0.35*0.15);
    this->optionInfoLabel->setStyleSheet("background-color:transparent; color:skyBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");
    this->optionInfoLabel->setFont(QFont("Segoe UI", 20, QFont::AnyStyle, false));
    //this->optionInfoLabel->adjustSize();
    //this->optionInfoLabel->setGeometry(QRect(328, 240, 329, 27*4));
    //this->optionInfoLabel->setWordWrap(true);
    this->optionInfoLabel->setAlignment(Qt::AlignLeft);

    this->individualButton = new QPushButton("個  人");
    this->individualButton->setFixedSize(width*0.75*0.5,height*0.35*0.4);
    this->individualButton->setFont(QFont("Segoe UI", 25, QFont::AnyStyle, false));
    this->individualButton->setStyleSheet("QPushButton{background-color:transparent; color:skyBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;}"
                                          "QPushButton:focus{padding:-2}");

//    this->orLabel = new QLabel("OR");
//    this->orLabel->setFont(QFont("Segoe UI", 25, QFont::AnyStyle, false));
//    this->orLabel->setStyleSheet("background-color:transparent; color:skyBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");
    this->organizationButton = new QPushButton("機  構");
    this->organizationButton->setFixedSize(width*0.75*0.5,height*0.35*0.4);
    this->organizationButton->setFont(QFont("Segoe UI", 25, QFont::AnyStyle, false));
    this->organizationButton->setStyleSheet("QPushButton{background-color:transparent; color:skyBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;}"
                                            "QPushButton:focus{padding:-2}");

    this->optionWidget = new QWidget();
    this->optionWidget->setFixedHeight(height*0.35*0.4);
    this->optionWidgetLayout = new QHBoxLayout(optionWidget);
    this->optionWidgetLayout->addWidget(individualButton);
    //this->optionWidgetLayout->addWidget(orLabel);
    this->optionWidgetLayout->addWidget(organizationButton);
    this->optionWidgetLayout->setMargin(0);
    this->optionWidgetLayout->setSpacing(0);
    //this->optionWidgetLayout->setAlignment(Qt::AlignCenter);

    this->cancelButton = new QPushButton("取 消  ");
    this->cancelButton->setStyleSheet("background-color:transparent; color:skyBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->returnLayout = new QHBoxLayout();
    this->returnLayout->addStretch(0);
    this->returnLayout->addWidget(cancelButton);
    this->returnLayout->setAlignment(Qt::AlignRight);

    this->individualOrOrgDialog = new QDialog();
    this->individualOrOrgDialog->setAttribute(Qt::WA_ShowModal, true);
    this->individualOrOrgDialog->setStyleSheet("background-color:#F7F083");
    this->individualOrOrgDialog->setFixedSize(width*0.75,height*0.3);
    this->dialogLayout = new QVBoxLayout(individualOrOrgDialog);
    this->dialogLayout->addWidget(optionInfoLabel);
    this->dialogLayout->addWidget(optionWidget);
    this->dialogLayout->addLayout(returnLayout);
    this->dialogLayout->setMargin(0);
    this->dialogLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuEnterPage::showDialog
//!
void PmuEnterPage::showDialog(){
    this->creatDialogWidget();
    //this->individualOrOrgDialog->connect(this->individualButton, SIGNAL(clicked()), , SLOT());
    this->individualOrOrgDialog->connect(this->individualButton, SIGNAL(clicked()), this, SLOT(showCoursePublishPage()));
    this->individualOrOrgDialog->connect(this->cancelButton, SIGNAL(clicked()), this->individualOrOrgDialog, SLOT(close()));

    this->individualOrOrgDialog->show();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuEnterPage::showCoursePublishPage
//!
void PmuEnterPage::showCoursePublishPage(){
    this->coursePublishPage->show();
    this->individualOrOrgDialog->close();
}
