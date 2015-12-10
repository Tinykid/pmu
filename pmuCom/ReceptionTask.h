#ifndef RECEPTIONTASK_H
#define RECEPTIONTASK_H

#include <QThread>
#include "CurrentAction.h"


class ReceptionTask : public QThread
{
public:
    ReceptionTask(CurrentAction* currentAction);
    void run();

private:
    CurrentAction* currentAction;
    QWidget* widget;
};

#endif // RECEPTIONTASK_H
