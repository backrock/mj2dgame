#pragma once
#include "GameDef.h"
#include "Btn.h"
#include "../include/SDL_rect.h"
#include "../include/SDL_surface.h"

//////////////////////////////////////////////////////////////////////////////////
//面板信息结构
typedef struct SPanelInfo
{
	EGameID		egiID;					//程序状态
	SDL_Point		pntPos;					//位置

	SDL_Surface*	pSurface;
}SPanelInfo;

//////////////////////////////////////////////////////////////////////////////////
//程序状态结构
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

	CBtn		m_cBtnInfo[EBI_BTN_NUM];		///<按钮信息
	SStatusInfo	m_sStatusInfo[M_STATUS_NUM];	///<程序状态信息

	EGameID		m_egiGame;				///< 程序状态ID
	int			m_nBtnCode;				///< 当前按钮ID
	int			m_nKeySelBtn;			///< 当前键盘选择的按钮序号

	///改变程序状态
	void	ChangeGameStatus(EGameID egiID,bool bInOut);

	///画操作面板
	void	DrawPanel(SDL_Surface *screen);

	///画按钮
	void	DrawButton(SDL_Surface *screen);

	///处理按键消息
	void	KeyDown(unsigned char nChar);

	///处理按钮相关的鼠标移动消息
	bool	MouseMoveButton(SDL_Point point);

	///按下指定按钮
	virtual void PushButton(int nBtnCode);
};

