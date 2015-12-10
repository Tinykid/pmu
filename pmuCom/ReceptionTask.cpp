#include "ReceptionTask.h"
#include <QDebug>

ReceptionTask::ReceptionTask(CurrentAction* currentAction){
    this->currentAction = currentAction;
    this->widget = widget;
}

//! -----------------------------------------------------
//!
//! \brief ReceptionTask::run
//!
void ReceptionTask::run(){
    while(1){
        if(this->currentAction->getResponse().contains("success")){
            qDebug()<<"qu ni ma";

        }
        msleep(200);
    }
}
