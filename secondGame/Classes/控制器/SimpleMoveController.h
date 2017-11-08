//
//  SimpleMoveController.h
//  secondGame
//
//  Created by 叶慧伟 on 2017/11/8.
//

#ifndef SimpleMoveController_h
#define SimpleMoveController_h
#include "cocos2d.h"
#include "Controller.h"
using namespace cocos2d;

class SimpleMoveController : public Controller {
public:
    CREATE_FUNC(SimpleMoveController);
    virtual bool init();
    virtual void update(float dt);
    
    //设置移动速度
    void setiSpeed(int iSpeed);
private:
    int m_iSpeed;
};

#endif /* SimpleMoveController_h */
