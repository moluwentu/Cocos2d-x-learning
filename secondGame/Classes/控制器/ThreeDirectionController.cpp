//
//  ThreeDirectionController.cpp
//  secondGame-mobile
//
//  Created by 叶慧伟 on 2017/11/8.
//

#include "ThreeDirectionController.h"

bool ThreeDirectionController::init(){
    this->m_xSpeed = 0;
    this->m_ySpeed = 0;
    
    //注册屏幕触摸事件
    registerTouchEvent();
    
    this->scheduleUpdate();
    
    return true;
}

void ThreeDirectionController::update(float dt){
    if (m_listener == NULL) {
        return;
    }
    
    Point curPos = m_listener->getTagPosition();
    curPos.x += m_xSpeed;
    curPos.y += m_ySpeed;
    
    m_listener->setTagPosition(curPos.x + m_xSpeed, curPos.y + m_ySpeed);
}

void ThreeDirectionController::setiXSpeed(int iSpeed){
    this->m_xSpeed = iSpeed;
}

void ThreeDirectionController::setiYSpeed(int iSpeed){
    this->m_ySpeed = iSpeed;
}

void ThreeDirectionController::registerTouchEvent(){
    
    auto listener = EventListenerTouchOneByOne::create();
    
    listener->onTouchBegan = [](Touch *touch,Event *event){
        return true;
    };
    
    listener->onTouchMoved = [&](Touch *touch,Event *event){
        
        //获取单击坐标
        Point touchPos = Director::getInstance()->convertToGL(touch->getLocationInView());
        //获取控制对象坐标
        Point pos = m_listener->getTagPosition();
        
        //判断Y移动方向
        int iSpeed = 0;
        if (touchPos.y > pos.y) {
            iSpeed = 1;
        }else{
            iSpeed = -1;
        }
        
        setiYSpeed(iSpeed);
    };
    
    listener->onTouchEnded = [&](Touch *touch,Event *event){
        //停止Y移动方向
        setiYSpeed(0);
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
