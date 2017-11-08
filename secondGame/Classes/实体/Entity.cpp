//
//  Entity.cpp
//  secondGame-mobile
//
//  Created by 叶慧伟 on 2017/11/7.
//

#include "Entity.h"

void Entity::bindSprite(Sprite *sprite){
    m_sprite = sprite;
    this->addChild(m_sprite);
}

void Entity::setController(Controller *controller){
    this->m_controller = controller;
    m_controller->setControllerListener(this);
}

void Entity::setTagPosition(int x, int y){
    setPosition(Point(x,y));
}

Point Entity::getTagPosition(){
    return getPosition();
}
