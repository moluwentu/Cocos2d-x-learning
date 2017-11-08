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

void Player::setViewPointByPlayer(){
    if (m_sprite == NULL) {
        return;
    }
    
    Layer *parent = (Layer *)getParent();
    
    //地图方块数量
    Size mapTileNum = m_map->getMapSize();
    
    //单个格子大小
    Size tileSize = m_map->getTileSize();
    
    //地图大小
    Size mapSize = Size(mapTileNum.width * tileSize.width,mapTileNum.height * tileSize.height);
    
    //屏幕大小
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //主角坐标
    Point spritePos = getPosition();
    
    //如果主角坐标小于屏幕一半，取中点，否则取主角坐标
    float x = std::max(spritePos.x, visibleSize.width / 2);
    float y = std::max(spritePos.y, visibleSize.height / 2);
    
    //如果大于极限值，取极限值坐标
    x = std::min(x, mapSize.width - visibleSize.width / 2);
    y = std::min(y, mapSize.height - visibleSize.height / 2);
    
    Point desPos = Point(x,y);
    
    Point centerPos = Point(visibleSize.width / 2,visibleSize.height / 2);
    
    //屏幕中点和要移动的目标点间的距离
    Point viewPos = centerPos - desPos;
    
    parent->setPosition(viewPos);
}

void Player::setTileMap(TMXTiledMap *map){
    this->m_map = map;
}

void Player::setTagPosition(int x, int y){
    Entity::setTagPosition(x, y);
    
    //以主角为中心移动地图
    setViewPointByPlayer();
}
