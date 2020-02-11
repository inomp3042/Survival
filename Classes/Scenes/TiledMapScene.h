//
//  TiledMapScene.h
//  MyGame
//
//  Created by jy_maeng on 2020/01/31.
//
#ifndef TiledMapScene_h
#define TiledMapScene_h

#include "cocos2d.h"

#endif /* TiledMapScene_h */

enum class Direction
{
    Vertical,
    Horizon
};

class TiledMapScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    CREATE_FUNC(TiledMapScene);
    
public:
    /**
     @brief This function is Called every frame and set view-point on center
     */
    void setViewPointCenter(const cocos2d::Vec2 position);
    
    /**
     @brief Keyboard listeneres manage pawn sprite movement
     */
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
    /**
    @brief Keyboard listeneres manage pawn sprite movement
    */
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) override;
    
    void update(float deltaTime) override;

private:
    /**
     @brief Return tile-location on position
     */
    cocos2d::Point getTileCoorForPosition(const cocos2d::Vec2& position);

    /**
     @brief Returns true if tile at postion is collidable
     */
    bool isCollidableTile(const cocos2d::Vec2& position);

	/**
	 @brief Check how many trees in world and spawn tree if tree is less than 5
	 */
	void checkTreesInWorld();

private:
    cocos2d::TMXTiledMap *_tileMap;
    cocos2d::TMXLayer *_meta;
    
    class PawnSprite* _player;
};