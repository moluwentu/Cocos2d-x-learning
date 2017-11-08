//
//  SimpleMoveController.cpp
//  secondGame-mobile
//
//  Created by 叶慧伟 on 2017/11/8.
//

#include "SimpleMoveController.h"

bool SimpleMoveController::init(){
    this->m_iSpeed = 0;
    //每帧都调用update
    this->scheduleUpdate();
    
    return true;
}

void SimpleMoveController::update(float dt){
    if (m_listener == NULL) {
        return;
    }
    
    Point pos = m_listener->getTagPosition();
    pos.x += m_iSpeed;
    m_listener->setTagPosition(pos.x, pos.y);
}

void SimpleMoveController::setiSpeed(int iSpeed){
    this->m_iSpeed = iSpeed;
}
