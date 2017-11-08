//
//  Player.h
//  secondGame
//
//  Created by 叶慧伟 on 2017/11/7.
//

#ifndef Player_h
#define Player_h
#include "Entity.h"

class Player : public Entity {
    
public:
    CREATE_FUNC(Player);
    virtual bool init();
    void run();
};


#endif /* Player_h */
