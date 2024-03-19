//class CBtnUnion �� class CImgUnion ������������������İ�ť��
//��ʼ��ʱ�趨��ÿ����ť��λ�ü���ͬ״̬��Ӧ��ͼ�š�
//��������¼������ð�ť֮״̬����ָ����ťλ�û��Ƶ�ǰ״̬��Ӧ��ͼ�Ρ�
#include "ImgUnion.h"

enum { NORMAL = 0,MOUSEOVER,PUSHDOWN,DISABLE };
struct BtnImgCode
{
	int nNormal;
	int nMouseOver;
	int nPushDown;
	int nDisable;
};

class CBtnUnion : public CImgUnion
{
public:
	CBtnUnion(const char* csFile,
			 int nNumImg,				// number of images
			 SDL_Rect*	prectSize,			// each image size
			 int nNumBtn,				// number of button
			  SDL_Rect* rectBtn,				// each button located
			 BtnImgCode* sImgCodeBtn,	// image code in CImgUnion of button;
			 int *nStatusBtn);			// the button begining status;
	~CBtnUnion();
	void SetBtnStatus(int nBtnCode,int nStatus);
	bool MouseMove(SDL_Point ptMouse);
	int  KeyMove(unsigned char nChar);
	int  KeyReturn();
	int	 SelFirst();
	int	 SelLast();
	bool IfBtnPush();
	bool IfBtnEnable();
	int  MouseLBDown(SDL_Point ptMouse);
	int  BtnUp();
	void DrawBtn(SDL_Surface *screen);
private:
	int nBtnNum;
	int *nBtnStatus;
	SDL_Rect* rectBtnLocate;				// each button left-top point
	BtnImgCode* sBtnImgCode;
};
