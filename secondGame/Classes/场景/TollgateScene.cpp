//
//  TollgateScene.cpp
//  secondGame-mobile
//
//  Created by 叶慧伟 on 2017/11/7.
//

#include "TollgateScene.h"
#include "Player.h"
//#include "SimpleMoveController.h"
#include "ThreeDirectionController.h"

Scene* TollgateScene::createScene(){
    auto scene = Scene::create();
    auto layer = TollgateScene::create();
    scene->addChild(layer);
    return scene;
}

bool TollgateScene::init(){
    if (!Layer::init()) {
        return false;
    };
    
    TMXTiledMap *map = TMXTiledMap::create("level01.tmx");
    this->addChild(map);
    
    addPlayer(map);
    
    return true;
}

void TollgateScene::addPlayer(TMXTiledMap *map){
    
    TMXObjectGroup *objGrounp = map->getObjectGroup("objects");
    
    ValueMap playerPointMap = objGrounp->getObject("PlayerPoint");
    float playerX = playerPointMap.at("x").asFloat();
    float playerY = playerPointMap.at("y").asFloat();
    
//    Size visibileSize = Director::getInstance()->getVisibleSize();
    //创建精灵
    Sprite *sprite = Sprite::create("player.png");
    
    Player *mPlayer = Player::create();
    mPlayer->bindSprite(sprite);
    mPlayer->run();
    mPlayer->setTileMap(map);
    
    mPlayer->setPosition(Point(playerX,playerY));
    
    map->addChild(mPlayer);
    
//    SimpleMoveController *smController = SimpleMoveController::create();
    //设置移动速度
//    smController->setiSpeed(1);
    
//    this->addChild(smController);
    
//    mPlayer->setController(smController);
    
    
    ThreeDirectionController *thController = ThreeDirectionController::create();
    thController->setiXSpeed(1);
    thController->setiYSpeed(0);
    
    this->addChild(thController);
    
    mPlayer->setController(thController);
}
