#include "PmuEnterPage.h"
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QTimer>
#include <QList>
#include <QGesture>

#include "ConnectToServer.h"
#include "CurrentAction.h"
#include "ReceptionTask.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    CurrentAction* currentAction = new CurrentAction();

    ConnectToServer* connectToServer = new ConnectToServer(currentAction);

    PmuEnterPage *pmuEnterPage = new PmuEnterPage(connectToServer, currentAction);

    pmuEnterPage->show();

    return a.exec();
}
