//
//  Entity.h
//  secondGame
//
//  Created by 叶慧伟 on 2017/11/7.
//

#ifndef Entity_h
#define Entity_h
#include "cocos2d.h"
#include "Controller.h"
#include "ControllerListener.h"
using namespace cocos2d;

class Entity : public Node,public ControllerListener {
    
public:
    void bindSprite(Sprite *sprite);
    void setController(Controller *controller);
    
    //实现smController的接口方法
    virtual void setTagPosition(int x,int y);
    virtual Point getTagPosition();
protected:
    Sprite *m_sprite;
    Controller *m_controller;
};

#endif /* Entity_h */
