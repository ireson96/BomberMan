#ifndef PLAYER_H
#define PLAYER_H

#include <CommonClass.h>
#include <iostream>
using namespace std;


class CPlayer : public CAnimateSprite
{
    public:
        CPlayer(const char *szName);
        CPlayer(const char *szName,KeyCodes up, KeyCodes down, KeyCodes right, KeyCodes left, KeyCodes setBom);
        virtual ~CPlayer();

        //void PushBomb();
        void Init();
        void KeyInit(KeyCodes up, KeyCodes down, KeyCodes right, KeyCodes left);
        void OnAction(int iKey, bool bPress);///控制人物移动
        void SetAnimationName(string name);

        ///Set & Get
        int GetBombPower()          {return bombPower;}
    protected:
    private:
        int playerHP,bombNum,bombPower,dir;
        double speed,speedX,speedY;
        bool isPushBomb;
        KeyCodes spriteUP = KEY_W,spriteDOWN = KEY_S,spriteRIGHT = KEY_D,spriteLEFT = KEY_A,spriteSetBomb = KEY_SPACE;//创建枚举类型方便更改键位
        string spriteAnimation[4];

};

#endif // PLAYER_H
