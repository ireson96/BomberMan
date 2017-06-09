#include "Player.h"
#include "Bomb.h"
#include "LessonX.h"

CPlayer::CPlayer(const char *szName):CAnimateSprite(szName)
{
    //ctor
    playerHP = 1;
    bombNum = 1;
    bombPower = 1;
    speed = 8;
    speedX = 0;
    speedY = 0;
    isPushBomb = false;
}

CPlayer::CPlayer(const char *szName,KeyCodes up, KeyCodes down, KeyCodes right, KeyCodes left, KeyCodes setBom):CAnimateSprite(szName),spriteUP(up),spriteDOWN(down),spriteLEFT(left),spriteRIGHT(right),spriteSetBomb(setBom)
{
    //ctor
    playerHP = 1;
    bombNum = 1;
    bombPower = 1;
    speed = 8;
    speedX = 0;
    speedY = 0;
    isPushBomb = false;
}

CPlayer::~CPlayer()
{
    //dtor
}

void CPlayer::Init()
{
    SetSpritePosition(0.f,0.f);
	SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
	SetSpriteCollisionActive(true,true);//设置为可以接受和发生碰撞
	SetSpriteVisible(true);
}


void CPlayer::SetAnimationName(string name)
{
    spriteAnimation[0] = name+string("1");//s
    spriteAnimation[1] = name+string("2");//a
    spriteAnimation[2] = name+string("3");//d
    spriteAnimation[3] = name+string("4");//w
}

void CPlayer::OnAction(int iKey, bool bPress)
{
	if(bPress){
        if(iKey == spriteUP){
            AnimateSpritePlayAnimation(spriteAnimation[3].data(),false);
            SetSpriteLinearVelocity(0,-speed);
        }else if(iKey == spriteRIGHT){
            AnimateSpritePlayAnimation(spriteAnimation[2].data(),false);
            SetSpriteLinearVelocity(speed,0);
        }else if(iKey == spriteDOWN){
            AnimateSpritePlayAnimation(spriteAnimation[0].data(),false);
            SetSpriteLinearVelocity(0,speed);
        }else if(iKey == spriteLEFT){
            AnimateSpritePlayAnimation(spriteAnimation[1].data(),false);
            SetSpriteLinearVelocity(-speed,0);
        }else if(iKey == spriteSetBomb){
            char *szName = CSystem::MakeSpriteName("bomb",g_GameMain.GetBombNum());
            CBomb *temBomb = new CBomb(szName,GetBombPower(),this);
            temBomb->CloneSprite("Bomb");
            temBomb->Init();
            g_GameMain.AddBomb(temBomb);
        }
    }
    else{
        if(iKey == spriteUP && GetSpriteLinearVelocityY()<0){
            SetSpriteLinearVelocityY(0);
        }else if(iKey == spriteRIGHT && GetSpriteLinearVelocityX()>0){
            SetSpriteLinearVelocityX(0);
        }else if(iKey == spriteDOWN && GetSpriteLinearVelocityY()>0){
            SetSpriteLinearVelocityY(0);
        }else if(iKey == spriteLEFT && GetSpriteLinearVelocityX()<0){
            SetSpriteLinearVelocityX(0);
        }
    }
}
