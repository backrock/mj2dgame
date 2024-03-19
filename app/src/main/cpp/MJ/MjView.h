#include "Mj.h"
#include "View.h"
#include "BtnUnion.h"

#define	SEL_NONE 1
#define	SEL_GANGPAI 2
#define	SEL_CHIPAI 3
#define	SEL_DAPAI 4

enum ESndType
{
	ESND_MENU_MOVE,
	ESND_MENU_SELECT,
	ESND_CHESS_MOVE,
	ESND_CHESS_SELECT,
	ESND_CHESS_OUT,
};

class CMjView : public CView
{
public:
	CMjView();
	~CMjView();
	void OnFreeSurface();
	void	OnTimer();
	void	OnDraw(SDL_Window *window);
	void	OnMouseMove(SDL_Point point);
	void	OnKeyDown(unsigned char nChar);
	void	OnLButtonDown(SDL_Point point);
	void	OnLButtonUp(SDL_Point point);
	void	OnRButtonDown(SDL_Point point);

private:

	cmj		m_cMJ;

	int		m_nLevel;				//����
	bool	m_bSndState;			//��Ч����
	char	m_ncSelectedNum;		//��ǰѡ����
	BYTE	m_nbSelecteArea;		//��ǰѡ������
	int		m_nMjBtnCode;

	bool bTimerStart;
	BYTE nbGuzi1,nbGuzi2;			//���ӵĴ�С
	BYTE nbWindDir;					//��������
	BYTE nbButtonStat[5];			//���״̬,�ֱ��ʾ�ԣ������ܣ��ͣ�����״̬
										//��ENABLED��		���Գԣ������ܣ��ͣ���
										//PUSHED��			�Ѿ��ԣ������ܣ��ͣ���
										//DISABLED����		���ɳԣ������ܣ��ͣ���
	BYTE nbWeiZhua[4][18];			//δץ���ƣ�0��ʾ��ץ��1��ʾ����
	BYTE nbMjSelected;				//��ҽ�Ҫ�������
	BYTE nbChipaiStat;
	BYTE nbGangpaiCode[5];			
	BYTE nbGangpaiStat[5];
	BYTE nbGangpaiNum;
	bool isButtonValid;				//��ҳԣ������ܣ��͵�״̬�Ƿ�����
	bool isViewDef;					//�Ƿ�ɼ�Ԥ�ȶ������
	bool isViewOther;				//�Ƿ� �ɼ� ���˵���
	bool isLiuJu;					//�Ƿ����� 

	//
	SDL_Rect rGuzi;
	SDL_Rect rMopai;
	SDL_Rect rDapai;
	SDL_Rect rChipai;
	SDL_Rect rGangpai;

	SDL_Rect src;
	SDL_Rect dst;

	CImgUnion* m_pIuSaizi;
	CImgUnion* m_pIuCenter;
	CBtnUnion* m_pBuMj;

	SDL_Surface* m_pSfCard;
	SDL_Surface* m_pSfBoard;
	SDL_Surface* m_pSfText;

	void PasteWeiZhua(SDL_Surface *screen);
	void PasteMJDiTu(SDL_Surface *screen);
	void PasteOutHand(SDL_Surface *screen);
	void PasteButton(SDL_Surface *screen);

	void SetRect(SDL_Rect* pr,int l,int t,int r,int b);
	void GetSelectRect();
	void UpdateMjButton();
	void CancelMjButton();
	void DoMjBotton();
	void MjAction();

	void New();
	void Setup();
	void OnHelpmj();
	void OnOptionDefine();

	BYTE minium(BYTE a,BYTE b);

	///����ָ����ť
	void PushButton(int nBtnCode);

	void PlaySnd(ESndType est);
};
