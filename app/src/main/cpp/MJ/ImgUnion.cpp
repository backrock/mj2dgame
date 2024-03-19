//class CImgUnion �������������ͼ��
//��һ��λͼ�л��ÿ��ͼ�μ���������ģ���λ����Ϣ��ͼ�εı���Ϊ���ڣ�
//ģ���Ӧ�ı���Ϊ���ף���Ӧͼ����Ч��Ϣ�Ĳ���Ϊ���ڡ�����ʱ���Ƚ�ģ��
//��Ŀ��DC�е�ָ��λ����������ٽ�ͼ����ָ��λ�û������
#include "StdAfx.h"
#include "ImgUnion.h"
#include "memory.h"

CImgUnion::CImgUnion(const char* csFile, int nNum, SDL_Rect*	prectSize)
{
	prectImgSize = NULL;

	pImg = LoadImageEx(csFile);

	nImgNum = nNum;
	prectImgSize = new SDL_Rect[nNum];
	memcpy((void *)prectImgSize,(void *)prectSize,nNum*(sizeof(SDL_Rect)));
}

CImgUnion::~CImgUnion()
{
	if (prectImgSize) delete prectImgSize;
}

void CImgUnion::BltImg(SDL_Surface *screen,int nImgCode,int nBltX,int nBltY)
{
	int nW = prectImgSize[nImgCode].w;
	int nH = prectImgSize[nImgCode].h;
	src.x = prectImgSize[nImgCode].x;
	src.y = prectImgSize[nImgCode].y;
	src.w = nW;
	src.h = nH;
	dst.x = nBltX;
	dst.y = nBltY;
	dst.w = nW;
	dst.h = nH;
	SDL_BlitSurface(pImg, &src, screen, &dst);
}
