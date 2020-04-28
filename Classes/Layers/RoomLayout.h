//
//  HostLayer.h
//  Survival
//
//  Created by jy_maeng on 2020/04/24.
//

#pragma once

#ifndef HostLayer_h
#define HostLayer_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"

struct Room
{
    std::string title;
    std::string passwoard;
    std::string owner;
    bool isPublic;
    unsigned int capacity;
    std::vector<std::string> userList;
};

class RoomLayout : public cocos2d::ui::Layout
{
    bool init() override;

    cocos2d::Label* _titleLabel;
    
    cocos2d::Label* _ownerLabel;
    
    //cocos2d::MenuItemLabel* _connectBtn;
    cocos2d::ui::Button* _connectionBtn;
    
    void onClicked(cocos2d::Ref* ref);
        
public:
    void updateLayout(const Room& host);
        
public:
    CREATE_FUNC(RoomLayout);
};

#endif /* HostLayer_h */
