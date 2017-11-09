//
//  ThreeDirectionController.h
//  secondGame
//
//  Created by 叶慧伟 on 2017/11/8.
//

#ifndef ThreeDirectionController_h
#define ThreeDirectionController_h
#include "Controller.h"
#include "cocos2d.h"
using namespace cocos2d;

class ThreeDirectionController : public Controller {
public:
    CREATE_FUNC(ThreeDirectionController);
    virtual bool init();
    virtual void update(float dt);
    //设置x方向的速度
    void setiXSpeed(int iSpeed);
    //设置y方向的速度
    void setiYSpeed(int iSpeed);
    
private:
    int m_xSpeed;
    int m_ySpeed;
    
    //注册屏幕触摸事件
    void registerTouchEvent();
};

#endif /* ThreeDirectionController_h */
