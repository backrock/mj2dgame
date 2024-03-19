#include "Mjplayer.h"

class cmj 
{
public:
	cmj();
	virtual ~cmj();
	
	cmjplayer   player[4];				//四个玩家类实例
	BYTE		nbMjAll[144];			//所有麻将牌
	char		csTaiName[STYLE_NUM][100];
	int			nCent[STYLE_NUM];

public:
	int Begin(BYTE nbLevel);
	//开始程序
 	//当程序(OnFileNew)开始时调用,
	//功能: 1. 设置庄家为当前玩家
	//		2. 设置各个玩家手中的数据,状态和牌局的状态
	//返回: 无效 
	//输入: nbLevel,难度级数(暂时无用)
	BYTE SetStatus(BYTE nbStatus);
	//设置牌局状态,其状态有
	//	KAIJU = 0,		开局,最初状态   
	//  QIPAI = 1,      起牌
	//  BUHUA = 2,      补花
	//  DAPAI = 3,	    打牌	
	//  WANZHUANG = 4,  完庄,每局的最终状态,有人胡牌火海底流局时的状态
	//输入：牌局状态
	//返回: 无效 
	BYTE GetStatus();
	//得到牌局状态,
	//输入: 无
	//返回:  牌局状态(牌局状态同SetStatus),
	BYTE Qipai();
	//起牌函数,当牌局状态为起牌时调用
	//功能: 1.起牌,
	//		2.设置牌局状态为补花
	//输入: 无
	//返回: 无效 
	BYTE Buhua();
	//补花函数,当牌局状态为补花时调用
	//功能: 1.补花
	//		2.设置状态为打牌
	//输入: 无
	//返回: 无效 
	BYTE WanZhuang(BYTE nbStat);
	//完庄函数,当牌局状态为完庄时调用
	//功能: 完庄,重新开始新一局
	//输入: 完庄状态,0为海底流局(此时庄家不变),
	//				 1为有人胡牌(此时如果庄家胡牌，庄家不变，否则下家为庄家）
	//返回:　无效
	BYTE Kaiju(BYTE& nbGuzi1,BYTE& nbGuzi2);
	//开局函数，当牌局状态为开局时调用
	//功能：1.开局，扔股子
	//		2.设置状态为起牌
	//输入: 返回nbGuzi1,返回nbGuzi2,
	//		要返回的两个股子的数目
	//返回: nbGuzi1+nbGuzi2,扔股子的总数目
	BYTE GetNum(BYTE & nbStart,BYTE & nbHead, BYTE& nbTail);
	//得到底牌数目
	//输入: nbStart,返回扔股子的总数目
	//		nbHead,返回当前海底牌开头的数目
	//		nbTail,返回当前海底牌结尾的号
	//返回: 无效
	BYTE SetNowPlayerStat(bool isButtonValid);
	//设置当前玩家状态
	//功能: 根据上次玩家和玩家的状态(在VIEW类中不可见)
	//		设置当前玩家和玩家状态
	//输入: 玩家按钮是否有效的标志
	//返回: 当前玩家号 
	BYTE GetCipaiStat(BYTE nbPlayer,BYTE nbLast,BYTE nbCode,BYTE & nbChipaiStat);
	//功能: 得到吃牌状态,(因人吃牌时可选择不同吃法)
	//		吃牌状态定义 :　1,吃的牌比手中的牌大,如5,6条吃7条
	//						2,吃的牌在手中牌中间,如5,7条吃6条
	//						3,吃的牌比手中的牌小,如5,6条吃4条
	//输入: nbPlayer,当前玩家号
	//		nbLast,上次玩家号
	//		nbCode,上次玩家打的牌
	//		nbChipaiStat,返回吃牌状态,如为123,则三种方式都可吃
	//								  如为12,则可吃前两种方式
	//返回: 0为不可吃,1为可吃
	BYTE GetGangpaiStat(BYTE nbPlayer,BYTE nbLast,BYTE nbCode,BYTE & nbGangpaiNum,BYTE nbGangpaiCode[5],BYTE nbGangpaiStat[5]);
	//功能: 得到杠牌状态,(人杠牌时可能手中有几个可杠的牌,要显示出所有可以杠的牌)
	//输入: nbPlayer,当前玩家号
	//		nbLast,上次玩家号
	//		nbCode,上次玩家打的牌  
	//		nbGangpaiNum,返回可以杠牌的牌数
	//		nbGangpaiCode,返回可以杠牌的牌号,为一个1*4的数组
	//		nbGangpaiStat,返回杠牌的状态,为一个1*4的数组,
	//					 ANGANG   = 0			杠牌状态为暗杠
	//					 MINGGANG = 1		杠牌状态为明杠
	//返回: 0为不可杠,1为可杠
	void GetButtonStat(BYTE nbButtonStat[5]);
	//功能: 得到人的按钮状态,
	//		nbButtonStat[0],		吃牌状态
	//		nbButtonStat[1],		碰牌状态
	//		nbButtonStat[2],		杠牌状态
	//		nbButtonStat[3],		胡牌状态
	//		nbButtonStat[4],		听牌状态
	//		状态种类:  ENABLED = 1  表示该状态可能
	//				   PUSHED = 2   表示该状态为已经按下 
	//				   DISABLED = 3 表示该状态为不可能
	//输入: 要返回的按钮状态,为1*5数组
	BYTE GetNowPlayerStat();
	//功能: 返回当前玩家玩牌状态(注:不是牌局状态,牌局状态为整个牌局的状态,
	//								牌局状态定义在前),
	//		MOPAI = 0, 玩家状态为摸牌
	//		CHIPAI =1, 玩家状态为吃牌
	//		PENPAI =2, 玩家状态为碰牌
	//		GANGPAI=3, 玩家状态为杠牌
	//		HUPAI  =4, 玩家状态为胡牌
	//		TINGPAI=5, 玩家状态为听牌
	//		BUPAI  =6, 玩家状态为补牌
	//		CHUPAI =7, 玩家状态为出牌
	//		XUANPAI=8, 玩家状态为选牌,
	//					只有对人有效,轮到人出牌时,可将状态设置为该状态
	//					再根据人的输入确定玩牌的状态
	//返回: 当前玩家状态
	BYTE GetPostCode();
	//功能: 得到上次操作的牌号,如上次操作为出牌,则为出牌的所出牌号
	//						   如上次操作为摸牌或补牌,则为摸牌或补牌的牌号
	//							如上次操作为吃,碰,杠牌,则无效
	//输入: 无
	//返回: 上次操作的牌号
	BYTE play(BYTE nbPlayerNum,BYTE nbStatus,BYTE m_ncSelectedNum);
	//功能: 玩牌函数
	//		同时设置玩完牌后的当前玩家及其状态
	//输入:  nbPlayerNum			当前完家序号
	//		 nbStatus				当前完家状态
	//								MOPAI = 0, 玩家状态为摸牌
	//								CHIPAI =1, 玩家状态为吃牌
	//								PENPAI =2, 玩家状态为碰牌
	//								GANGPAI=3, 玩家状态为杠牌
	//								HUPAI  =4, 玩家状态为胡牌
	//								TINGPAI=5, 玩家状态为听牌
	//								BUPAI  =6, 玩家状态为补牌
	//								CHUPAI =7, 玩家状态为出牌
	//								XUANPAI=8, 玩家状态为选牌,
	//		 m_ncSelectedNum			当玩家为人时有效
	//								当人的状态为吃牌时,为人可以吃牌的第几种吃法
	//									如ChipaiStat为123,输入为1,则吃法为1,如ChipaiStat为23,输入为1,则吃法为2
	//									吃法定义 :　1,吃的牌比手中的牌大,如5,6条吃7条
	//													2,吃的牌在手中牌中间,如5,7条吃6条
	//   												3,吃的牌比手中的牌小,如5,6条吃4条
	//								当人的状态为杠牌时,为要杠牌的牌号,
	//返回: 无效,可不用								
	BYTE GetZhuangjia();
	//功能: 得到当前庄家号
	//输入:　无
	//返回: 当前庄家号
	BYTE GetLastPlayer();
	//功能: 得到上次玩家号
	//输入: 无
	//返回: 上次玩家号
	BYTE GetPaiXin(BYTE * nbPai);
	//功能: 得到牌型
	//输入: 要返回的牌型,为一数组
	//		该数组项为0表示该牌型没有,为1表示有该牌型
	//		牌型定义见"defined.h"
	//返回: 为总的台数
	BYTE GetNowPlayer();
	//功能: 得到当前玩家号
	//输入: 无
	//返回: 当前玩家号
	BYTE GetLastPlayStat();
	//功能: 得到上次玩家状态
	//输入: 无
	//返回: 上次玩家号
	BYTE GetNowPlayStat();
	//功能: 得到当前玩家状态
	//输入: 无
	//返回: 当前玩家状态
	BYTE SetNowPlayer(BYTE nbPlayer);
	//功能: 设置当前玩家
	//输入: 玩家号
	//返回: 当前玩家号
	BYTE SetLastPlayer(BYTE nbPlayer);
	//功能: 设置上次玩家
	//输入: 玩家号
	//返回: 上次玩家号
	BYTE GetMJ(BYTE nbPlayer,BYTE nbNum,BYTE nbMj[17]);
	//功能: 得到各个玩家牌的情况
	//		包括: 玩家下海的牌,玩家手中的牌,玩家打出去的牌
	//			  玩家暗杠的牌,玩家下海的牌中杠牌的情况,和玩家拥有的花牌情况
	//输入: nbPlayer,玩家号(即要得到麻将信息的玩家号)
	//		nbNum,序号,代表要得到什么牌,其定义如下:
	//			  0 玩家下海的牌,  为一个1*14的数组,每一个数组项表示下海的一张牌
	//			  1 玩家手中的牌,  为一个1*14的数组,每一个数组项表示手中的一张牌
	//			  2 玩家打出去的牌,为一个1*14的数组,每一个数组项表示打出去的一张牌
	//			  3 玩家暗杠的牌,  为一个1*4的数组,每一个数组项表示暗杠的牌号
	//			  4 玩家下海的牌中杠牌状况,为一个1*4数组,每一个数组项表示下海的牌是否为杠牌,
	//								如为1表示为杠牌,如为0表示不是杠牌
	//			  5 玩家拥有的花牌情况,为一个1*8数组,每一个数组项为1或0,表示是否拥有该花牌
	//						0  春
	//						1  夏
	//						2  秋
	//						3  冬	
	//						4  梅
	//						5  兰
	//						6  竹
	//						7  菊
	//		nbMj[14], 要返回的麻将牌
	//返回: 各种牌的数目
private:
	BYTE InitDefined(BYTE * nbMjDefined);
	//定义预定牌组
	BYTE RoundBegin(BYTE nbLevel,BYTE nbZhuang);
	int  calcTaiShu(BYTE nbStatus,BYTE nbPlayerNum,BYTE nbLast,BYTE nbCode);
	//计算台数		
	BYTE		nbNowPlayer;			//当前玩家
	BYTE		nbLastPlayer;			//上次出牌的玩家
	BYTE		nbZhuangjia;			//当前庄家
	BYTE		nbRoundNum;				//当前打的轮数
	BYTE		nbStat;					//当前状态，有开局，摸牌和起牌，完毕
	BYTE		nbNowPlayStat;			//当前完家状态，有吃，碰，摸，胡，杠，出牌，选牌（只有人有）
	BYTE		nbLastPlayStat;			//上轮玩家状态
	BYTE        nbStartNum;				//开始的点数，决定从哪儿起牌
	BYTE		nbHeadNum;				//当前在抓哪张牌
	BYTE		nbTailNum;				//海底已抓了几张牌
	BYTE		nbPaiXin[100];			// 牌型
	BYTE		nbPostCode;				//上次操作的牌
};
