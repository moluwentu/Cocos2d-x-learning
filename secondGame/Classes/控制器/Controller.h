//
//  Controller.h
//  secondGame
//
//  Created by 叶慧伟 on 2017/11/8.
//

#ifndef Controller_h
#define Controller_h
#include "cocos2d.h"
#include "ControllerListener.h"

using namespace cocos2d;

class Controller : public Node {
    
public:
    //设置监听对象
    void setControllerListener(ControllerListener *listener);
protected:
    ControllerListener *m_listener;
};

#endif /* Controller_h */
