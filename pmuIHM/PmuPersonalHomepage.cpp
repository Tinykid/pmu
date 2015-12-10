#include "PmuPersonalHomepage.h"

PmuPersonalHomepage::PmuPersonalHomepage(int width, int height) : QWidget()
{
    this->width = width;
    this->height = height;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

//!------------------------------------------------------------------------------------
//!
//! \brief PmuPersonalHomepage::initVariable
//!
void PmuPersonalHomepage::initVariable(){
    this->titleBarWidget = new PmuTitleBar(width, height, "個人資料");
}

//!------------------------------------------------------------------------------------
//!
//! \brief PmuPersonalHomepage::constructIHM
//!
void PmuPersonalHomepage::constructIHM(){
    this->avatarCenterLabel = new CLabel();
    this->avatarCenterLabel->setFixedSize(width*0.25, height*0.15);
    this->avatarCenterLabel->setStyleSheet("background-color:#9999CC; color:AliceBlue; border: 0px;border-image:url(:/images/avatar.png)");

    this->avatarLabel = new CLabel();
    this->avatarLabel->setFixedHeight(height*0.15);
    this->avatarLabelLayout = new QHBoxLayout(avatarLabel);
    this->avatarLabelLayout->addWidget(avatarCenterLabel);

    this->userNameLabel = new CLabel();
    this->userNameLabel->setFont(QFont("Segoe UI",20,QFont::Normal,false));
    this->userNameLabel->setText("修改頭像");
    this->userNameLabel->setAlignment(Qt::AlignCenter);
    this->userNameLabel->setStyleSheet("background-color:transparent; color: aliceblue;");

    this->personalInofLabel = new CLabel();
    this->personalInofLabel->setFixedSize(width, height*0.2);
    this->personalInfoLayout = new QVBoxLayout(personalInofLabel);
    this->personalInfoLayout->addWidget(avatarLabel);
    this->personalInfoLayout->addWidget(userNameLabel);
    this->personalInfoLayout->setMargin(0);
    this->personalInfoLayout->setSpacing(0);

    this->somethingElth = new QWidget();

    this->personalHomepageLayout = new QVBoxLayout(this);
    this->personalHomepageLayout->addWidget(titleBarWidget);
    this->personalHomepageLayout->addWidget(personalInofLabel);
    this->personalHomepageLayout->addWidget(somethingElth);
    this->personalHomepageLayout->setMargin(0);
    this->personalHomepageLayout->setSpacing(0);
}

//!------------------------------------------------------------------------------------
//!
//! \brief PmuPersonalHomepage::setConnections
//!
void PmuPersonalHomepage::setConnections(){
    this->connect(this->titleBarWidget->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
