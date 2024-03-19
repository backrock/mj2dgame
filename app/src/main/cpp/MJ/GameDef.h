#ifndef  _GAME_DEF_H_
#define _GAME_DEF_H_


#define M_WIN_WIDTH		640
#define M_WIN_HEIGHT	480

//����״̬ID
enum EGameID
{
	EGI_ENTER,			//����
	EGI_SETUP,			//����
	EGI_PLAY,			//��Ϸ
	EGI_PLAY_MENU,		//��Ϸ�˵�
	EGI_RETURN,			//����
	EGI_HELP,			//����
	EGI_PLAY_HELP,		//����
	EGI_END_WIN,		//�Ծֽ���
	EGI_END_LOSE,		//�Ծֽ���
	EGI_END_DRAW,		//�Ծֽ���
	EGI_QUIT,			//�˳�ȷ��

	EGI_INVALID,		//��Ч״̬,����Ϊ״̬����
};

#define M_STATUS_NUM EGI_INVALID

//��ťID
enum EButtonID
{
	EBI_START,			//��ʼ
	EBI_QUIT,			//�˳�
	EBI_RECODE,			//���а�
	EBI_BACK,			//����
	EBI_HELP,			//����
	EBI_PLAY,			//��Ϸ�У�����
	EBI_P_HELP,			//��Ϸʱ����
	EBI_RETURN,			//����
	EBI_SETUP,			//����
	EBI_YES,			//�˳�ȷ��
	EBI_NO,				//�˳�ȡ��
	EBI_R_YES,			//����ȷ��
	EBI_R_NO,			//����ȡ��

	EBI_S_YES,			//����ȷ��
	EBI_S_NO,			//����ȡ��
	EBI_S_LEVEL1,		//����1
	EBI_S_LEVEL2,		//����2
	EBI_S_LEVEL3,		//����3
	EBI_S_SND_OPEN,		//��Ч��
	EBI_S_SND_CLOSE,	//��Ч��
	
	EBI_BTN_NUM,		//��ť��Ŀ

	//���ⰴť
};

#define M_MAX_STATUS_BTN_NUM	16
#define M_MAX_GROUP_NUM			8
#define M_MAX_STATUS_PANEL_NUM	4


#endif // ! _GAME_DEF_H_
