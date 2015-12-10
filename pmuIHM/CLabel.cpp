#include "CLabel.h"

CLabel::CLabel() : QLabel()
{

}

void CLabel::mousePressEvent(QMouseEvent*event){
    emit clicked();
}
