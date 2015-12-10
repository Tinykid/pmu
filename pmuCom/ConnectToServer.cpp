#include "ConnectToServer.h"


/**
 * @brief ConnectToServer::ConnectToServer
 * @param currentAction
 */
ConnectToServer::ConnectToServer(CurrentAction* currentAction){
    this->currentAction = currentAction;
    this->network_manager = new QNetworkAccessManager();
    this->url_str = "http://172.20.35.211:8090/daishangwo/";

    this->connect(this->network_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponse(QNetworkReply*)));
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::reponse
//! \param reply
//!
void ConnectToServer::getResponse(QNetworkReply *reply){
    this->reponse = reply->readAll();
    qDebug()<<"-----------------------------";
    qDebug()<<reply->readAll();
    qDebug()<<reponse;
    qDebug()<<"-----------------------------";
    this->currentAction->setResponse(this->reponse);
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::clear
//!
void ConnectToServer::clear(){
    post_data.clear();
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::composeRequestMessage
//! \param msg
//!
void ConnectToServer::composeRequestMessage(QString msg){
    post_data.append(msg + "&");
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::composeRequestFinalMessage
//! \param msg
//!
void ConnectToServer::composeRequestFinalMessage(QString msg){
    post_data.append(msg);
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::connectera
//!
void ConnectToServer::connectera(QString typeAction){
    this->currentAction->setCurrentAction(typeAction);

    this->network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    this->network_request.setHeader(QNetworkRequest::ContentLengthHeader, post_data.length());
    this->network_request.setUrl(QUrl(url_str + typeAction));

    this->network_manager->post(network_request, post_data);

    this->clear();
}
