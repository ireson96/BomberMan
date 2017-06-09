#include "BombFire.h"
#include "LessonX.h"

/*CBombFire::CBombFire( const char *szCloneName, const char *szMyName, const float fTime , int lastnum , Position sid):CEffect(szCloneName,szMyName,fTime),side(sid),lastNum(lastnum)
{
    //ctor
    cout<<"I am a BombFire"<<endl;
}*/

CBombFire::CBombFire(const char *szCloneName,const char *szName,int lastnum,Position sid):CSprite(szName,szCloneName),lastNum(lastnum),side(sid)
{
    cout<<"I am a BombFire  "<<side<<endl;
}

CBombFire::~CBombFire()
{
    //dtor
    cout<<"one Bomb Fire was delete"<<endl;
}

void CBombFire::Init()
{
    if(lastNum>0){
            cout<<lastNum<<endl;
        switch(side){
        case UP:
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire", szMyName, lastNum-i , UP);
                tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY()-4*i);
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);
            }
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire1", szMyName, lastNum-i , UP);
                tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY()-4*i);
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);
            }
            break;
        case DOWN:
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire", szMyName, lastNum-i , DOWN);
                tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY()+4*i);
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);
            }
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire1", szMyName, lastNum-i , DOWN);
                tempBombFire->SetSpritePosition(GetSpritePositionX(),GetSpritePositionY()+4*i);
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);
            }
            break;
        case LEFT:
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire", szMyName, lastNum-i , LEFT);
                tempBombFire->SetSpritePosition(GetSpritePositionX()-4*i,GetSpritePositionY());
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);

            }
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire1", szMyName, lastNum-i , LEFT);
                tempBombFire->SetSpritePosition(GetSpritePositionX()-4*i,GetSpritePositionY());
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);

            }
            break;
        case RIGHT:
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("bomfire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire", szMyName, lastNum-i , RIGHT);
                tempBombFire->SetSpritePosition(GetSpritePositionX()+4*i,GetSpritePositionY());
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);
            }
            for(int i=1;i<=lastNum;i++){
                char *szMyName = CSystem::MakeSpriteName("fire",g_GameMain.GetBombFireNum());
                CBombFire *tempBombFire = new CBombFire( "bombfire1", szMyName, lastNum-i , RIGHT);
                tempBombFire->SetSpritePosition(GetSpritePositionX()+4*i,GetSpritePositionY());
                tempBombFire->SetSpriteCollisionActive(true,true);
                tempBombFire->SetSpriteWorldLimit(WORLD_LIMIT_NULL, -26, -22, 26, 22);
                tempBombFire->SetSpriteVisible(true);
                tempBombFire->SetSpriteLifeTime(1);
                g_GameMain.AddBombFire(tempBombFire);
            }
            break;
        }
    }
}
