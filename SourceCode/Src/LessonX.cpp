/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"


////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;

//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
CGameMain::CGameMain()
{
	m_iGameState			=	0;
	///初始化精灵
	m_pStart	= new CSprite("start");
}
//==============================================================================
//
// 析构函数
CGameMain::~CGameMain()
{
    ///销毁所有创建的精灵
    delete m_pStart;
}

//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
			SetGameState(2); // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void CGameMain::GameInit()
{
    ///开局设置按任意键开始隐藏
    m_pStart->SetSpriteVisible(false);
    ///创建玩家
    playerOne = new CPlayer("playerone");
    playerOne->CloneSprite("boy");
    playerOne->SetAnimationName("PlayerPic04Animation");
    playerOne->Init();
    playerTwo = new CPlayer("playertwo",KEY_UP,KEY_DOWN,KEY_RIGHT,KEY_LEFT,KEY_ENTER);
    playerTwo->CloneSprite("girl");
    playerTwo->SetAnimationName("PlayerPic03Animation");
    playerTwo->Init();
    ///初始化容器
    while(!bombVector.empty()) bombVector.pop_back();
    while(!bombFireVector.empty()) bombFireVector.pop_back();
    bombNum = 0;
    bombFireNum = 0;


}
//=============================================================================
//
// 每局游戏进行中
void CGameMain::GameRun( float fDeltaTime )
{
    ///检查过期炸弹
    for(vector<CBomb*>::iterator it=bombVector.begin(); it!=bombVector.end();)
    {
        CBomb *tempBomb =*it;
        if(tempBomb->GetSpriteLifeTime()<=0)
        {
            bombVector.erase(it);
            //tempBomb->DeleteSprite();
            cout<<"delete bomb"<<endl;
            delete tempBomb;
        }
        else
        {
            it++;
        }
    }
    ///检查过期爆炸效果
    for(vector<CBombFire*>::iterator it=bombFireVector.begin(); it!=bombFireVector.end();)
    {
        CBombFire *tempBombFire =*it;
        if(tempBombFire->GetSpriteLifeTime()<=0)
        {
            bombFireVector.erase(it);
            //tempBomb->DeleteSprite();
            cout<<"delete bomb fire"<<endl;
            delete tempBombFire;
        }
        else
        {
            it++;
        }
    }
}
//=============================================================================
//
// 本局游戏结束
void CGameMain::GameEnd()
{
}


///当有按键按下时
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
    if(0 == GetGameState()){
        m_iGameState = 1;
    }

    if(2 == GetGameState()){
        playerOne->OnAction(iKey,true);
        playerTwo->OnAction(iKey,true);
    }

}

void CGameMain::OnKeyUp( const int iKey )
{
    if(2 == GetGameState()){
        playerOne->OnAction(iKey,false);
        playerTwo->OnAction(iKey,false);
    }
}

void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(strstr(szName,"playerone") != NULL )
	{
	    if(iColSide == 0 || iColSide == 1){
            playerOne->SetSpriteLinearVelocityX(0);
	    }else{
            playerOne->SetSpriteLinearVelocityY(0);
	    }
	}
	if(strstr(szName,"playertwo") != NULL)
	{
        if(iColSide == 0 || iColSide == 1){
            playerTwo->SetSpriteLinearVelocityX(0);
	    }else{
            playerTwo->SetSpriteLinearVelocityY(0);
	    }
	}
}

void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    cout << szSrcName << "   " << szTarName <<endl;
    if(strstr(szTarName,"bomb")){
        if(strstr(szSrcName,"playerone")){
            CBomb *tempbomb = FindBombForName(szTarName);
            if(!strstr(tempbomb->GetOwnerName(),szSrcName)){
                playerOne->SetSpriteLinearVelocity(0,0);
            }
        }
    }
    if(strstr(szTarName,"bomb")){
        if(strstr(szSrcName,"playertwo")){
            CBomb *tempbomb = FindBombForName(szTarName);
            if(!strstr(tempbomb->GetOwnerName(),szSrcName)){
                playerTwo->SetSpriteLinearVelocity(0,0);
            }
        }
    }

    ///检查玩家是否与炸弹相碰撞
    if(strstr(szTarName,"bomfire")){
        if(strstr(szSrcName,"playerone")){
            //delete playerOne;
            cout<<"playerone die"<<endl;
        }
        if(strstr(szSrcName,"playertwo")){
            //delete playerTwo;
            cout<<"playertwo die"<<endl;
        }
    }
}


void CGameMain::AddBomb(CBomb *tempBomb)
{
    bombVector.push_back(tempBomb);
    bombNum++;
}
void CGameMain::AddBombFire(CBombFire *tempBombFire)
{
    bombFireVector.push_back(tempBombFire);
    bombFireNum++;
}

CBomb* CGameMain::FindBombForName(const char *bombName)
{
   for(vector<CBomb*>::iterator it=bombVector.begin(); it!=bombVector.end();)
    {
        CBomb *tempBomb =*it;
        if(strstr(tempBomb->GetName(),bombName))
        {
            return tempBomb;
        }
        else
        {
            it++;
        }
    }
    return NULL;
}

