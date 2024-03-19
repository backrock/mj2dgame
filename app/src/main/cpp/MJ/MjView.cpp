// mjiangView.cpp : implementation of the CMjView class
//
#include "StdAfx.h"
#include "MjView.h"

/*
���̲�������
���ƺ�׼������״̬:
	���Ҽ��ƶ����,ȷ�ϼ�ѡ��һ����,��������Ѿ���ѡ�����,�����趨�µı�ѡ����
	�������������ʱ,�Ҽ�����˵�ѡ��
	���¼�����˵�ѡ��
	�г����ܵȰ�ťʱ,��ѡ��״̬��ȷ�ϼ�,���������ܵ�
�˵�ѡ��״̬:
	����ص�����״̬
	���¼�ѡ��˵���
	���³��Ƽ��������ѡ��״̬
	������Լ������и��ư��¸��Ƽ��������ѡ��״̬����������ܣ�����ѡ��
	�������Ƽ���ֱ��������ƣ�����ѡ��
����ѡ��״̬:
	���¼���Ч
	���Ҽ�ѡ��Ҫ�Ե����飬�����ѡ��Ĭ�ϣ���������
����ѡ��״̬:
	���¼���Ч
	���Ҽ�ѡ��Ҫ�ܵ����飬�����ѡ��Ĭ�ϣ���������
*/

//�����Ʒ���ʾ
//��ʾ���Ʒ�
//����������ͼ
//Ȧ����˵��
//����������޷���

/////////////////////////////////////////////////////////////////////////////
// CMjView
int ZHANGSHU, MAXGNUM, MAXGNUMINHAND,MAXSHU;

/////////////////////////////////////////////////////////////////////////////
#define  PEDSIZE	30

#define  SCALEX     225
#define  SCALEY     225
	
#define  MJWIDTH	25
#define  MJHITH		34

int nMjImgW = MJWIDTH-3;
int nMjImgH = MJHITH-3;

SDL_Point pntInHand[4] = {{77,440},{440,375},{45,5},{6,405}};			//4�������Ƶ���ʼλ��
SDL_Point pntWeiZhua[4] = {{75,404},{406,380},{8,39},{40,445}};			//4����δץ�Ƶ���ʼλ��
SDL_Point pntChiGangSel = {510,360};									//�Ը���ѡ��λ��
SDL_Point pntSaizi = {470,85};											//ɫ��λ��
SDL_Point pTokenPoint[4] = {{222,278},{285,221},{220,160},{160,217}};	//��ǰ���Ʒ���ʾλ��

//4�Һ�����λ��
SDL_Point pntOutHand[4][24] = {
{{115,365},{138,365},{161,365},{184,365},{207,365},{230,365},{253,365},{276,365},{299,365},{322,365},{345,365},
{150,330},{173,330},{196,330},{219,330},{242,330},{265,330},{288,330},{311,330},
{185,295},{208,295},{231,295},{254,295},{277,295}},
//
{{370,115},{370,138},{370,161},{370,184},{370,207},{370,230},{370,253},{370,276},{370,299},{370,322},{370,345},
{335,150},{335,173},{335,196},{335,219},{335,242},{335,265},{335,288},{335,311},
{300,185},{300,208},{300,231},{300,254},{300,277}},
//
{{115,72},{138,72},{161,72},{184,72},{207,72},{230,72},{253,72},{276,72},{299,72},{322,72},{345,72},
{150,107},{173,107},{196,107},{219,107},{242,107},{265,107},{288,107},{311,107},
{185,142},{208,142},{231,142},{254,142},{277,142}},
//
{{80,115},{80,138},{80,161},{80,184},{80,207},{80,230},{80,253},{80,276},{80,299},{80,322},{80,345},
{115,150},{115,173},{115,196},{115,219},{115,242},{115,265},{115,288},{115,311},
{150,185},{150,208},{150,231},{150,254},{150,277}},
};

//
void* hInstance;

#define SND_ASYNC  0x0001
void sndPlaySound(const char* path,unsigned char type){

}
/////////////////////////////////////////////////////////////////////////////
// CMjView construction/destruction

CMjView::CMjView()///new()
{
	SDL_Surface* pSur_start = LoadImageEx("enter.jpg");

	SDL_Surface* pSur_menu = LoadImageEx("menu.png");
	SDL_Surface* pSur_return = LoadImageEx("return.png");
	SDL_Surface* pSur_quit = LoadImageEx("quit.png");
	SDL_Surface* pSur_setup = LoadImageEx("setup.png");
	SDL_Surface* pSur_win = LoadImageEx("win.png");
	SDL_Surface* pSur_lose = LoadImageEx("lose.png");
	SDL_Surface* pSur_draw = LoadImageEx("draw.png");
	SDL_Surface* pSur_help = LoadImageEx("help.png");
	SDL_Surface* pSur_phelp = LoadImageEx("phelp.png");

	//////////////////////////////////////////////////////////////////////////////////
	//��ť��Ϣ
	m_cBtnInfo[EBI_START].Init(500,160,129,31,"btnStart");
	m_cBtnInfo[EBI_SETUP].Init(500,200,129,31,"btnSetup");
	m_cBtnInfo[EBI_HELP].Init(500,240,129,31,"btnHelp");
	//m_cBtnInfo[EBI_RECODE].Init(500,280,129,31,"btnRecode");
	m_cBtnInfo[EBI_QUIT].Init(500,280,129,31,"btnQuit");

	m_cBtnInfo[EBI_PLAY].Init(500,400,129,31,"");
	m_cBtnInfo[EBI_P_HELP].Init(500,400,129,31,"btnHelp");
	m_cBtnInfo[EBI_RETURN].Init(490,440,129,31,"btnReturn");

	m_cBtnInfo[EBI_YES].Init(150,280,72,25,"btnYes");
	m_cBtnInfo[EBI_NO].Init(250,280,72,25,"btnNo");

	m_cBtnInfo[EBI_R_YES].Init(150,260,72,25,"btnYes");
	m_cBtnInfo[EBI_R_NO].Init(250,260,72,25,"btnNo");

	m_cBtnInfo[EBI_S_YES].Init(150,310,72,25,"btnYes");
	m_cBtnInfo[EBI_S_NO].Init(250,310,72,25,"btnNo");
	m_cBtnInfo[EBI_S_LEVEL1].Init(130,210,60,21,"btnSM");
	m_cBtnInfo[EBI_S_LEVEL2].Init(218,210,60,21,"btnSM");
	m_cBtnInfo[EBI_S_LEVEL3].Init(305,210,60,21,"btnSM");
	m_cBtnInfo[EBI_S_SND_OPEN].Init(130,270,60,21,"btnSM");
	m_cBtnInfo[EBI_S_SND_CLOSE].Init(218,270,60,21,"btnSM");

	//////////////////////////////////////////////////////////////////////////////////
	//����״̬��Ϣ
	SStatusInfo sStatusInfo1[M_STATUS_NUM] =
	{
		{EGI_ENTER,0,0,0},
		{EGI_SETUP,0,7,3,{EBI_S_LEVEL1,EBI_S_LEVEL2,EBI_S_LEVEL3,EBI_S_SND_OPEN,EBI_S_SND_CLOSE,EBI_S_YES,EBI_S_NO},{0,3,5},{1,3,5}},
		{EGI_PLAY,0,3,0,{EBI_PLAY,EBI_P_HELP,EBI_RETURN}},
		{EGI_PLAY_MENU,0,4,0,{EBI_START,EBI_SETUP,EBI_HELP,EBI_QUIT}},
		{EGI_RETURN,0,2,0,{EBI_R_YES,EBI_R_NO}},
		{EGI_HELP,0,0,0},
		{EGI_PLAY_HELP,0,0,0},
		{EGI_END_WIN,0,0,0},
		{EGI_END_LOSE,0,0,0},
		{EGI_END_DRAW,0,0,0},
		{EGI_QUIT,0,2,0,{EBI_YES,EBI_NO}},
	};
	memcpy(m_sStatusInfo,sStatusInfo1,sizeof(SStatusInfo)*M_STATUS_NUM);

	m_sStatusInfo[EGI_ENTER].AddPanel(0,0,pSur_start);

	m_sStatusInfo[EGI_PLAY_MENU].AddPanel(500,150,pSur_menu);

	m_sStatusInfo[EGI_RETURN].AddPanel(0,0,pSur_return);

	m_sStatusInfo[EGI_QUIT].AddPanel(0,0,pSur_quit);

	m_sStatusInfo[EGI_SETUP].AddPanel(0,0,pSur_setup);

	m_sStatusInfo[EGI_HELP].AddPanel(0,0,pSur_help);
	m_sStatusInfo[EGI_PLAY_HELP].AddPanel(0,0,pSur_phelp);

	ChangeGameStatus(EGI_ENTER,true);

	///////////////////////////////////////////////////////////////////////////////////////
	//��ʼ������
	SDL_Rect r[11] = {{0,0,21,21},{22,0,21,21},{44,0,21,21},{66,0,21,21},{88,0,21,21},{110,0,21,21},
				{0,22,28,28},{0,51,28,28},{0,80,28,28},{0,109,28,28},{29,22,49,38}};
	m_pIuSaizi = new CImgUnion("Saizi.png",11,r);

	//��ʼ����ť
	SDL_Rect r2[20] = {{0,0,138,30},{0,31,138,30},{0,62,138,30},{0,93,138,30},{0,124,138,30},
					{142,0,138,30},{142,31,138,30},{142,62,138,30},{142,93,138,30},{142,124,138,30},
					{284,0,138,30},{284,31,138,30},{284,62,138,30},{284,93,138,30},{284,124,138,30},
					{426,0,138,30},{426,31,138,30},{426,62,138,30},{426,93,138,30},{426,124,138,30}};
	SDL_Rect rb[5] = {{490,160,150,30},{490,200,150,30},{490,240,150,30},{490,280,150,30},{490,320,150,30}};
	BtnImgCode ic[5] = {{0,5,10,15},{1,6,11,16},{2,7,12,17},{3,8,13,18},{4,9,14,19}};
	int ns[5] = {NORMAL,NORMAL,NORMAL,NORMAL,NORMAL};//{DISABLE,DISABLE,DISABLE,DISABLE,DISABLE};
	m_pBuMj = new CBtnUnion("PlayBtn.png",20,r2,5,rb,ic,ns);
	
	//��ʾ������Ϣ
	SDL_Rect r3[4] = {{100,0,199,100},{200,0,299,100},{300,0,399,100},{400,0,499,100}};
	m_pIuCenter = new CImgUnion("Center.png",4,r3);

	m_pSfCard = LoadImageEx("Paimian.png");
	m_pSfBoard = LoadImageEx("play.jpg");
	m_pSfText = LoadImageEx("text.png");

	///////////////////////////////////////////////////////////////////////////////////////
	ZHANGSHU = 17;
	MAXGNUM = ZHANGSHU/3+1;		//���ό��ӹ�6�M��
	MAXGNUMINHAND = ZHANGSHU/3;	//5�M�����������5�M����
	MAXSHU = (ZHANGSHU/3+1)*3;	///?

	m_nLevel = 2;
	m_bSndState = true;

	for(int i=0;i<5;i++)		
	{
		nbButtonStat[i] = DISABLED;
	}
	nbGuzi1 = 1; nbGuzi2 = 1;
	nbMjSelected = INVALID;
	isButtonValid = false;
	isViewDef = false;
	isLiuJu = false;
	isViewOther = false;
	bTimerStart = false;

	New();
}

CMjView::~CMjView()
{
	OnFreeSurface();
}
void CMjView::OnFreeSurface() {
	if(m_pSfCard)SDL_FreeSurface(m_pSfCard);
	m_pSfCard = 0;
	if(m_pSfBoard)SDL_FreeSurface(m_pSfBoard);
	m_pSfBoard = 0;
	if(m_pSfText)SDL_FreeSurface(m_pSfText);
	m_pSfText = 0;
	delete m_pIuSaizi; m_pIuSaizi = 0;
	delete m_pIuCenter; m_pIuCenter = 0;
	delete m_pBuMj; m_pBuMj = 0;
}
/////////////////////////////////////////////////////////////////////////////
// CMjView drawing
void CMjView::OnDraw(SDL_Window *window)
{
	int i,j;
	SDL_Surface* screen = SDL_GetWindowSurface(window);
	if (screen == NULL) {
		/*fprintf(stderr, "Couldn't set display mode: %s\n",
			SDL_GetError());*/
		return;
	}

	//	BYTE nbPostCode;
	//	nbPostCode = m_cMJ.GetPostCode();

	//������
	src.w = M_WIN_WIDTH;
	src.h = M_WIN_HEIGHT;
	dst.w = M_WIN_WIDTH;
	dst.h = M_WIN_HEIGHT;
	src.x = 0;
	src.y = 0;
	dst.x = 0;
	dst.y = 0;
	SDL_BlitSurface(m_pSfBoard, &src, screen, &dst);

	//����������ͼ
	//m_pIuCenter->BltImg(screen,nbWindDir,190,190);
	m_pIuCenter->BltImg(screen,0,190,190);

	//��ׯ��ͼ
	src.w = PEDSIZE;
	src.h = PEDSIZE;
	dst.w = PEDSIZE;
	dst.h = PEDSIZE;
	src.x = SCALEX+3*MJHITH+1 + m_cMJ.GetZhuangjia()*PEDSIZE;
	src.y = 0;
	dst.x = pntSaizi.x+80;
	dst.y = pntSaizi.y-40;
	SDL_BlitSurface(m_pSfCard, &src, screen, &dst);

	//������ͼ
	m_pIuSaizi->BltImg(screen,nbGuzi1-1,pntSaizi.x+60,pntSaizi.y);
	m_pIuSaizi->BltImg(screen,nbGuzi2-1,pntSaizi.x+100,pntSaizi.y);

	//����ǰ���Ʒ�
	BYTE nbNowPlayer = m_cMJ.GetNowPlayer();
	m_pIuSaizi->BltImg(screen,10,pTokenPoint[nbNowPlayer].x,pTokenPoint[nbNowPlayer].y);
	
	//��δץ���Ƶ�ͼ
	PasteWeiZhua(screen);

	//��������Ƶ�ͼ
	PasteOutHand(screen);

	//��״̬��ť
	PasteButton(screen);

	//���齫��ͼ
	PasteMJDiTu(screen);

	///////////////////////////////////////////////////////////////////////////
	int tmpx,tmpy,textw,texth;
	tmpx = 500;tmpy = 160; textw = 120; texth = 31;
	if(m_cMJ.GetStatus() == WANZHUANG)
	{
		if(isLiuJu == true)
		{	//��������
			src.w = 120;
			src.h = texth;
			dst.w = 120;
			dst.h = texth;
			src.x = 120;
			src.y = 0;
			dst.x = tmpx;
			dst.y = tmpy;
			SDL_BlitSurface(m_pSfText, &src, screen, &dst);
		}
		else
		{
			BYTE nbPaiXin[PAIXINGSUM];
			int nTaiShu = m_cMJ.GetPaiXin(nbPaiXin);
			for(i=0;i<PAIXINGSUM;i++)
			{
				if(nbPaiXin[i] == 1)
				{	//����
					src.w = 120;
					src.h = texth;
					dst.w = 120;
					dst.h = texth;
					src.x = (i%5)*120;
					src.y = (i/5+1)*texth;
					dst.x = tmpx;
					dst.y = tmpy;
					SDL_BlitSurface(m_pSfText, &src, screen, &dst);
					tmpy += texth;
				}
			}

			//��̨��
			src.w = 160;
			src.h = texth;
			dst.w = 160;
			dst.h = texth;
			src.x = 240;
			src.y = 0;
			dst.x = tmpx;
			dst.y = tmpy;
			SDL_BlitSurface(m_pSfText, &src, screen, &dst);

			int n[3],j = 0;;
			n[0] = nTaiShu/100; n[1] = (nTaiShu%100)/10; n[2] = nTaiShu%10;
			tmpx += 100;
			for (int i=0; i<3; i++)
			{
				if (j>0 || n[i]>0)
				{
					src.w = 16;
					src.h = texth;
					dst.w = 16;
					dst.h = texth;
					src.x = 436+n[i]*16;
					src.y = 0;
					dst.x = tmpx+j*16;
					dst.y = tmpy;
					j++;
					SDL_BlitSurface(m_pSfText, &src, screen, &dst);
				}
			}
		}
	}
	else if (m_egiGame==EGI_PLAY)// && m_cMJ.GetStatus() == DAPAI)
	{	//���ư�ť
		m_pBuMj->DrawBtn(screen);
	}

	//�������ض�״̬����
	DrawPanel(screen);

	//��ʾ��ť
	//UpdateButton();
	DrawButton(screen);

    // ˢ����Ļ�ı仯����
   // SDL_UpdateRect(screen, 0,0,0,0);	//SDL_UpdateWindowSurfaceRects
	// 刷新窗体，让与窗体关联的screen中的数据能够显示出来。
	//SDL_FreeSurface(m_pSfText);
   SDL_UpdateWindowSurface(window); 
}

void CMjView::OnLButtonDown(SDL_Point point)
{
	PushButton(m_nBtnCode);

	if (m_egiGame==EGI_PLAY)
	{
		OnMouseMove(point);

		m_nMjBtnCode = -1;
		BYTE nbStatus = m_cMJ.GetStatus();
		BYTE nbPlayer = m_cMJ.GetNowPlayer();
		if(nbStatus == DAPAI && nbPlayer == 0)
		{
			m_nMjBtnCode = m_pBuMj->MouseLBDown(point);
		}

		MjAction();
		if (m_nMjBtnCode>=0) DoMjBotton();
	}
}

void CMjView::PushButton(int nBtnCode) 
{
	CView::PushButton(m_nBtnCode);
	if (m_nBtnCode==EBI_START)
	{
		New();
	}
	else if (m_nBtnCode==EBI_S_YES)
	{
		Setup();
	}
}

void CMjView::OnLButtonUp(SDL_Point point)
{
}

void CMjView::OnRButtonDown(SDL_Point point)
{
}

void CMjView::PlaySnd(ESndType est)
{
	if (m_bSndState)
	{
		switch (est)
		{
		case ESND_MENU_MOVE:
			sndPlaySound("snd\\move.wav",SND_ASYNC);
			break;
		case ESND_MENU_SELECT:
			sndPlaySound("snd\\beep.wav",SND_ASYNC);
			break;
		case ESND_CHESS_MOVE:
			sndPlaySound("snd\\move.wav",SND_ASYNC);
			break;
		case ESND_CHESS_SELECT:
			sndPlaySound("snd\\down.wav",SND_ASYNC);
			break;
		case ESND_CHESS_OUT:
			sndPlaySound("snd\\turn.wav",SND_ASYNC);
			break;
		}
	}
}

void CMjView::OnKeyDown(unsigned char nChar)
{
	if (m_egiGame!=EGI_PLAY)
	{
		KeyDown(nChar);
		//if(nChar == 118 || nChar == 86)
		//{
		//	if(isViewOther == true) isViewOther = false;
		//	else isViewOther = true;
		//}
	}

	if (m_egiGame==EGI_PLAY)
	{
		if (m_nKeySelBtn>0)
		{	//�˵���ť
			if (nChar==SDLK_RETURN  || nChar==SDLK_DOWN)
			{
				KeyDown(nChar);
			}
			else if (nChar==SDLK_UP)
			{
				if (m_nKeySelBtn>1) 
				{
					KeyDown(nChar);
				}
				else if (m_pBuMj->IfBtnEnable())
				{
					KeyDown(nChar);
					m_pBuMj->SelLast();
				}
			}
			else if (nChar==SDLK_LEFT)
			{
				ChangeGameStatus(m_egiGame,true);
			}
		}
		else if (m_nKeySelBtn==0)
		{
			m_nMjBtnCode = -1;
			if (m_cMJ.GetNowPlayer()== 0)
			{
				if (m_pBuMj->IfBtnEnable() && nChar==SDLK_LEFT)
				{	//�ڳ���ťѡ��ʱ���������ѡ��
					ChangeGameStatus(m_egiGame,true);
					m_pBuMj->BtnUp();
				}

				GetSelectRect();
				BYTE nbPlayStat = m_cMJ.GetNowPlayStat();
				int nMaxSelectPlay = (rDapai.w)/nMjImgW;
				int nMaxSelectBtn = 0;
				if (nbButtonStat[GANGPAI-1] == PUSHED)
				{
					nMaxSelectBtn = (rGangpai.w)/MJWIDTH;;
					m_nbSelecteArea = SEL_GANGPAI;
				}
				else if( nbButtonStat[CHIPAI-1] == PUSHED )
				{
					nMaxSelectBtn = (rChipai.w)/(nMjImgW*2+5);;
					m_nbSelecteArea = SEL_CHIPAI;
				}
				else if (nbPlayStat == CHUPAI || nbPlayStat == XUANPAI) 
				{
					m_nbSelecteArea = SEL_DAPAI;
				}

				if ((m_nbSelecteArea==SEL_CHIPAI||m_nbSelecteArea==SEL_GANGPAI) && (nChar==SDLK_UP||nChar==SDLK_DOWN))
				{
					return;
				}

				if (nChar==SDLK_RETURN)
				{
					m_nMjBtnCode = m_pBuMj->KeyReturn();
					if (m_nMjBtnCode==0)
					{
						m_nbSelecteArea = SEL_CHIPAI;
					}
					else if (m_nMjBtnCode==2)
					{
						m_nbSelecteArea = SEL_GANGPAI;
					}
					MjAction();
					if (m_nMjBtnCode>=0) DoMjBotton();
				}
				else if (nChar==SDLK_UP)
				{	//�ƶ�MJ��ť
					if (m_pBuMj->KeyMove(nChar))
					{
						m_pBuMj->SelFirst();
					}
				}
				else if (nChar==SDLK_DOWN)
				{	//�ƶ�MJ��ť
					if (m_pBuMj->KeyMove(nChar)<0)
					{
						m_ncSelectedNum = nMaxSelectPlay-1;
						nbMjSelected = -1;
						KeyDown(SDLK_RIGHT);
					}
				}
				else if (!m_pBuMj->IfBtnPush())
				{
					if (nChar==SDLK_LEFT)
					{
						if (m_ncSelectedNum>0) 
						{
							m_ncSelectedNum--;
						}
					}
					else if (nChar==SDLK_RIGHT) 
					{
						if (m_nbSelecteArea==SEL_DAPAI)
						{
							if (m_ncSelectedNum<nMaxSelectPlay-1)
							{
								m_ncSelectedNum++;
							}
							else
							{
								m_ncSelectedNum = nMaxSelectPlay-1;
								nbMjSelected = -1;
								if (m_pBuMj->KeyMove(SDLK_DOWN)<0)
								{
									KeyDown(SDLK_DOWN);
								}
							}
						}
						else if ((m_nbSelecteArea==SEL_CHIPAI||m_nbSelecteArea==SEL_GANGPAI) && m_ncSelectedNum<nMaxSelectBtn-1)
						{
							m_ncSelectedNum++;
						}
					}
				}
			}
			else
			{
				MjAction();
			}
		}
	}
}

void CMjView::OnMouseMove(SDL_Point point)
{
	// TODO: Add your message handler code here and/or call default
	if (MouseMoveButton(point))
	{
	}
	if (m_egiGame==EGI_PLAY)
	{
		if (m_cMJ.GetNowPlayer()== 0)
		{
			if (m_pBuMj->MouseMove(point))
			{
			}

			GetSelectRect();
			//m_ncSelectedNum = -1;
			m_nbSelecteArea = SEL_NONE;
			BYTE nbPlayStat = m_cMJ.GetNowPlayStat();
			if (nbButtonStat[GANGPAI-1] == PUSHED)
			{
				if (SDL_PointInRect(&point,&rGangpai))
				{
					m_ncSelectedNum = (point.x-rGangpai.x)/MJWIDTH;
					m_nbSelecteArea = SEL_GANGPAI;
				}
			}
			else if( nbButtonStat[CHIPAI-1] == PUSHED )
			{
				if (SDL_PointInRect(&point,&rChipai))
				{
					m_ncSelectedNum = (point.x-rChipai.x)/(nMjImgW*2+5);
					m_nbSelecteArea = SEL_CHIPAI;
				}
			}
			else if (nbPlayStat == CHUPAI || nbPlayStat == XUANPAI) 
			{
				if (SDL_PointInRect(&point,&rDapai))
				{
					m_ncSelectedNum = (point.x-rDapai.x)/nMjImgW;
					m_nbSelecteArea = SEL_DAPAI;
				}
			}
		}
	}
}

void CMjView::OnTimer() 
{
	if (!bTimerStart) return;

	BYTE nbTmp[5],nbPlayer,nbStatus;

	nbStatus = m_cMJ.GetStatus();
	if(nbStatus == QIPAI)
	{
		MjAction();
	}
	else if(nbStatus == BUHUA)
	{
		MjAction();
	}
//		else if(nbStatus == WANZHUANG )
//		{
//			MjAction();
//		}
	else if(nbStatus == DAPAI && m_cMJ.player[0].GetTingpaiStat() == 2)
	{
		nbPlayer = m_cMJ.GetNowPlayer();
		if(nbPlayer == 0)
		{
			for(int i=0;i<5;i++) nbTmp[i] = DISABLED;
			m_cMJ.GetButtonStat(nbTmp);
			if(nbTmp[HUPAI-1] != ENABLED) MjAction();
		}
		else  MjAction();
	}
	else if(nbStatus == DAPAI && m_cMJ.GetNowPlayer() != 0)
	{
		MjAction();
	}
	else if(nbStatus == DAPAI && m_cMJ.GetNowPlayer() == 0 && (m_cMJ.GetNowPlayStat() == MOPAI || m_cMJ.GetNowPlayStat() == BUPAI))
	{
		MjAction();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

void CMjView::Setup() 
{
	m_nLevel = m_sStatusInfo[EGI_SETUP].nGroupSelect[0];			//0~2
	m_bSndState = 4-m_sStatusInfo[EGI_SETUP].nGroupSelect[1];		//1~0
	New();
}

void CMjView::New() 
{
	m_cMJ.Begin(m_nLevel);
	srand(0);
	nbWindDir = rand()%4;
	bTimerStart = true;
}

void CMjView::OnOptionDefine() 
{
	//CDefineTaiShu taishu;
	//if(ZHANGSHU==14) taishu.m_taishu = 0;
	//else	taishu.m_taishu = 1;

	//taishu.DoModal();

	//if(taishu.m_taishu == 0 && ZHANGSHU == 17)
	//{
	//	ZHANGSHU = 14;
	//	MAXGNUM = ZHANGSHU/3+1;
	//	MAXGNUMINHAND = ZHANGSHU/3;
	//	MAXSHU = (ZHANGSHU/3+1)*3;
	//	OnFileNew();
	//}else if(taishu.m_taishu == 1 && ZHANGSHU == 14)
	//{
	//	ZHANGSHU = 17;
	//	MAXGNUM = ZHANGSHU/3+1;
	//	MAXGNUMINHAND = ZHANGSHU/3;
	//	MAXSHU = (ZHANGSHU/3+1)*3;
	//	OnFileNew();
	//}
}

void CMjView::SetRect(SDL_Rect* pr,int l,int t,int r,int b)
{
	pr->x = l;
	pr->y = t;
	pr->w = r-l;
	pr->h = b-t;
}

BYTE  CMjView::minium(BYTE a,BYTE b)
{
	if(a<b) return a;
	else return b;
}

void CMjView::OnHelpmj() 
{
	char cHelpStr[1000];
	strcpy(cHelpStr,"������ʽ: \n");
	strcat(cHelpStr,"����:��ʼ����������,��ʱ��������Ĺ�����,����ʼ�Զ�����\n");
	strcat(cHelpStr,"����:��������Ϻ�������,������ʼ\n");
	strcat(cHelpStr,"����:�����ư�ťΪ��ɫʱ,���¸ð�ť,�ڰ�ť������ʾ�ɳԵ�����,�ٵ��Ҫ�Ե�����\n");
	strcat(cHelpStr,"����:�����ư�ťΪ��ʱ,���¸ð�ť����\n");
	strcat(cHelpStr,"����:�����ư�ťΪ��ɫʱ,���¸ð�ť\n");
	strcat(cHelpStr,"     �������пɸܵ���,���ڰ�ť����ʾ�ɸܵ���,���Ҫ�ܵ��Ƽ���\n");
	strcat(cHelpStr,"     �������޿ɸܵ���(ֻ�����ܵ����),���Ѿ�����\n");
	strcat(cHelpStr,"����:�����ư�ťΪ��ʱ,���¸ð�ť,��ʾ������,���������Դ�\n");
	strcat(cHelpStr,"����:�����ư�ťΪ��ʱ,���¸ð�ť����\n");
	strcat(cHelpStr,"������Ҽ�ȡ�����ܵĳ�,��,�ܵȲ���\n");
	strcat(cHelpStr,"���¼���'V'��,��ʾ��������������");
	//MessageBox(cHelpStr,NULL,MB_OK);
}

void CMjView::GetSelectRect()
{
	BYTE nbTmp,nbTmpCode[17],nbTmp1,nbTmp2;
	nbTmp = m_cMJ.player[0].GetMjDownSea(nbTmpCode);
	nbTmp1 = m_cMJ.player[0].GetMjInHand(nbTmpCode);
	nbTmp2 = m_cMJ.player[0].GetMjAnGang(nbTmpCode);

	SetRect(&rGuzi, pntSaizi.x+60,pntSaizi.y+9,pntSaizi.x+122,pntSaizi.y+31);
	SetRect(&rMopai, pntInHand[0].x+nMjImgW*16,pntWeiZhua[0].y,600,640);
	SetRect(&rDapai, pntInHand[0].x+(nbTmp+nbTmp2*3)*nMjImgW+5,pntInHand[0].y,pntInHand[0].x+(nbTmp+nbTmp1+nbTmp2*3)*nMjImgW+5,pntInHand[0].y+nMjImgH);
	SetRect(&rChipai, pntChiGangSel.x,pntChiGangSel.y,pntChiGangSel.x+((nbChipaiStat>100)+(nbChipaiStat>10)+1)*(nMjImgW*2+5),pntChiGangSel.y+nMjImgH);
	SetRect(&rGangpai, pntChiGangSel.x,pntChiGangSel.y,pntChiGangSel.x+nbGangpaiNum*MJWIDTH,pntChiGangSel.y+MJHITH);
}

void CMjView::UpdateMjButton()
{
	int nTran[5] = {0,1,2,4,3};
	for (int i=0; i<5; i++)
	{
		m_pBuMj->SetBtnStatus(nTran[i],DISABLED);
	}

	if(m_cMJ.GetNowPlayer() == 0 && isButtonValid == false)
	{
		BYTE tmp[5];
		for(int i=0;i<5;i++) tmp[i] = DISABLED;
		m_cMJ.GetButtonStat(tmp);
		////////////////////////////////////////////////////////////
		for (int i=0; i<5; i++)
		{
			if (tmp[i]==ENABLED)
			{
				if(nbButtonStat[i] != PUSHED) 
				{
					nbButtonStat[i] = tmp[i];
					m_pBuMj->SetBtnStatus(nTran[i],PUSHDOWN);
				}
				m_pBuMj->SetBtnStatus(nTran[i],NORMAL);
			}
			else
			{
				nbButtonStat[i] = tmp[i];
			}
		}

		int nTran[5] = {0,1,2,4,3};
		int nbSelectedBtn = nTran[m_nMjBtnCode];
		if (m_pBuMj->IfBtnEnable() && nbSelectedBtn!=CHIPAI-1 && nbSelectedBtn!=GANGPAI-1)
		{
			m_pBuMj->SelFirst();
		}
	}
}

void CMjView::CancelMjButton() 
{
	if(m_cMJ.GetNowPlayer() == 0 && m_cMJ.GetStatus() == DAPAI)
	{
		isButtonValid = true;
		m_cMJ.SetNowPlayerStat(isButtonValid);
		for(int i=0;i<4;i++)		
		{
			nbButtonStat[i] = DISABLED;
		}
	}
}

void CMjView::DoMjBotton() 
{
	BYTE nbCode,nbPlayer,nbStatus,nbLast,nbLastPlayStatus,nbPlayStat;
 	nbLastPlayStatus = m_cMJ.GetLastPlayStat();
	nbLast = m_cMJ.GetLastPlayer();
	nbCode = m_cMJ.GetPostCode();
	nbPlayer = m_cMJ.GetNowPlayer();
	nbPlayStat = m_cMJ.GetNowPlayStat();
	////////////////////////////////////////////////////////////
	int nTran[5] = {0,1,2,4,3};
	int nbSelectedBtn = nTran[m_nMjBtnCode];
	nbButtonStat[nbSelectedBtn] = PUSHED;
	if(nbSelectedBtn +1 == TINGPAI)
	{
		m_cMJ.play(0,TINGPAI,nbSelectedBtn);
	}
	else if(nbSelectedBtn +1 == CHIPAI)
	{
		m_cMJ.GetCipaiStat(0,nbLast,nbCode,nbChipaiStat);
	}
	else if(nbSelectedBtn+1 == GANGPAI && !(nbLast>=1 && nbLast<=3))
	{
		m_cMJ.GetGangpaiStat(0,nbLast,nbCode,nbGangpaiNum,nbGangpaiCode,nbGangpaiStat);
	}
	else if(nbSelectedBtn+1 == HUPAI)
	{
		m_cMJ.play(0,HUPAI,nbLastPlayStatus);
	}
	else 
	{	//��
		m_cMJ.play(0,nbSelectedBtn+1,nbCode);
		m_nbSelecteArea = SEL_NONE;
		MjAction();
		m_ncSelectedNum = 0;
		nbMjSelected = -1;
		m_nbSelecteArea = SEL_DAPAI;
		return;
	}

	m_ncSelectedNum = -1;
	nbMjSelected = -1;
	m_nbSelecteArea = SEL_NONE;
}

void CMjView::MjAction() 
{
	BYTE nbStatus = m_cMJ.GetStatus();
	if(nbStatus == KAIJU)						//����
	{
		isLiuJu = false;
		m_cMJ.Kaiju(nbGuzi1,nbGuzi2);
		for(int i=0;i<5;i++)	nbButtonStat[i] = DISABLED;
		for(int i=0;i<5;i++)	m_pBuMj->SetBtnStatus(i,DISABLED);
	}
	else if(nbStatus == QIPAI)					//����
	{
		m_cMJ.Qipai();
	}
	else if(nbStatus == BUHUA)					//����
	{
		m_cMJ.Buhua();
		isButtonValid = false;
	}
	else if(nbStatus == WANZHUANG )				//����
	{
		if(isLiuJu == true) m_cMJ.WanZhuang(0);
		else m_cMJ.WanZhuang(1);
	}
	else if(nbStatus == DAPAI)					//����
	{
		int i;
		
		BYTE nbLastPlayStatus = m_cMJ.GetLastPlayStat();	//�ϴ���Ҡ�B
		BYTE nbLast = m_cMJ.GetLastPlayer();			//�ϴ����
		BYTE nbCode = m_cMJ.GetPostCode();			//�ϴβ�������
		BYTE nbPlayer = m_cMJ.GetNowPlayer();		//��ǰ���
		BYTE nbPlayStat = m_cMJ.GetNowPlayStat();	//��ǰ��Ҡ�B
		BYTE nbHead,nbTail,nbStart;			//��ǰ��ץ������//������ץ�˼�����//��ʼ�ĵ������������Ķ�����//
		m_cMJ.GetNum(nbStart,nbHead,nbTail);		//

		if(nbTail%2 != 0) nbTail --;
		if(nbTail - nbHead == 18)		//����߀ʣ18�����ƾֽY�������ƣ����f
		{
			isLiuJu = true;
			m_cMJ.SetStatus(WANZHUANG);
		}
		else if(nbPlayer != 0)		//��X
		{
			m_cMJ.play(nbPlayer,nbPlayStat,nbCode);
			if(nbPlayStat == CHUPAI)  isButtonValid = false;
		}
		else		//���
		{
			GetSelectRect();

			/////////////////////////////////////////////////////////////////////////////////////////////
			//m_cMJ.GetButtonStat(nbButtonStat);
			if(((nbPlayStat == CHUPAI || nbPlayStat == XUANPAI) && m_nbSelecteArea == SEL_DAPAI) ||
				(m_cMJ.player[0].GetTingpaiStat()==2 && nbPlayStat!=MOPAI && nbButtonStat[HUPAI-1]==DISABLED && nbPlayStat!=BUPAI))
			{		//�x�ơ����ƣ����� ��
				if(m_ncSelectedNum != nbMjSelected)			//��ǰ�x����
				{
					nbMjSelected = m_ncSelectedNum;
					//m_ncSelectedNum = -1;
					CancelMjButton();
				}
				else if(nbButtonStat[CHIPAI-1] == DISABLED && nbButtonStat[GANGPAI-1] == DISABLED
					    && nbButtonStat[PENPAI-1] == DISABLED && nbButtonStat[HUPAI-1] == DISABLED)
				{
					m_cMJ.play(0,CHUPAI,m_ncSelectedNum);		//����
//					if(nbButtonStat[TINGPAI-1] == PUSHED) m_cMJ.play(0,TINGPAI,m_ncSelectedNum);
					if(nbButtonStat[TINGPAI-1] != PUSHED) nbButtonStat[TINGPAI-1] = DISABLED;
					for(i=0;i<4;i++)	nbButtonStat[i] = DISABLED;		//���oȫ���oЧ
					nbMjSelected = INVALID;
					isButtonValid = false;
				}
			}
			else if(nbPlayStat == MOPAI)	//
			{
				m_cMJ.play(0,MOPAI,0);
				isButtonValid = false;
			}
			else if(nbPlayStat == BUPAI)	//
			{
				m_cMJ.play(0,BUPAI,0);
				isButtonValid = false;
			}
			else if(m_nbSelecteArea == SEL_GANGPAI && nbButtonStat[GANGPAI-1] == PUSHED)
			{		//�Ƿ��x��Ҫ�ܵ���
				if (m_ncSelectedNum<0)
				{
					CancelMjButton();
				}
				else
				{
					m_cMJ.play(0,GANGPAI,nbGangpaiCode[m_ncSelectedNum]);
				}
				for(i =0 ;i<4;i++)	nbButtonStat[i] = DISABLED;
			}
			else if(m_nbSelecteArea == SEL_CHIPAI && nbButtonStat[CHIPAI-1] == PUSHED )
			{		//���ƿɳ�
				if (m_ncSelectedNum<0)
				{	//����
					CancelMjButton();
				}
				else
				{
					BYTE tmp[3];
					if(nbChipaiStat <= 10)
					{    
						tmp[0] = nbChipaiStat;
						tmp[1] = tmp[2] = INVALID;
					}
					else if(nbChipaiStat <= 100)
					{
						tmp[0] = nbChipaiStat/10;
						tmp[1] = nbChipaiStat%10;tmp[2] = INVALID;
					}
					else if(nbChipaiStat > 100 && nbChipaiStat <=123 )
					{
						tmp[0] = nbChipaiStat/100;
						tmp[1] = (nbChipaiStat/10)%10;
						tmp[2] = nbChipaiStat%10;
					}
					if(tmp[m_ncSelectedNum] >= 1 && tmp[m_ncSelectedNum] <=3)
					{		//�x��Ҫ�Ե��ƽM��
						m_cMJ.play(0,CHIPAI,tmp[m_ncSelectedNum]);
						for(i =0 ;i<4;i++)	nbButtonStat[i] = DISABLED;
					}
				}
			}
			else if(nbButtonStat[GANGPAI-1] == PUSHED )	//����
			{
				for(i =0 ;i<4;i++)	nbButtonStat[i] = DISABLED;
			}
			else if(nbButtonStat[TINGPAI-1] == PUSHED )
			{
				for(i =0 ;i<4;i++)	nbButtonStat[i] = DISABLED;
			}
		}
	}//����

	//�ı��齫������ť״̬������/����/���ƵȲ������п��ܸı䰴ť״̬
	UpdateMjButton();
}

//��δץ���Ƶ�ͼ
void CMjView::PasteWeiZhua(SDL_Surface *screen)
{
	BYTE nbMjDefined[4][17];
	BYTE nbTail,nbHead,nbStart,nbStartNum;
	int  i,j;

	m_cMJ.GetNum(nbStart,nbHead,nbTail);
	if(nbHead%2 != 0) nbHead --; nbHead = nbHead/2;
	if(nbTail%2 != 0) nbTail ++; nbTail = nbTail/2;nbTail = 72-nbTail;
	for(i=0;i<4;i++)
		for(j=0;j<18;j++) nbWeiZhua[i][j] = 1;
	
	nbStartNum = (nbStart+m_cMJ.GetZhuangjia())%4;
	for(i=nbStartNum+4;i>nbStartNum;i--)
	{
		if(i%4 == nbStartNum%4)
		{
			if(i%4 == 2 || i%4 ==3)
			{
				for(j=0;j<minium(nbHead,18-nbStart);j++)
					nbWeiZhua[nbStartNum][nbStart+j] = 0;
			}
			else
			{
				for(j=0;j<minium(nbHead,18-nbStart);j++)
					nbWeiZhua[nbStartNum][17-nbStart-j] = 0;
			}
			
			if(nbHead > 18-nbStart) nbHead = nbHead-18+nbStart;
			else nbHead = 0;
		}
		else
		{
			if(nbHead != 0)
			{
				if(i%4 == 2 || i%4 == 3)
				{
					for(j=0;j<minium(nbHead,18);j++) nbWeiZhua[i%4][j] = 0;
				}
				else
				{
					for(j=0;j<minium(nbHead,18);j++)   nbWeiZhua[i%4][17-j] = 0;
				}
			}
			if(nbHead > 18) nbHead = nbHead-18;
			else nbHead = 0;
		}
	}
	for(i=nbStartNum;i<nbStartNum+4;i++)
	{
		if(i%4 == nbStartNum)
		{
			if(i%4 == 2 || i%4 ==3)
			{
				for(j=0;j<minium(nbTail,nbStart);j++)
					nbWeiZhua[nbStartNum][nbStart-j] = 0;
			}
			else
			{
				for(j=0;j<minium(nbTail,nbStart);j++)
					nbWeiZhua[nbStartNum][17-nbStart+j] = 0;
			}
			if(nbTail > nbStart) nbTail= nbTail - nbStart;
			else nbTail = 0;
		}
		else
		{
			if(nbTail != 0)
			{
				if(i%4 == 2 || i%4 == 3)
				{
					for(j=0;j<minium(nbTail,18);j++)
						nbWeiZhua[i%4][17-j] = 0;
				}
				else
				{
					for(j=0;j<minium(nbTail,18);j++)
						nbWeiZhua[i%4][j] = 0;
				}
			}
			if(nbTail > 18) nbTail = nbTail-18;
			else nbTail = 0;
		}
	}

	for(i=0;i<4;i++)	
		m_cMJ.player[i].GetMjDefined(nbMjDefined[i]);

	/*********************/
	src.w = MJHITH;
	src.h = MJWIDTH;
	dst.w = MJHITH;
	dst.h = MJWIDTH;
	src.x = SCALEX+3*MJHITH;
	src.y = SCALEY-6*MJWIDTH;
	for(i=17;i>=0;i--)
	{
		if(nbWeiZhua[1][i] == 1)
		{
			dst.x = pntWeiZhua[1].x;
			dst.y = pntWeiZhua[1].y-i*nMjImgW;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		if(nbWeiZhua[3][i] == 1)
		{
			dst.x = pntWeiZhua[3].x;
			dst.y = pntWeiZhua[3].y-i*nMjImgW;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	src.h = MJHITH;
	src.w = MJWIDTH;
	dst.h = MJHITH;
	dst.w = MJWIDTH;
	src.y = 3*MJHITH;
	src.x = 5*MJWIDTH;
	for(i=0; i<=17; i++)
	{
		if(nbWeiZhua[2][i] == 1)
		{
			dst.x = pntWeiZhua[2].x+i*nMjImgW;
			dst.y = pntWeiZhua[2].y;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		if(nbWeiZhua[0][i] == 1)
		{
			dst.x = pntWeiZhua[0].x+i*nMjImgW;
			dst.y = pntWeiZhua[0].y;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
}

void CMjView::PasteMJDiTu(SDL_Surface *screen)
{
	BYTE nbMjInHand[4][17];		//�����齫��
	BYTE nbNumInHand[4];		//�����齫����Ŀ
	BYTE nbMjDownSea[4][17];	//�Ի������齫��
	BYTE nbNumDownSea[4];		//�Ի������齫����Ŀ
	BYTE nbGangDownSea[4][5];	//�Ի����������Ƿ����
	BYTE nbMjAnGang[4][5];		//���ܵ���
	BYTE nbNumAnGang[4];		//���ܵ�����Ŀ
	int  i,j;

	for(i=0;i<4;i++)
	{
		nbNumDownSea[i] = m_cMJ.player[i].GetMjDownSea(nbMjDownSea[i]);
		nbNumInHand[i] = m_cMJ.player[i].GetMjInHand(nbMjInHand[i]);
		nbNumAnGang[i] = m_cMJ.player[i].GetMjAnGang(nbMjAnGang[i]);
		m_cMJ.player[i].GetGangDownSea(nbGangDownSea[i]);
//		for(j=0;j<8;j++)
//			nbHuapai[i][j] = m_cMJ.player[i].GetHuapai(j);	
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ��ҷ�
	src.w = MJWIDTH;
	src.h = MJHITH;
	dst.w = MJWIDTH;
	dst.h = MJHITH;
	for(i=0;i<nbNumDownSea[0];i++)
	{
		//cMemDC->BitBlt(pntInHand[0].x+i*nMjImgW,pntInHand[0].y,nMjImgW,nMjImgH,cMemBakDC,(nbMjDownSea[0][i]%10-1)*nMjImgW,(nbMjDownSea[0][i]/10)*nMjImgH,SRCCOPY);
		dst.x = pntInHand[0].x+i*nMjImgW;
		dst.y = pntInHand[0].y;
		src.x = (nbMjDownSea[0][i]%10-1)*MJWIDTH;
		src.y = (nbMjDownSea[0][i]/10)*MJHITH;
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		if(nbGangDownSea[0][i/3] == 1 && i%3 == 1)
		{	//���ƶ໭һ��
			//cMemDC->BitBlt(pntInHand[0].x+i*nMjImgW-3,pntInHand[0].y-3,nMjImgW,nMjImgH,cMemBakDC,(nbMjDownSea[0][i]%10-1)*nMjImgW,(nbMjDownSea[0][i]/10)*nMjImgH,SRCCOPY);
			dst.x = pntInHand[0].x+i*nMjImgW-3;
			dst.y = pntInHand[0].y-3;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	for(i=0;i<nbNumAnGang[0];i++)
	{
		for(j=0;j<3;j++)
		{
			dst.x = pntInHand[0].x+nbNumDownSea[0]*nMjImgW+(i*3+j)*nMjImgW;
			dst.y = pntInHand[0].y;
			src.x = 5*MJWIDTH;
			src.y = 3*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		//cMemDC->BitBlt(pntInHand[0].x+nbNumDownSea[0]*nMjImgW+5+(i*3+1)*nMjImgW-3,pntInHand[0].y-3,nMjImgW,nMjImgH,cMemBakDC,(nbMjAnGang[0][i]%10-1)*nMjImgW,(nbMjAnGang[0][i]/10)*nMjImgH,SRCCOPY);
		dst.x = pntInHand[0].x+nbNumDownSea[0]*nMjImgW+(i*3+1)*nMjImgW-3;
		dst.y = pntInHand[0].y-3;
		src.x = (nbMjAnGang[0][i]%10-1)*MJWIDTH;
		src.y = (nbMjAnGang[0][i]/10)*MJHITH;
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
	}
	for(i=0;i<nbNumInHand[0];i++)
	{
		//cMemDC->BitBlt(pntInHand[0].x+(nbNumDownSea[0]+nbNumAnGang[0]*3)*nMjImgW+i*nMjImgW,pntInHand[0].y,nMjImgW,nMjImgH,cMemBakDC,(nbMjInHand[0][i]%10-1)*nMjImgW,(nbMjInHand[0][i]/10)*nMjImgH,SRCCOPY);
		dst.x = pntInHand[0].x+(nbNumDownSea[0]+nbNumAnGang[0]*3)*nMjImgW+i*nMjImgW+5;
		dst.y = pntInHand[0].y-(i==nbMjSelected)*5;
		src.x = (nbMjInHand[0][i]%10-1)*MJWIDTH;
		src.y = (nbMjInHand[0][i]/10)*MJHITH;
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
	}
	
	//�����ʾ
	if (m_egiGame==EGI_PLAY && m_cMJ.GetNowPlayer()==0 && !m_pBuMj->IfBtnPush() && m_nKeySelBtn==0 && m_ncSelectedNum>=0)
	{
		src.x = 6*MJWIDTH;
		src.y = 3*MJHITH;
		if (nbButtonStat[GANGPAI-1] == PUSHED)
		{
			dst.x = rGangpai.x+MJWIDTH*m_ncSelectedNum;
			dst.y = rGangpai.y;
		}
		else if( nbButtonStat[CHIPAI-1] == PUSHED )
		{
			dst.x = rChipai.x+(nMjImgW*2+5)*m_ncSelectedNum;
			dst.y = rChipai.y;
			src.x = 7*MJWIDTH;
			src.w = MJWIDTH*2;
			dst.w = MJWIDTH*2;
		}
		else //if (nbPlayStat == CHUPAI || nbPlayStat == XUANPAI) 
		{
			dst.x = pntInHand[0].x+(nbNumDownSea[0]+nbNumAnGang[0]*3)*nMjImgW+m_ncSelectedNum*nMjImgW+5;
			dst.y = pntInHand[0].y-(m_ncSelectedNum==nbMjSelected)*5;
		}
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	// �¼�
	src.w = MJHITH;
	src.h = MJWIDTH;
	dst.w = MJHITH;
	dst.h = MJWIDTH;
	for(i=nbNumInHand[1]-1;i>=0;i--)
	{
		dst.x = pntInHand[1].x;
		dst.y = pntInHand[1].y-(nbNumDownSea[1]+nbNumAnGang[1]*3)*nMjImgW-i*nMjImgW;
		if(isViewOther == true || m_cMJ.GetStatus() == WANZHUANG )
		{
			//cMemDC->BitBlt(pntInHand[1].x,pntInHand[1].y-(nbNumDownSea[1]+nbNumAnGang[1]*3)*nMjImgW-i*nMjImgW,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjInHand[1][i]/10)*nMjImgH,SCALEY-(nbMjInHand[1][i]%10)*nMjImgW,SRCCOPY);
			src.x = SCALEX+(nbMjInHand[1][i]/10)*MJHITH;
			src.y = SCALEY-(nbMjInHand[1][i]%10)*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		else
		{
			src.x = SCALEX+3*MJHITH;
			src.y = SCALEY-6*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}

	}
	for(i=nbNumDownSea[1]-1;i>=0;i--)
	{
		//cMemDC->BitBlt(pntInHand[1].x,pntInHand[1].y-i*nMjImgW,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjDownSea[1][i]/10)*nMjImgH,SCALEY-(nbMjDownSea[1][i]%10)*nMjImgW,SRCCOPY);
		dst.x = pntInHand[1].x;
		dst.y = pntInHand[1].y-i*nMjImgW;
		src.x = SCALEX+(nbMjDownSea[1][i]/10)*MJHITH;
		src.y = SCALEY-(nbMjDownSea[1][i]%10)*MJWIDTH;
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		if(nbGangDownSea[1][i/3] == 1 && i%3 == 1)
		{
			//cMemDC->BitBlt(pntInHand[1].x-3,pntInHand[1].y-i*nMjImgW-3,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjDownSea[1][i]/10)*nMjImgH,SCALEY-(nbMjDownSea[1][i]%10)*nMjImgW,SRCCOPY);
			dst.x = pntInHand[1].x-3;
			dst.y = pntInHand[1].y-i*nMjImgW-3;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	for(i=nbNumAnGang[1]-1;i>=0;i--)
	{
		for(j=0;j<3;j++)
		{
			dst.x = pntInHand[1].x;
			dst.y = pntInHand[1].y-nbNumDownSea[1]*nMjImgW-(i*3+j)*nMjImgW;
			src.x = SCALEX+3*MJHITH;
			src.y = SCALEY-6*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		dst.x = pntInHand[1].x-3;
		dst.y = pntInHand[1].y-nbNumDownSea[1]*nMjImgW-(i*3+1)*nMjImgW-3;
		if(isViewOther == true)
		{
			//cMemDC->BitBlt(pntInHand[1].x-3,pntInHand[1].y-nbNumDownSea[1]*nMjImgW-(i*3+1)*nMjImgW-5+2,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjAnGang[1][i]/10)*nMjImgH,SCALEY-(nbMjAnGang[1][i]%10)*nMjImgW,SRCCOPY);
			src.x = SCALEX+(nbMjAnGang[1][i]/10)*MJHITH;
			src.y = SCALEY-(nbMjAnGang[1][i]%10)*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		else
		{
			src.x = SCALEX+3*MJHITH;
			src.y = SCALEY-6*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �Լ�
	src.w = MJWIDTH;
	src.h = MJHITH;
	dst.w = MJWIDTH;
	dst.h = MJHITH;
	for(i=0;i<nbNumDownSea[2];i++)
	{
		//cMemDC->BitBlt(pntInHand[2].x+i*nMjImgW,pntInHand[2].y,nMjImgW,nMjImgH,cMemBakDC,(nbMjDownSea[2][i]%10-1)*nMjImgW,(nbMjDownSea[2][i]/10)*nMjImgH,SRCCOPY);
		dst.x = pntInHand[2].x+i*nMjImgW;
		dst.y = pntInHand[2].y;
		src.x = (nbMjDownSea[2][i]%10-1)*MJWIDTH;
		src.y = (nbMjDownSea[2][i]/10)*MJHITH;
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		if(nbGangDownSea[2][i/3] == 1 && i%3 == 1)
		{
			//cMemDC->BitBlt(pntInHand[2].x+i*nMjImgW-3,pntInHand[2].y-3,nMjImgW,nMjImgH,cMemBakDC,(nbMjDownSea[2][i]%10-1)*nMjImgW,(nbMjDownSea[2][i]/10)*nMjImgH,SRCCOPY);
			dst.x = pntInHand[2].x+i*nMjImgW-3;
			dst.y = pntInHand[2].y-3;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	for(i=0;i<nbNumAnGang[2];i++)
	{
		for(j=0;j<3;j++)
		{
			dst.x = pntInHand[2].x+(i*3+j)*nMjImgW+nbNumDownSea[2]*nMjImgW;
			dst.y = pntInHand[2].y;
			src.x = 5*MJWIDTH;
			src.y = 3*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		dst.x = pntInHand[2].x+(i*3+1)*nMjImgW+nbNumDownSea[2]*nMjImgW-3;
		dst.y = pntInHand[2].y-3;
		if(isViewOther== true)
		{
			//cMemDC->BitBlt(pntInHand[2].x+(i*3+1)*nMjImgW+nbNumDownSea[2]*nMjImgW-3,pntInHand[2].y-3,nMjImgW,nMjImgH,cMemBakDC,(nbMjAnGang[2][i]%10-1)*nMjImgW,(nbMjAnGang[2][i]/10)*nMjImgH,SRCCOPY);
			src.x = (nbMjAnGang[2][i]%10-1)*MJWIDTH;
			src.y = (nbMjAnGang[2][i]/10)*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		else
		{
			src.x = 5*MJWIDTH;
			src.y = 3*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	for(i=0;i<nbNumInHand[2];i++)
	{
		dst.x = pntInHand[2].x+i*nMjImgW+(nbNumDownSea[2]+nbNumAnGang[2]*3)*nMjImgW;
		dst.y = pntInHand[2].y;
		if(isViewOther == true || m_cMJ.GetStatus() == WANZHUANG)
		{
			//cMemDC->BitBlt(pntInHand[2].x+i*nMjImgW+(nbNumDownSea[2]+nbNumAnGang[2]*3)*nMjImgW,pntInHand[2].y,nMjImgW,nMjImgH,cMemBakDC,(nbMjInHand[2][i]%10-1)*nMjImgW,(nbMjInHand[2][i]/10)*nMjImgH,SRCCOPY);
			src.x = (nbMjInHand[2][i]%10-1)*MJWIDTH;
			src.y = (nbMjInHand[2][i]/10)*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		else
		{
			src.x = 5*MJWIDTH;
			src.y = 3*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}

	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// �ϼ�
	src.w = MJHITH;
	src.h = MJWIDTH;
	dst.w = MJHITH;
	dst.h = MJWIDTH;
	for(i=nbNumInHand[3]-1;i>=0;i--)
	{
		dst.x = pntInHand[3].x;
		dst.y = pntInHand[3].y-i*nMjImgW-(nbNumDownSea[3]+nbNumAnGang[3]*3)*nMjImgW;
		if(isViewOther == true || m_cMJ.GetStatus() == WANZHUANG )
		{
			//cMemDC->BitBlt(pntInHand[3].x,pntInHand[3].y-i*nMjImgW-(nbNumDownSea[3]+nbNumAnGang[3]*3)*nMjImgW,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjInHand[3][i]/10)*nMjImgH,SCALEY-(nbMjInHand[3][i]%10)*nMjImgW,SRCCOPY);
			src.x = SCALEX+(nbMjInHand[3][i]/10)*MJHITH;
			src.y = SCALEY-(nbMjInHand[3][i]%10)*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		else
		{
			src.x = SCALEX+3*MJHITH;
			src.y = SCALEY-6*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	for(i=nbNumDownSea[3]-1;i>=0;i--)
	{
		//cMemDC->BitBlt(pntInHand[3].x,pntInHand[3].y-i*nMjImgW,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjDownSea[3][i]/10)*nMjImgH,SCALEY-(nbMjDownSea[3][i]%10)*nMjImgW,SRCCOPY);
		dst.x = pntInHand[3].x;
		dst.y = pntInHand[3].y-i*nMjImgW;
		src.x = SCALEX+(nbMjDownSea[3][i]/10)*MJHITH;
		src.y = SCALEY-(nbMjDownSea[3][i]%10)*MJWIDTH;
		SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		if(nbGangDownSea[3][i/3] == 1 && i%3 == 1)	
		{
			//cMemDC->BitBlt(pntInHand[3].x-3,pntInHand[3].y-i*nMjImgW-3,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjDownSea[3][i]/10)*nMjImgH,SCALEY-(nbMjDownSea[3][i]%10)*nMjImgW,SRCCOPY);
			dst.x = pntInHand[3].x-3;
			dst.y = pntInHand[3].y-i*nMjImgW-3;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
	for(i=nbNumAnGang[3]-1;i>=0;i--)
	{
		for(j=0;j<3;j++)
		{
			dst.x = pntInHand[3].x;
			dst.y = pntInHand[3].y-nbNumDownSea[3]*nMjImgW-(i*3+j)*nMjImgW;
			src.x = SCALEX+3*MJHITH;
			src.y = SCALEY-6*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		dst.x = pntInHand[3].x-3;
		dst.y = pntInHand[3].y-(i*3+1)*nMjImgW-nbNumDownSea[3]*nMjImgW-3;
		if(isViewOther == true)
		{
			//cMemDC->BitBlt(pntInHand[3].x-3,pntInHand[3].y-(i*3+1)*nMjImgW-nbNumDownSea[3]*nMjImgW-3,nMjImgH,nMjImgW,cMemBakDC,SCALEX+(nbMjAnGang[3][i]/10)*nMjImgH,SCALEY-(nbMjAnGang[3][i]%10)*nMjImgW,SRCCOPY);
			src.x = SCALEX+(nbMjAnGang[3][i]/10)*MJHITH;
			src.y = SCALEY-(nbMjAnGang[3][i]%10)*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
		else
		{
			src.x = SCALEX+3*MJHITH;
			src.y = SCALEY-6*MJWIDTH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
}

void CMjView::PasteOutHand(SDL_Surface *screen)
{
	int  i,j;
	for(i=0;i<4;i++)
	{
		//��ʾ�������ﶬ÷����ա�
		int nHuapaiNum = 0;
		BYTE nbHuapai[8];
		for(j=0;j<8;j++) nbHuapai[j] = m_cMJ.player[i].GetHuapai(j);	
		for (j=0; j<8; j++) if (nbHuapai[j]==1)
		{
			int n = 1-j/4;
			int m = j%4;
			dst.x = pntOutHand[i][nHuapaiNum].x;
			dst.y = pntOutHand[i][nHuapaiNum].y;
			if (i==0||i==2)
			{
				//cMemDC->BitBlt(pntOutHand[i][nHuapaiNum].x,pntOutHand[i][nHuapaiNum].y,nMjImgW,nMjImgH,
				//	cMemBakDC,nMjImgW*m,nMjImgH*(n+5),SRCCOPY);
				src.w = MJWIDTH;
				src.h = MJHITH;
				dst.w = MJWIDTH;
				dst.h = MJHITH;
				src.x = MJWIDTH*m;
				src.y = MJHITH*(n+5);
			}
			else
			{
				//cMemDC->BitBlt(pntOutHand[i][nHuapaiNum].x,pntOutHand[i][nHuapaiNum].y,nMjImgH,nMjImgW,
				//	cMemBakDC,nMjImgW*9+nMjImgH*(n+5),nMjImgW*9-nMjImgW*(m+1),SRCCOPY);
				src.w = MJHITH;
				src.h = MJWIDTH;
				dst.w = MJHITH;
				dst.h = MJWIDTH;
				src.x = MJWIDTH*9+MJHITH*(n+5);
				src.y = MJWIDTH*9-MJWIDTH*(m+1);
			}
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
			nHuapaiNum++;
		}

		//
		BYTE nbMjOutHand[25];			//���ȥ���齫��
		BYTE nbNumOutHand;				//���ȥ���齫����Ŀ
		nbNumOutHand = m_cMJ.player[i].GetMjOutHand(nbMjOutHand);
		nHuapaiNum++;
		for (j=0; j<nbNumOutHand; j++)
		{
			dst.x = pntOutHand[i][nHuapaiNum+j].x;
			dst.y = pntOutHand[i][nHuapaiNum+j].y;
			if (i==0||i==2)
			{
				//cMemDC->BitBlt(pntOutHand[i][nHuapaiNum+j].x,pntOutHand[i][nHuapaiNum+j].y,nMjImgW,nMjImgH,
				//	cMemBakDC,(nbMjOutHand[j]%10-1)*nMjImgW,(nbMjOutHand[j]/10)*nMjImgH,SRCCOPY);
				src.w = MJWIDTH;
				src.h = MJHITH;
				dst.w = MJWIDTH;
				dst.h = MJHITH;
				src.x = (nbMjOutHand[j]%10-1)*MJWIDTH;
				src.y = (nbMjOutHand[j]/10)*MJHITH;
			}
			else
			{
				//cMemDC->BitBlt(pntOutHand[i][nHuapaiNum+j].x,pntOutHand[i][nHuapaiNum+j].y,nMjImgH,nMjImgW,
				//	cMemBakDC,SCALEX+(nbMjOutHand[j]/10)*nMjImgH,SCALEY-(nbMjOutHand[j]%10)*nMjImgW,SRCCOPY);
				src.w = MJHITH;
				src.h = MJWIDTH;
				dst.w = MJHITH;
				dst.h = MJWIDTH;
				src.x = SCALEX+(nbMjOutHand[j]/10)*MJHITH;
				src.y = SCALEY-(nbMjOutHand[j]%10)*MJWIDTH;
			}
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
		}
	}
}

void CMjView::PasteButton(SDL_Surface *screen)
{
	int		i;
	BYTE nbPostCode;

	nbPostCode = m_cMJ.GetPostCode();

	src.w = MJWIDTH;
	src.h = MJHITH;
	dst.w = MJWIDTH;
	dst.h = MJHITH;
	if(nbButtonStat[CHIPAI-1] == PUSHED)
	{
		int  tmpCode[3][2] = {{-2,-1},{-1,1},{1,2}};
		dst.x = pntChiGangSel.x;
		dst.y = pntChiGangSel.y;
		for(i=1;i<=3;i++)
		{
			if(nbChipaiStat/100 == i || nbChipaiStat%10 == i || (nbChipaiStat/10)%10 == i)
			{
				//tmpx = tmpx+60;;
				//cMemDC->BitBlt(tmpx,tmpy,nMjImgW,nMjImgH,cMemBakDC,((nbPostCode+tmpCode[i-1][0])%10-1)*nMjImgW,((nbPostCode+tmpCode[i-1][0])/10)*nMjImgH,SRCCOPY);
				src.x = ((nbPostCode+tmpCode[i-1][0])%10-1)*MJWIDTH;
				src.y = ((nbPostCode+tmpCode[i-1][0])/10)*MJHITH;
				SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
				//cMemDC->BitBlt(tmpx+nMjImgW+2,tmpy,nMjImgW,nMjImgH,cMemBakDC,((nbPostCode+tmpCode[i-1][1])%10-1)*nMjImgW,((nbPostCode+tmpCode[i-1][1])/10)*nMjImgH,SRCCOPY);
				dst.x += nMjImgW;
				src.x = ((nbPostCode+tmpCode[i-1][1])%10-1)*MJWIDTH;
				SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
				dst.x += (nMjImgW+5);
			}
		}
	}
	else if(nbButtonStat[GANGPAI-1] == PUSHED)
	{
		dst.x = pntChiGangSel.x;
		dst.y = pntChiGangSel.y;
		for(i=0;i<nbGangpaiNum;i++)
		{
			//cMemDC->BitBlt(tmpx,tmpy,nMjImgW,nMjImgH,cMemBakDC,(nbGangpaiCode[i]%10-1)*nMjImgW,(nbGangpaiCode[i]/10)*nMjImgH,SRCCOPY);
			src.x = (nbGangpaiCode[i]%10-1)*MJWIDTH;
			src.y = (nbGangpaiCode[i]/10)*MJHITH;
			SDL_BlitSurface(m_pSfCard, &src, screen, &dst);
			dst.x += MJWIDTH;
		}
	}
}
