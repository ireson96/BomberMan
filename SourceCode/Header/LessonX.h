/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include "Player.h"
#include "Bomb.h"
#include "BombFire.h"
#include <bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMain
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
	///定义全局精灵
	CSprite     *m_pStart;   //开始精灵
	CPlayer     *playerOne;
	CPlayer     *playerTwo;
	vector<CBomb*> bombVector;
	vector<CBombFire*> bombFireVector;
	int bombNum,bombFireNum;

public:
	CGameMain();            //构造函数
	~CGameMain();           //析构函数

	// Get方法
	int				GetGameState()											{ return m_iGameState; }
	///Get 炸弹数量
	int             GetBombNum()        {return bombNum;}
	///Get 炸弹粒子效果数量
	int             GetBombFireNum()    {return bombFireNum;}

	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }

	// 游戏主循环等
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();

	///Main函数运行时调用
	void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void OnKeyUp( const int iKey );
	void OnSpriteColWorldLimit( const char *szName, const int iColSide );
	void OnSpriteColSprite( const char *szSrcName, const char *szTarName );

	///将炸弹加入容器
	void AddBomb(CBomb *tempBomb);
	///将炸弹粒子效果加入容器
	void AddBombFire(CBombFire *tempBombFire);
	///根据名字寻找炸弹
	CBomb* FindBombForName(const char *bombName);


};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
