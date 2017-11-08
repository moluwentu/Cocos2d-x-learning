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
    void setViewPointByPlayer();
    void setTileMap(TMXTiledMap *map);
    virtual void setTagPosition(int x, int y);
private:
    TMXTiledMap *m_map;
};


#endif /* Player_h */
