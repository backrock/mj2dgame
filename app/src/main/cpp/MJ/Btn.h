#include "../include/SDL_surface.h"

#define	M_SPAN_SIZE	48

class CBtn
{
public:
	CBtn(void);
	~CBtn(void);

	/**
	��ʼ����ť����
	*/
	void Init(int left,int top,int width,int height,		//λ��
			  char*		csFileBase,		//λͼ�ļ����Ļ������֣��������ļ���Ϊ����N.bmp(����)|D.bmp(����)|G.bmp(��Ч)
			  char*		csSpan=NULL);	//��ʾ�ִ�

	/**
	У������
	*/
	void AdjustArea(int nXOff,int nYOff);

	/**
	�ж�����Ƿ��ڰ�ť��
	*/
	bool MouseIn(SDL_Point point);

	/**
	����ť
	*/
	void DrawButton(SDL_Surface *screen);
	
	/** �Ƿ���ʾ��ť */
	void Show(bool bShow);

	/** �Ƿ񼤻ť */
	void Enable(bool bActive);

	/** �趨��ť��ʾ��Ϣ */
	void SetSpan(char* csSpan);

	/** �ı䰴ť״̬ */
	void Push(bool bDown)
	{
		m_bPushDown = bDown;
	}

	/** ѡ�а�ť״̬ */
	void Select(bool bDown)
	{
		m_bSelect = bDown;
	}

private:
	SDL_Rect		m_rectPos;				///λ��
	char		m_csSpan[M_SPAN_SIZE];	///��ʾ�ִ�
	bool		m_bShow;				///�Ƿ���ʾλͼ
	bool		m_bActive;				///�Ƿ񼤻�
	bool		m_bPushDown;			///�Ƿ񱻰���
	bool		m_bSelect;				///�Ƿ�ѡ��

	SDL_Surface*	m_imgNormal;			///��ͨ״̬
	SDL_Surface*	m_imgDown;				///����״̬
	SDL_Surface*	m_imgSelect;			///ѡ��״̬
	SDL_Surface*	m_imgInvalid;			///��Ч״̬
};
