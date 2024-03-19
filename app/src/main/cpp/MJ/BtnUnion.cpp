//class CBtnUnion �� class CImgUnion ������������������İ�ť��
//��ʼ��ʱ�趨��ÿ����ť��λ�ü���ͬ״̬��Ӧ��ͼ�š�
//��������¼������ð�ť֮״̬����ָ����ťλ�û��Ƶ�ǰ״̬��Ӧ��ͼ�Ρ�

#include "StdAfx.h"
#include "BtnUnion.h"
#include "memory.h"

CBtnUnion::CBtnUnion(const char* csFile,
					int nNumImg,				// number of images
					 SDL_Rect*	prectSize,			// each image size
					int nNumBtn,				// number of button
					 SDL_Rect* rectBtn,				// each button left-top point
					BtnImgCode* sImgCodeBtn,	// image code in CImgUnion of button;
					int *nStatusBtn):			// the button begining status;
	CImgUnion(csFile, nNumImg, prectSize)
{
	nBtnNum = nNumBtn;
	nBtnStatus = new int[nBtnNum];
	rectBtnLocate = new SDL_Rect[nBtnNum];
	sBtnImgCode = new BtnImgCode[nBtnNum];
	memcpy((void *)rectBtnLocate,(void *)rectBtn,nBtnNum*(sizeof(SDL_Rect)));
	memcpy((void *)sBtnImgCode,(void *)sImgCodeBtn,nBtnNum*(sizeof(BtnImgCode)));
	memcpy((void *)nBtnStatus,(void *)nStatusBtn ,nBtnNum*(sizeof(int)));
}

CBtnUnion::~CBtnUnion()
{
	CImgUnion::~CImgUnion();
	if (nBtnStatus) delete nBtnStatus;
	if (rectBtnLocate) delete rectBtnLocate;
	if (sBtnImgCode) delete sBtnImgCode;
}

void CBtnUnion::SetBtnStatus(int nBtnCode,int nStatus)
{
	nBtnStatus[nBtnCode] = nStatus;
}

bool CBtnUnion::MouseMove(SDL_Point ptMouse)
{
	bool ifChange = false;
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]!=DISABLE&&nBtnStatus[i]>=0)
		{
			if (SDL_PointInRect(&ptMouse,rectBtnLocate+i))
			{
				if (nBtnStatus[i]!=PUSHDOWN)
				{
					if (nBtnStatus[i]!=MOUSEOVER)
					{
						nBtnStatus[i] = MOUSEOVER;
						ifChange = true;
					}
				}
			}
			else
			{
				if (nBtnStatus[i]!=NORMAL)
				{
					nBtnStatus[i] = NORMAL;
					ifChange = true;
				}
			}
		}
	}
	return ifChange;
}

bool CBtnUnion::IfBtnPush()
{
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]==MOUSEOVER)
		{
			return true;
		}
	}
	return false;
}

bool CBtnUnion::IfBtnEnable()
{
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]!=DISABLE)
		{
			return true;
		}
	}
	return false;
}

int CBtnUnion::SelFirst()
{
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]!=DISABLE && nBtnStatus[i]>=0 && nBtnStatus[i]!=PUSHDOWN)
		{
			nBtnStatus[i] = MOUSEOVER;
			return i;
		}
	}
	return -1;
}

int CBtnUnion::SelLast()
{
	for (int i=nBtnNum-1; i>=0; i--)
	{
		if (nBtnStatus[i]!=DISABLE && nBtnStatus[i]>=0 && nBtnStatus[i]!=PUSHDOWN)
		{
			nBtnStatus[i] = MOUSEOVER;
			return i;
		}
	}
	return -1;
}

//return:
//>0:Push Key
//-1:
int CBtnUnion::KeyReturn()
{
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]==MOUSEOVER)
		{
			nBtnStatus[i] = PUSHDOWN;
			return i;
		}
	}
	return -1;
}

//return:
//>0:Push Key
//-1:
int CBtnUnion::KeyMove(unsigned char nChar)
{
	int iNow,iLast,iNext,iFirst,iEnd;
	iNow = -1;
	iFirst = -1;
	iEnd = -1;
	iLast = -1;
	iNext = -1;
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]==MOUSEOVER)
		{
			nBtnStatus[i] = NORMAL;
			iNow = i;
			iNext = -2;
		}
		else if (nBtnStatus[i]!=DISABLE && nBtnStatus[i]>=0 && nBtnStatus[i]!=PUSHDOWN)
		{
			if (iNow<0)	iLast = i;
			if (iFirst<0) iFirst = i;
			if (iNext==-2) iNext = i;
			iEnd = i;
		}
	}
	
	if (iNow<0)
	{	//û�е�ǰѡ��
		if (nChar==SDLK_UP)
		{	//�������һ��
			iNow = iEnd;
		}
		else if (nChar==SDLK_DOWN)
		{	//���ҵ�һ��
			iNow = iFirst;
		}
	}
	else
	{
		if (nChar==SDLK_UP)
		{	//������һ��Ϊ��ѡ
			iNow = iLast;
		}
		else if (nChar==SDLK_DOWN)
		{	//������һ��Ϊ��ѡ
			iNow = iNext;
		}
	}

	if (iNow>=0) 
	{
		nBtnStatus[iNow] = MOUSEOVER;
	}
	return iNow;
}

int CBtnUnion::MouseLBDown(SDL_Point ptMouse)
{
	bool ifChange = false;
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]==MOUSEOVER)
		{
			nBtnStatus[i] = PUSHDOWN;
			return i;
		}
	}
	return -1;
}

int CBtnUnion::BtnUp()
{
	for (int i=0; i<nBtnNum; i++)
	{
		if (nBtnStatus[i]==MOUSEOVER)
		{
			nBtnStatus[i] = NORMAL;
			return i;
		}
	}
	return -1;
}

void CBtnUnion::DrawBtn(SDL_Surface *screen)
{
	for (int i=0; i<nBtnNum; i++)
	{
		int nImgCode;
		switch (nBtnStatus[i])
		{
		case NORMAL:
			nImgCode = sBtnImgCode[i].nNormal;
			break;
		case MOUSEOVER:
			nImgCode = sBtnImgCode[i].nMouseOver;
			break;
		case PUSHDOWN:
			nImgCode = sBtnImgCode[i].nPushDown;
			break;
		case DISABLE:
			nImgCode = sBtnImgCode[i].nDisable;
			break;
		default:
			nImgCode = -1;
		}
		if (nImgCode>=0)
			CImgUnion::BltImg(screen,nImgCode,rectBtnLocate[i].x,rectBtnLocate[i].y);
	}
}

