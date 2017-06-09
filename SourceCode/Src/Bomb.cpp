#include "Bomb.h"
#include "LessonX.h"

CBomb::CBomb(const char *szName,int playerPower,CPlayer *owner):CSprite(szName),power(playerPower),own(owner)
{
    //ctor
    ownName = own->GetName();
}

void CBomb::Init()
{
    SetSpritePosition(own->GetSpritePositionX(),own->GetSpritePositionY());
    SetSpriteCollisionReceive(true);
    SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    SetSpriteVisible(true);
    SetSpriteLifeTime(3);
}

CBomb::~CBomb()
{
    //dtor
    //cout<<"bomb!"<<endl;
    SetSpriteVisible(false);
    char *szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
    CBombFire *tempBombFire = new CBombFire( "bombfire", szMyName, power , UP);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionReceive(true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(true);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();

    szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire", szMyName, power , DOWN);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionReceive(true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(true);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();

    szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire", szMyName, power , LEFT);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionActive(true,true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(true);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();

    szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire", szMyName, power , RIGHT);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionActive(true,true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(true);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();





    szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire1", szMyName, power , UP);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionReceive(true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(true);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();

    szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire1", szMyName, power , DOWN);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionReceive(true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(false);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();

    szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire1", szMyName, power , LEFT);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionActive(true,true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(false);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();

    szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
    tempBombFire = new CBombFire( "bombfire1", szMyName, power , RIGHT);
    tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY());
    tempBombFire->SetSpriteCollisionActive(true,true);
    tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
    tempBombFire->SetSpriteVisible(false);
    tempBombFire->SetSpriteLifeTime(1);
    g_GameMain.AddBombFire(tempBombFire);
    tempBombFire->Init();
    cout<<"ok"<<endl;
}
