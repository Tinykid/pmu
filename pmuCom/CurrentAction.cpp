#include "CurrentAction.h"
#include <QDebug>

CurrentAction::CurrentAction()
{

}

//! -------------------------------------------------------
//!
//! \brief CurrentAction::setCurrentAction
//! \param action
//!
void CurrentAction::setCurrentAction(QString action){
    this->action = action;
}

//! -------------------------------------------------------
//!
//! \brief CurrentAction::getCurrentAction
//! \return
//!
QString CurrentAction::getCurrentAction(){
    return this->action;
}

//! -------------------------------------------------------
//!
//! \brief CurrentAction::setResponse
//! \param response
//!
void CurrentAction::setResponse(QString response){
    qDebug()<<"setResponse"<<response;
    this->response = response;
}

//! -------------------------------------------------------
//!
//! \brief CurrentAction::getResponse
//! \return
//!
QString CurrentAction::getResponse(){
    return this->response;
}
