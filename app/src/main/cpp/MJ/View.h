#pragma once
#include "GameDef.h"
#include "Btn.h"
#include "../include/SDL_rect.h"
#include "../include/SDL_surface.h"

//////////////////////////////////////////////////////////////////////////////////
//�����Ϣ�ṹ
typedef struct SPanelInfo
{
	EGameID		egiID;					//����״̬
	SDL_Point		pntPos;					//λ��

	SDL_Surface*	pSurface;
}SPanelInfo;

//////////////////////////////////////////////////////////////////////////////////
//����״̬�ṹ
typedef struct SStatusInfo
{
	EGameID		egiID;
	int			nPanelNum;
	int			nBtnNum;
	int			nGroupNum;
	EButtonID	ebiID[M_MAX_STATUS_BTN_NUM];
	int			nGroupBegin[M_MAX_GROUP_NUM];
	int			nGroupSelect[M_MAX_GROUP_NUM];
	SPanelInfo	sPanelInfo[M_MAX_STATUS_PANEL_NUM];

	void AddPanel(int x,int y,SDL_Surface* pSur)
	{
		sPanelInfo[nPanelNum].pntPos.x = x;
		sPanelInfo[nPanelNum].pntPos.y = y;
		sPanelInfo[nPanelNum].pSurface = pSur;
		nPanelNum++;
	}
}SStatusInfo;

//////////////////////////////////////////////////////////////////////////////////
class CView
{
public:
	CView(void);
	~CView(void);
	bool	m_bExit;

protected:

	CBtn		m_cBtnInfo[EBI_BTN_NUM];		///<��ť��Ϣ
	SStatusInfo	m_sStatusInfo[M_STATUS_NUM];	///<����״̬��Ϣ

	EGameID		m_egiGame;				///< ����״̬ID
	int			m_nBtnCode;				///< ��ǰ��ťID
	int			m_nKeySelBtn;			///< ��ǰ����ѡ��İ�ť���

	///�ı����״̬
	void	ChangeGameStatus(EGameID egiID,bool bInOut);

	///���������
	void	DrawPanel(SDL_Surface *screen);

	///����ť
	void	DrawButton(SDL_Surface *screen);

	///��������Ϣ
	void	KeyDown(unsigned char nChar);

	///����ť��ص�����ƶ���Ϣ
	bool	MouseMoveButton(SDL_Point point);

	///����ָ����ť
	virtual void PushButton(int nBtnCode);
};

