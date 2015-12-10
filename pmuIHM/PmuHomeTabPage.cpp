#include "PmuHomeTabPage.h"

PmuHomeTabPage::PmuHomeTabPage(int width, int height, QFont *caracterStyle) : QTabWidget()
{
    this->width = width;
    this->height = height;
    this->caracterStyle = caracterStyle;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->drawBackground();
}

void PmuHomeTabPage::optionClicked(int index){
    qDebug()<<index;
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::initVariable
//!
void PmuHomeTabPage::initVariable(){
    this->pmumainPage = new PmuMainPage(width, height);
    this->neighborPage = new PmuNeighborPage(width,height);
    this->selectPage = new SelectPage(width, height);
    this->myOwnPage = new MyOwnPage(width, height);
    this->setStyleSheet("QTabWidget::pane{border:0;} "
                        "QTabBar::tab{border:0;background:white;color:#363636; width:" + QString::number(width*0.25) + ";height:" + QString::number(height*0.06) + ";}");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::constructIHM
//!
void PmuHomeTabPage::constructIHM(){
    //this->setIconSize(QSize(width*0.10,height*0.06));

    this->insertTab(0,this->pmumainPage,"首页");
    this->setTabIcon(0,QIcon(":/images/homePage.png"));

    this->insertTab(1,this->neighborPage,"附近");
    this->setTabIcon(1,QIcon(":/images/homePage.png"));

    this->insertTab(2,this->selectPage,"精選");
    this->setTabIcon(2,QIcon(":/images/homePage.png"));

    this->insertTab(3,this->myOwnPage,"我的");
    this->setTabIcon(3,QIcon(":/images/homePage.png"));

    this->setTabPosition(South);
    this->setFont(QFont("Segoe UI",15,QFont::Normal,false));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::setConnections
//!
void PmuHomeTabPage::setConnections(){
   this->connect(this, SIGNAL(tabBarClicked(int)), this, SLOT(optionClicked(int)));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::drawBackground
//!
void PmuHomeTabPage::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}
