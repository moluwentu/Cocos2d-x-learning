//
//  Player.cpp
//  secondGame-mobile
//
//  Created by 叶慧伟 on 2017/11/7.
//

#include "Player.h"

bool Player::init(){
    return true;
}

void Player::run(){
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("boys.plist","boys.png");
    
    SpriteFrame *frame = NULL;
    Vector<SpriteFrame *>frameList;
    
    for (int i = 1; i <= 15; i++) {
        frame = frameCache->getSpriteFrameByName(StringUtils::format("run%d.png",i));
        frameList.pushBack(frame);
    }
    
    //创建动画
    Animation *animation = Animation::createWithSpriteFrames(frameList);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.08f);
    
    Animate *action = Animate::create(animation);
    
    m_sprite->runAction(action);
}
