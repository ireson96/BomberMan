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

    playerOne = new CPlayer("playerone");
    playerOne->CloneSprite("boy");
    playerOne->SetAnimationName("PlayerPic04Animation");
    playerOne->Init();
}
//=============================================================================
//
// 每局游戏进行中
void CGameMain::GameRun( float fDeltaTime )
{
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
        playerOne->OnMove(iKey,true);
    }

}

void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(strstr(szName,"playerone") != NULL)
	{
			playerOne->SetSpriteLinearVelocity(0,0);
	}
	/*if(strstr(szName,"playertwo") != NULL)
	{
			playerTwo->SetSpriteLinearVelocity(0,0);
	}*/
}

