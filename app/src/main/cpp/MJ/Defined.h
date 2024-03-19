#ifndef DEFINED_H
#define DEFINED_H
#define INVALID 255
#define PAIXINGSUM 49

extern int ZHANGSHU, MAXGNUM, MAXGNUMINHAND,MAXSHU;

//�����齫�Ƶ��ƺ�
enum{
	YIWAN	=	1,		//һ��,ֵΪ1  
	LIANGWAN,			//����,ֵΪ2
	SANWAN,				//����,ֵΪ3
	SIWAN,				//����,ֵΪ4
	WUWAN,				//����,ֵΪ5
	LIUWAN,				//����,ֵΪ6
	QIWAN,				//����,ֵΪ7
	BAWAN,				//����,ֵΪ8
	JIUWAN,				//����,ֵΪ9

	YITIAO	=	11,		//һ��,ֵΪ11
	LIANGTIAO,			//����,ֵΪ12
	SANTIAO,			//����,ֵΪ13
	SITIAO,				//����,ֵΪ14
	WUTIAO,				//����,ֵΪ15
	LIUTIAO,			//����,ֵΪ16
	QITIAO,				//����,ֵΪ17
	BATIAO,				//����,ֵΪ18
	JIUTIAO,			//����,ֵΪ19

	YITONG	=	21,		//һͲ,ֵΪ21
	LIANGTONG,			//��Ͳ,ֵΪ22
	SANTONG,			//��Ͳ,ֵΪ23
	SITONG,				//��Ͳ,ֵΪ24
	WUTONG,				//��Ͳ,ֵΪ25
	LIUTONG,			//��Ͳ,ֵΪ26
	QITONG,				//��Ͳ,ֵΪ27
	BATONG,				//��Ͳ,ֵΪ28
	JIUTONG,			//��Ͳ,ֵΪ29

	DONGFENG =	31,		//����,ֵΪ31
	NANFENG,			//�Ϸ�,ֵΪ32
	XIFENG,				//����,ֵΪ33
	BEIFENG,			//����,ֵΪ34

	HONGZHONG = 41,		//����,ֵΪ41
	FACAI,				//�෢,ֵΪ42
	BAIBAN,				//�װ�,ֵΪ43

	MEI		  = 51,		//÷,ֵΪ51
	LAN	,				//��,ֵΪ52
	ZHU ,				//��,ֵΪ53
	JU	,				//��,ֵΪ54

	CHUN	 = 61,		//��,ֵΪ61
	XIA	,				//��,ֵΪ62
	QIU ,				//��,ֵΪ63
	DONG,				//��,ֵΪ64
};

//�����ƾ�״̬
enum{
	KAIJU    = 0,		//����,ֵΪ0
	QIPAI,				//����,ֵΪ1
	BUHUA,				//����,ֵΪ2
	DAPAI,				//����,ֵΪ3
	WANZHUANG,			//��ׯ,ֵΪ4
};

//�����������״̬
enum{
	MOPAI	= 0,		//����,ֵΪ0
	CHIPAI,				//����,ֵΪ1
	PENPAI,				//����,ֵΪ2
	GANGPAI,			//����,ֵΪ3
	HUPAI,				//����,ֵΪ4
	TINGPAI,			//����,ֵΪ5
	BUPAI,				//����,ֵΪ6
	CHUPAI,				//����,ֵΪ7
	XUANPAI,			//ѡ��,	ֵΪ8
};

//���尴ť״̬
enum{
	ENABLED = 1,		//����,ֵΪ1
	PUSHED,				//����,ֵΪ2
	DISABLED,			//����,ֵΪ3
};

//�������״̬
enum{
	ANGANG = 0,			//����,ֵΪ0
	MINGGANG,			//����,ֵΪ1
};

//����������
enum{
	DONGJIA = 0,		//����,����,ֵΪ0
	NANJIA,				//�ϼ�,ֵΪ1
	XIJIA,				//����,ֵΪ2
	BEIJIA,				//����,ֵΪ3
};

//�����Ƶ�����,��view���޹�
enum{
	JIANGPAI = 0,		//����
	KEZI	 ,			//����
	GANGZI   ,			//����
	SHUNZI	 ,			//˳��
};

//��������
enum{
	ZHUANGJIA = 0,		//ׯ��,ֵΪ0
	MENQING ,			//����,ֵΪ1
	ZIMO,				//����,ֵΪ2
	LIZHI,				//��ֱ,ֵΪ3
	GANGSHANGKAIHUA,	//���Ͽ���,ֵΪ4
	HAIDILAOYUE,		//��������,ֵΪ5
	HEDILAOYU,			//�ӵ�����,ֵΪ6
	HONGZHONGPAI,		//������,ֵΪ7
	FACAIPAI,			//�巢��,ֵΪ8
	BAIBANPAI,			//�װ���,ֵΪ9
	DONGFENFPAI,		//������,ֵΪ10
	XIFENGPAI,			//������,ֵΪ11
	NANFENGPAI,			//�Ϸ���,ֵΪ12
	BEIFENGPAI,			//������,ֵΪ13
	HUAPAI,				//����,ֵΪ14
	DUANYAOJIU,			//���۾�,ֵΪ15
	YIBEIKOU,			//һ����,ֵΪ16
	PINGHU,				//ƽ��,ֵΪ17
	QUANQIUREN,			//ȫ����,ֵΪ18
	YITIAOLONG,			//һ����,ֵΪ19
	SANANKE,			//������,ֵΪ20
	SANGANGZI,			//������,ֵΪ21
	HUNQUANDAIYAO,		//��ȫ����,ֵΪ22
	EBEIKOU,			//������,ֵΪ23
	SANSETONGSHUN,		//��ɫͬ˳,ֵΪ24
	SANSETONGKE,		//��ɫͬ��,ֵΪ25
	MENQINGZIMO,		//��������,ֵΪ26
	HUNYISE,			//��һɫ,ֵΪ27
	XIAOSANYUAN,		//С��Ԫ,ֵΪ28
	CUNQUANDAIYAO,		//��ȫ����,ֵΪ29
	HUNLAOTOU,			//����ͷ,ֵΪ30
	SIANKE,				//�İ���,ֵΪ31
	SIGANGZI,			//�ĸ���,ֵΪ32
	QINGYISE,			//��һɫ,ֵΪ33
	ZIYISE,				//��һɫ,ֵΪ34
	DASANYUAN,			//����Ԫ,ֵΪ35
	XIAOSIXI,			//С��ϲ,ֵΪ36
	WUANKE,				//�尵��,ֵΪ37
	QINLAOTOU,			//����ͷ,ֵΪ38
	TIANTING,			//����,ֵΪ39
	QIQIANGYI,			//����һ,ֵΪ40
	DASIXI,				//����ϲ,ֵΪ41
	BAXIANGUOHAI,		//���ɹ���,ֵΪ42
	TIANHU,				//���,ֵΪ43
	DIHU,				//�غ�,ֵΪ44
	RENHU,				//�˺�,ֵΪ45
	PENPENHU,			//������,ֵΪ46
	PIHU,				//ƨ��,ֵΪ47
	QIDUI,				//�߶�,ֵΪ48
	STYLE_NUM,
};

#endif