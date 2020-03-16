#ifndef MS_MANAGER_H__
#define MS_MANAGER_H__

#include "cocos2d.h"
#include "MySprite.h"

class MSManager : public cocos2d::Node
{
public:
    enum class Type{
       MY_SPRITE,
       ITEM_SPRITE,
       UNIT_SPRITE,
       PAWN_SPRITE,
       SURVIVOR_SPRITE
    };

    /* get type of MySprite in manager */
    static Type getType(std::string id);

    /* if has id return true else false */
    static bool hasMySprite(std::string id);

    /* add MySprite to manager*/
    static void addMySprite(MySprite*);

    /* get MySprite */
    static MySprite *getMySprite(std::string id);

    /* get MySprite as ItemSprite */
    static class ItemSprite *getAsItem(std::string id);

    /* get MySprite as UnitSprite */
    static class UnitSprite *getAsUnit(std::string id);

    /* get MySprite as PawnSprite */
    static class PawnSprite *getAsPawn(std::string id);

    /* get MySprite as SurvivorSprite */
    static class SurvivorSprite *getAsSurvivor(std::string id);

    /* remove MySprite in manager */
    static void remove(std::string id);

private:
    /* manager of MySprite */
    static std::map<std::string, std::pair<Type, MySprite *>> _manager;

friend class Multi;
};
#endif // MS_MANAGER_H__