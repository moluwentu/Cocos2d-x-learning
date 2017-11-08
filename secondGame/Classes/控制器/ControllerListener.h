//
//  ControllerListener.h
//  secondGame
//
//  Created by 叶慧伟 on 2017/11/8.
//

#ifndef ControllerListener_h
#define ControllerListener_h
#include "cocos2d.h"

using namespace cocos2d;

class ControllerListener {
    
public:
    //设置坐标
    virtual void setTagPosition(int x, int y) = 0;
    //获取坐标
    virtual Point getTagPosition() = 0;
};

#endif /* ControllerListener_h */
