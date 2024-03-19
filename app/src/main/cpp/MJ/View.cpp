#include "StdAfx.h"
#include "View.h"

CView::CView(void)
{
	m_bExit = false;
}

CView::~CView(void)
{
}

/*
����ĳ����״̬
bInOut:true����
*/
void CView::ChangeGameStatus(EGameID egiID,bool bInOut)
{
	for (int i=0; i<M_STATUS_NUM; i++)
	{
		if (egiID==m_sStatusInfo[i].egiID)
		{	//�ҵ�ָ������״̬

			//����ť
			for (int j=0; j<m_sStatusInfo[i].nBtnNum; j++)
			{
				m_cBtnInfo[m_sStatusInfo[i].ebiID[j]].Show(bInOut);
				m_cBtnInfo[m_sStatusInfo[i].ebiID[j]].Push(false);
			}

			int nCmdShow = SW_HIDE;
			if (bInOut)
			{
				nCmdShow = SW_SHOW;
				m_egiGame = egiID;
			}

			m_nKeySelBtn = 0;
			m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn]].Push(true);

			for (int i=0; i<m_sStatusInfo[m_egiGame].nGroupNum; i++)
			{
				m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_sStatusInfo[m_egiGame].nGroupSelect[i]]].Select(true);
			}

			return;
		}
	}
}

//�������ض�״̬����
void CView::DrawPanel(SDL_Surface *screen)
{
	for (int i=0; i<m_sStatusInfo[m_egiGame].nPanelNum; i++)
	{
		if (m_sStatusInfo[m_egiGame].sPanelInfo[i].pSurface)
		{
			SDL_Rect dst;
			dst.x = m_sStatusInfo[m_egiGame].sPanelInfo[i].pntPos.x;
			dst.y = m_sStatusInfo[m_egiGame].sPanelInfo[i].pntPos.y;
			dst.w = m_sStatusInfo[m_egiGame].sPanelInfo[i].pSurface->w;
			dst.h = m_sStatusInfo[m_egiGame].sPanelInfo[i].pSurface->h;
			SDL_BlitSurface(m_sStatusInfo[m_egiGame].sPanelInfo[i].pSurface, NULL, screen, &dst);
		}
	}
}

//����ť
void CView::DrawButton(SDL_Surface *screen)
{
	//�Ȼ���ť
	for (int i=0; i<EBI_BTN_NUM; i++)
	{
		m_cBtnInfo[i].DrawButton(screen);
	}
}

//true:����������ڵİ�ť�ı�
bool CView::MouseMoveButton(SDL_Point point)
{
	int nOldBtnCode = m_nBtnCode;

	m_nBtnCode = -1;

	//ȷ����ť��
	for (int i=0; i<EBI_BTN_NUM; i++)
	{
		if (m_cBtnInfo[i].MouseIn((SDL_Point)point))
		{
			m_nBtnCode = i;
		}
	}

	return (nOldBtnCode != m_nBtnCode);
}

void CView::PushButton(int nBtnCode) 
{
	//ѡ��״̬��ͬ�ķ��鰴ť�ı�״̬
	if (m_sStatusInfo[m_egiGame].nGroupNum>0)
	{
		for (int i=0; i<m_sStatusInfo[m_egiGame].nGroupNum-1; i++)
		{
			if (m_nKeySelBtn>=m_sStatusInfo[m_egiGame].nGroupBegin[i] && m_nKeySelBtn<m_sStatusInfo[m_egiGame].nGroupBegin[i+1])
			{
				m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_sStatusInfo[m_egiGame].nGroupSelect[i]]].Select(false);
				m_sStatusInfo[m_egiGame].nGroupSelect[i] = m_nKeySelBtn;
				m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_sStatusInfo[m_egiGame].nGroupSelect[i]]].Select(true);
			}
		}
	}

	switch (nBtnCode)
	{
	case EBI_START:			//��ʼ
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY,true);
		break;
	case EBI_QUIT:			//�ر�
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_QUIT,true);
		break;
	case EBI_BACK:			//����
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY,true);
		break;
	case EBI_HELP:			//����
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_HELP,true);
		break;
	case EBI_P_HELP:			//����
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY_HELP,true);
		break;
	//case EBI_CONTINUE:		//����
	//	ChangeGameStatus(m_egiGame,false);
	//	ChangeGameStatus(EGI_PLAY,true);
	//	break;
	case EBI_RETURN:
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_RETURN,true);
		break;
	case EBI_SETUP:			//����
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_SETUP,true);
		break;
	case EBI_R_YES:			//����ȷ��
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY_MENU,true);
		break;
	case EBI_R_NO:			//����ȡ��
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY,true);
		break;
	case EBI_S_YES:			//����ȷ��
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY_MENU,true);
		break;
	case EBI_S_NO:			//����ȡ��
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY_MENU,true);
		break;
	case EBI_YES:			//�˳�ȷ��
		m_bExit = true;
		//PostQuitMessage(0);
		break;
	case EBI_NO:			//�˳�ȡ��
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY_MENU,true);
		break;
	}
}

void CView::KeyDown(unsigned char nChar)
{
	if (m_egiGame==EGI_ENTER)
	{
		ChangeGameStatus(m_egiGame,false);
		ChangeGameStatus(EGI_PLAY_MENU,true);
		return;
	}

	m_nBtnCode = -1;
	switch(nChar)
	{
	case SDLK_LEFT:
	case SDLK_UP:
		m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn]].Push(false);
		if (m_nKeySelBtn>0)
		{
			m_nKeySelBtn--;
		}
		m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn]].Push(true);
		m_nBtnCode = m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn];
		break;
	case SDLK_RIGHT:
	case SDLK_DOWN:
		m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn]].Push(false);
		if (m_nKeySelBtn<m_sStatusInfo[m_egiGame].nBtnNum-1)
		{
			m_nKeySelBtn++;
		}
		m_cBtnInfo[m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn]].Push(true);
		m_nBtnCode = m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn];
		break;
	case SDLK_RETURN:
		if (m_egiGame==EGI_HELP)
		{
			ChangeGameStatus(EGI_HELP,false);
			ChangeGameStatus(EGI_PLAY_MENU,true);
		}
		else if (m_egiGame==EGI_PLAY_HELP)
		{
			ChangeGameStatus(EGI_PLAY_HELP,false);
			ChangeGameStatus(EGI_PLAY,true);
		}
		else
		{
			if (m_nKeySelBtn<m_sStatusInfo[m_egiGame].nBtnNum)
			{
				m_nBtnCode = m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn];
			}
			PushButton(m_sStatusInfo[m_egiGame].ebiID[m_nKeySelBtn]);
		}
		break;
	}
}