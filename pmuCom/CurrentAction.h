#ifndef CURRENTACTION_H
#define CURRENTACTION_H

#include <QString>

class CurrentAction
{
public:
    CurrentAction();

    QString action;
    QString response;

    void setCurrentAction(QString action);
    void setResponse(QString response);

    QString getCurrentAction();
    QString getResponse();
};

#endif // CURRENTACTION_H
