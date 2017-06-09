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
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState			=	0;
	///��ʼ������
	m_pStart	= new CSprite("start");
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
    ///�������д����ľ���
    delete m_pStart;
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
    ///�������ð��������ʼ����
    m_pStart->SetSpriteVisible(false);

    playerOne = new CPlayer("playerone");
    playerOne->CloneSprite("boy");
    playerOne->SetAnimationName("PlayerPic04Animation");
    playerOne->Init();
    playerTwo = new CPlayer("playertwo",KEY_UP,KEY_DOWN,KEY_RIGHT,KEY_LEFT,KEY_ENTER);
    playerTwo->CloneSprite("girl");
    playerTwo->SetAnimationName("PlayerPic03Animation");
    playerTwo->Init();
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
}


///���а�������ʱ
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

