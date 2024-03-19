#ifndef  _GAME_DEF_H_
#define _GAME_DEF_H_


#define M_WIN_WIDTH		640
#define M_WIN_HEIGHT	480

//程序状态ID
enum EGameID
{
	EGI_ENTER,			//进入
	EGI_SETUP,			//设置
	EGI_PLAY,			//游戏
	EGI_PLAY_MENU,		//游戏菜单
	EGI_RETURN,			//返回
	EGI_HELP,			//帮助
	EGI_PLAY_HELP,		//帮助
	EGI_END_WIN,		//对局结束
	EGI_END_LOSE,		//对局结束
	EGI_END_DRAW,		//对局结束
	EGI_QUIT,			//退出确认

	EGI_INVALID,		//无效状态,可作为状态总数
};

#define M_STATUS_NUM EGI_INVALID

//按钮ID
enum EButtonID
{
	EBI_START,			//开始
	EBI_QUIT,			//退出
	EBI_RECODE,			//排行榜
	EBI_BACK,			//悔棋
	EBI_HELP,			//帮助
	EBI_PLAY,			//游戏中，虚拟
	EBI_P_HELP,			//游戏时帮助
	EBI_RETURN,			//返回
	EBI_SETUP,			//设置
	EBI_YES,			//退出确认
	EBI_NO,				//退出取消
	EBI_R_YES,			//返回确认
	EBI_R_NO,			//返回取消

	EBI_S_YES,			//设置确认
	EBI_S_NO,			//设置取消
	EBI_S_LEVEL1,		//级别1
	EBI_S_LEVEL2,		//级别2
	EBI_S_LEVEL3,		//级别3
	EBI_S_SND_OPEN,		//音效开
	EBI_S_SND_CLOSE,	//音效关
	
	EBI_BTN_NUM,		//按钮数目

	//虚拟按钮
};

#define M_MAX_STATUS_BTN_NUM	16
#define M_MAX_GROUP_NUM			8
#define M_MAX_STATUS_PANEL_NUM	4


#endif // ! _GAME_DEF_H_
