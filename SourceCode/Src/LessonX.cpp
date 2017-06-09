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
    ///�������
    playerOne = new CPlayer("playerone");
    playerOne->CloneSprite("boy");
    playerOne->SetAnimationName("PlayerPic04Animation");
    playerOne->Init();
    playerTwo = new CPlayer("playertwo",KEY_UP,KEY_DOWN,KEY_RIGHT,KEY_LEFT,KEY_ENTER);
    playerTwo->CloneSprite("girl");
    playerTwo->SetAnimationName("PlayerPic03Animation");
    playerTwo->Init();
    ///��ʼ������
    while(!bombVector.empty()) bombVector.pop_back();
    while(!bombFireVector.empty()) bombFireVector.pop_back();
    bombNum = 0;
    bombFireNum = 0;


}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
    ///������ը��
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
    ///�����ڱ�ըЧ��
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

    ///�������Ƿ���ը������ײ
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

