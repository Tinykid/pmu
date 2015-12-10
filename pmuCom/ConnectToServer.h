#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextCodec>

#include "CurrentAction.h"
#include "ReceptionTask.h"

class ConnectToServer : public QObject{

    Q_OBJECT

public:
    ConnectToServer(CurrentAction* currentAction);

    void connectera(QString typeAction);

    void clear();

    void composeRequestMessage(QString msg);
    void composeRequestFinalMessage(QString msg);

    //void getReponse();

private:
    QString url_str;
    QNetworkAccessManager *network_manager;
    QNetworkReply *reply;
    QNetworkRequest network_request;
    QByteArray post_data;
    QString reponse;

    CurrentAction* currentAction;

public slots:
    void getResponse(QNetworkReply*reply);
};

#endif // CONNECTTOSERVER_H
