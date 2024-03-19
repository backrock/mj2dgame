#ifndef DEFINED_H
#define DEFINED_H
#define INVALID 255
#define PAIXINGSUM 49

extern int ZHANGSHU, MAXGNUM, MAXGNUMINHAND,MAXSHU;

//定义麻将牌的牌号
enum{
	YIWAN	=	1,		//一万,值为1  
	LIANGWAN,			//二万,值为2
	SANWAN,				//三万,值为3
	SIWAN,				//四万,值为4
	WUWAN,				//五万,值为5
	LIUWAN,				//六万,值为6
	QIWAN,				//七万,值为7
	BAWAN,				//八万,值为8
	JIUWAN,				//九万,值为9

	YITIAO	=	11,		//一条,值为11
	LIANGTIAO,			//二条,值为12
	SANTIAO,			//三条,值为13
	SITIAO,				//四条,值为14
	WUTIAO,				//五条,值为15
	LIUTIAO,			//六条,值为16
	QITIAO,				//七条,值为17
	BATIAO,				//八条,值为18
	JIUTIAO,			//九条,值为19

	YITONG	=	21,		//一筒,值为21
	LIANGTONG,			//二筒,值为22
	SANTONG,			//三筒,值为23
	SITONG,				//四筒,值为24
	WUTONG,				//五筒,值为25
	LIUTONG,			//六筒,值为26
	QITONG,				//七筒,值为27
	BATONG,				//八筒,值为28
	JIUTONG,			//九筒,值为29

	DONGFENG =	31,		//东风,值为31
	NANFENG,			//南风,值为32
	XIFENG,				//西风,值为33
	BEIFENG,			//北风,值为34

	HONGZHONG = 41,		//红中,值为41
	FACAI,				//青发,值为42
	BAIBAN,				//白板,值为43

	MEI		  = 51,		//梅,值为51
	LAN	,				//兰,值为52
	ZHU ,				//竹,值为53
	JU	,				//菊,值为54

	CHUN	 = 61,		//春,值为61
	XIA	,				//夏,值为62
	QIU ,				//秋,值为63
	DONG,				//冬,值为64
};

//定义牌局状态
enum{
	KAIJU    = 0,		//开局,值为0
	QIPAI,				//起牌,值为1
	BUHUA,				//补牌,值为2
	DAPAI,				//打牌,值为3
	WANZHUANG,			//完庄,值为4
};

//定义玩家玩牌状态
enum{
	MOPAI	= 0,		//摸牌,值为0
	CHIPAI,				//吃牌,值为1
	PENPAI,				//碰牌,值为2
	GANGPAI,			//杠牌,值为3
	HUPAI,				//胡牌,值为4
	TINGPAI,			//听牌,值为5
	BUPAI,				//补牌,值为6
	CHUPAI,				//出牌,值为7
	XUANPAI,			//选牌,	值为8
};

//定义按钮状态
enum{
	ENABLED = 1,		//可能,值为1
	PUSHED,				//按下,值为2
	DISABLED,			//不可,值为3
};

//定义杠牌状态
enum{
	ANGANG = 0,			//暗杠,值为0
	MINGGANG,			//明杠,值为1
};

//定义玩家序号
enum{
	DONGJIA = 0,		//东家,即人,值为0
	NANJIA,				//南家,值为1
	XIJIA,				//西家,值为2
	BEIJIA,				//北家,值为3
};

//定义牌的种类,与view类无关
enum{
	JIANGPAI = 0,		//将牌
	KEZI	 ,			//刻子
	GANGZI   ,			//杠子
	SHUNZI	 ,			//顺子
};

//定义牌型
enum{
	ZHUANGJIA = 0,		//庄家,值为0
	MENQING ,			//门清,值为1
	ZIMO,				//字摸,值为2
	LIZHI,				//立直,值为3
	GANGSHANGKAIHUA,	//杠上开花,值为4
	HAIDILAOYUE,		//海底捞月,值为5
	HEDILAOYU,			//河底捞鱼,值为6
	HONGZHONGPAI,		//红中牌,值为7
	FACAIPAI,			//清发牌,值为8
	BAIBANPAI,			//白板牌,值为9
	DONGFENFPAI,		//东风牌,值为10
	XIFENGPAI,			//西风牌,值为11
	NANFENGPAI,			//南风牌,值为12
	BEIFENGPAI,			//北风牌,值为13
	HUAPAI,				//花牌,值为14
	DUANYAOJIU,			//断幺九,值为15
	YIBEIKOU,			//一杯口,值为16
	PINGHU,				//平胡,值为17
	QUANQIUREN,			//全求人,值为18
	YITIAOLONG,			//一条龙,值为19
	SANANKE,			//三暗刻,值为20
	SANGANGZI,			//三杠子,值为21
	HUNQUANDAIYAO,		//混全带幺,值为22
	EBEIKOU,			//二杯口,值为23
	SANSETONGSHUN,		//三色同顺,值为24
	SANSETONGKE,		//三色同刻,值为25
	MENQINGZIMO,		//门清字摸,值为26
	HUNYISE,			//混一色,值为27
	XIAOSANYUAN,		//小三元,值为28
	CUNQUANDAIYAO,		//纯全带幺,值为29
	HUNLAOTOU,			//混老头,值为30
	SIANKE,				//四暗刻,值为31
	SIGANGZI,			//四杠子,值为32
	QINGYISE,			//清一色,值为33
	ZIYISE,				//字一色,值为34
	DASANYUAN,			//大三元,值为35
	XIAOSIXI,			//小四喜,值为36
	WUANKE,				//五暗刻,值为37
	QINLAOTOU,			//清老头,值为38
	TIANTING,			//天听,值为39
	QIQIANGYI,			//七抢一,值为40
	DASIXI,				//大四喜,值为41
	BAXIANGUOHAI,		//八仙过海,值为42
	TIANHU,				//天胡,值为43
	DIHU,				//地胡,值为44
	RENHU,				//人胡,值为45
	PENPENHU,			//碰碰胡,值为46
	PIHU,				//屁胡,值为47
	QIDUI,				//七对,值为48
	STYLE_NUM,
};

#endif