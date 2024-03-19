#include "StdAfx.h"
#include "Btn.h"

CBtn::CBtn(void)
{
	m_csSpan[0] = 0;
}

CBtn::~CBtn(void)
{
}

//��ʼ����ť����
void CBtn::Init(int left,int top,int width,int height, char* csFileBase,char* csSpan)
{
	//λ��
	m_rectPos.x = left;
	m_rectPos.y = top;
	m_rectPos.w = width;
	m_rectPos.h = height;

	//λͼ�ļ����Ļ������֣��������ļ���Ϊ����N.png(����)|D.png(����)|G.png(��Ч)
	if (csFileBase)
	{
		char	csFile[MAX_PATH];
		strcpy(csFile,csFileBase);
		char* p = csFile+strlen(csFileBase);
		strcpy(p,"N.png");
		m_imgNormal = LoadImageEx(csFile);
		strcpy(p,"D.png");
		m_imgDown = LoadImageEx(csFile);
		strcpy(p,"S.png");
		m_imgSelect = LoadImageEx(csFile);
		strcpy(p,"I.png");
		m_imgInvalid = LoadImageEx(csFile);
	}

	//��ʾ�ִ�
	if (csSpan)
	{
		strcpy(m_csSpan,csSpan);
	}
	
	m_bShow = false;					//�Ƿ���ʾλͼ
	m_bActive = false;				//�Ƿ񼤻�
	m_bPushDown = false;				//�Ƿ񱻰���
	m_bSelect = false;				//�Ƿ�ѡ��
}

//У��������
void CBtn::AdjustArea(int nOffX,int nOffY)
{
	m_rectPos.x = m_rectPos.x+nOffX;
	m_rectPos.y = m_rectPos.y+nOffY;
}

//�ж�����Ƿ��ڰ�ť��
bool CBtn::MouseIn(SDL_Point point)
{
	if (!m_bShow) return false;

	m_bPushDown = false;
	if (m_bActive)
	{
		SDL_Rect rectPos;
		rectPos.x = m_rectPos.x;
		rectPos.y = m_rectPos.y;
		rectPos.w = m_rectPos.w;
		rectPos.h = m_rectPos.h;

		if (SDL_PointInRect(&point,&rectPos))
		{
			m_bPushDown = true;
			return true;
		}
	}
	else
	{
		return false;
	}
}

//����ť
void CBtn::DrawButton(SDL_Surface *screen)
{
	if (!m_imgNormal) return;
	if (!m_bShow) return;

	SDL_Rect src;
	SDL_Rect dst;

	src.x = 0;
	src.y = 0;
	src.w = m_imgNormal->w;
	src.h = m_imgNormal->h;
	dst.x = m_rectPos.x;
	dst.y = m_rectPos.y;
	dst.w = m_imgNormal->w;
	dst.h = m_imgNormal->h;
	
	if (!m_bActive && m_imgInvalid)
	{
		SDL_BlitSurface(m_imgInvalid, NULL, screen, &dst);
	}
	else 
	{
		if (m_bSelect && m_imgSelect)
		{
			SDL_BlitSurface(m_imgSelect, NULL, screen, &dst);
		}
		else if (m_imgNormal)
		{
			SDL_BlitSurface(m_imgNormal, NULL, screen, &dst);
		}
		if (m_bPushDown && m_imgDown)
		{
			SDL_BlitSurface(m_imgDown, NULL, screen, &dst);
		}
	}
}

//�Ƿ���ʾ��ť
void CBtn::Show(bool bShow)
{
	m_bShow = bShow;
	if (m_bShow)
	{
		m_bActive = true;
	}
}

//�Ƿ񼤻ť
void CBtn::Enable(bool bActive)
{
	m_bActive = bActive;
}

//�趨��ť��ʾ��Ϣ
void CBtn::SetSpan(char* csSpan)
{
	strcpy(m_csSpan,csSpan);
}
