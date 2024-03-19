// MJ.cpp: implementation of the CMJ class.
//
//////////////////////////////////////////////////////////////////////

#include <time.h>
#include "StdAfx.h"
#include "Mj.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int nMjNum[70];
cmj::cmj()
{
	nCent[ZHUANGJIA] = 1;		//ׯ��
	nCent[MENQING] = 1;			//����
	nCent[ZIMO] = 1;				//����
	nCent[LIZHI] = 1;				//��ֱ
	nCent[GANGSHANGKAIHUA] = 1;	//���Ͽ���
	nCent[HAIDILAOYUE] = 1;		//��������
	nCent[HEDILAOYU] = 1;			//�ӵ�����
	nCent[HONGZHONGPAI] = 1;		//������
	nCent[FACAIPAI] = 1;			//�巢��
	nCent[BAIBANPAI] = 1;			//�װ���
	nCent[DONGFENFPAI] = 1;		//������
	nCent[XIFENGPAI] = 1;			//������
	nCent[NANFENGPAI] = 1;			//�Ϸ���
	nCent[BEIFENGPAI] = 1;			//������
	nCent[HUAPAI] = 1;				//����
	nCent[DUANYAOJIU] = 1;			//���۾�
	nCent[YIBEIKOU] = 1;			//һ����
	nCent[PINGHU] = 1;				//ƽ��
	nCent[QUANQIUREN] = 2;			//ȫ����
	nCent[YITIAOLONG] = 2;			//һ����
	nCent[SANANKE] = 2;			//������
	nCent[SANGANGZI] = 2;			//������
	nCent[HUNQUANDAIYAO] = 2;		//��ȫ����
	nCent[EBEIKOU] = 2;			//������
	nCent[SANSETONGSHUN] = 3;		//��ɫͬ˳
	nCent[SANSETONGKE] = 3;		//��ɫͬ��
	nCent[MENQINGZIMO] = 3;		//��������
	nCent[HUNYISE] = 4;			//��һɫ
	nCent[XIAOSANYUAN] = 4;		//С��Ԫ
	nCent[CUNQUANDAIYAO] = 4;		//��ȫ����
	nCent[HUNLAOTOU] = 4;			//����ͷ
	nCent[SIANKE] = 4;				//�İ���
	nCent[SIGANGZI] = 4;			//�ĸ���
	nCent[QINGYISE] = 8;			//��һɫ
	nCent[ZIYISE] = 8;				//��һɫ
	nCent[DASANYUAN] = 8;			//����Ԫ
	nCent[XIAOSIXI] = 8;			//С��ϲ
	nCent[WUANKE] = 8;				//�尵��
	nCent[QINLAOTOU] = 8;			//����ͷ
	nCent[TIANTING] = 16;			//����
	nCent[QIQIANGYI] = 16;			//����һ
	nCent[DASIXI] = 16;				//����ϲ
	nCent[BAXIANGUOHAI] = 16;		//���ɹ���
	nCent[TIANHU] = 32;				//���
	nCent[DIHU] = 32;				//�غ�
	nCent[RENHU] = 32;				//�˺�
	nCent[PENPENHU] = 4;			//������
	nCent[PIHU] = 5;				//ƨ��
	nCent[QIDUI] = 8;				//�߶�

	strcpy(csTaiName[ZHUANGJIA],"ׯ��");
	strcpy(csTaiName[MENQING],"����");
	strcpy(csTaiName[ZIMO],"����");
	strcpy(csTaiName[LIZHI],"��ֱ");
	strcpy(csTaiName[GANGSHANGKAIHUA],"���Ͽ���");
	strcpy(csTaiName[HAIDILAOYUE],"��������");
	strcpy(csTaiName[HEDILAOYU],"�ӵ�����");
	strcpy(csTaiName[HONGZHONGPAI],"������");
	strcpy(csTaiName[FACAIPAI],"�巢��");
	strcpy(csTaiName[BAIBANPAI],"�װ���");
	strcpy(csTaiName[DONGFENFPAI],"������");
	strcpy(csTaiName[XIFENGPAI],"������");
	strcpy(csTaiName[NANFENGPAI],"�Ϸ���");
	strcpy(csTaiName[BEIFENGPAI],"������");
	strcpy(csTaiName[HUAPAI],"����");
	strcpy(csTaiName[DUANYAOJIU],"���۾�");
	strcpy(csTaiName[YIBEIKOU],"һ����");
	strcpy(csTaiName[PINGHU],"ƽ��");
	strcpy(csTaiName[QUANQIUREN],"ȫ����");
	strcpy(csTaiName[YITIAOLONG],"һ����");
	strcpy(csTaiName[SANANKE],"������");
	strcpy(csTaiName[SANGANGZI],"������");
	strcpy(csTaiName[HUNQUANDAIYAO],"��ȫ����");
	strcpy(csTaiName[EBEIKOU],"������");
	strcpy(csTaiName[SANSETONGSHUN],"��ɫͬ˳");
	strcpy(csTaiName[SANSETONGKE],"��ɫͬ��");
	strcpy(csTaiName[MENQINGZIMO],"��������");
	strcpy(csTaiName[HUNYISE],"��һɫ");
	strcpy(csTaiName[XIAOSANYUAN],"С��Ԫ");
	strcpy(csTaiName[CUNQUANDAIYAO],"��ȫ����");
	strcpy(csTaiName[HUNLAOTOU],"����ͷ");
	strcpy(csTaiName[SIANKE],"�İ���");
	strcpy(csTaiName[SIGANGZI],"�ĸ���");
	strcpy(csTaiName[QINGYISE],"��һɫ");
	strcpy(csTaiName[ZIYISE],"��һɫ");
	strcpy(csTaiName[DASANYUAN],"����Ԫ");
	strcpy(csTaiName[XIAOSIXI],"С��ϲ");
	strcpy(csTaiName[WUANKE],"�尵��");
	strcpy(csTaiName[QINLAOTOU],"����ͷ");
	strcpy(csTaiName[TIANTING],"����");
	strcpy(csTaiName[QIQIANGYI],"����һ");
	strcpy(csTaiName[DASIXI],"����ϲ");
	strcpy(csTaiName[BAXIANGUOHAI],"���ɹ���");
	strcpy(csTaiName[TIANHU],"���");
	strcpy(csTaiName[DIHU],"�غ�");
	strcpy(csTaiName[RENHU],"�˺�");
	strcpy(csTaiName[PENPENHU],"������");
	strcpy(csTaiName[PIHU],"ƨ��");
	strcpy(csTaiName[QIDUI],"�߶�");
}

cmj::~cmj()
{

}

int  cmj::Begin(BYTE nbLevel)
{
//	nbZhuangjia = BEIJIA;
	nbRoundNum = 0;
	nbZhuangjia = DONGJIA;
	return(RoundBegin(nbLevel,DONGJIA));
}

BYTE cmj::RoundBegin(BYTE nbLevel,BYTE nbZhuang)
{
	int i,j,k;
	int random;
	BYTE nbMjOutHand[17],nbMjInHand[17],nbMjDownSea[17],nbMjDefined[17],nbMjAnGang[17];
	
	int nMjTmpNum[70] =	{0,4,4,4,4,4,4,4,4,4,
						 0,4,4,4,4,4,4,4,4,4,
						 0,4,4,4,4,4,4,4,4,4,
						 0,4,4,4,4,0,0,0,0,0,
						 0,4,4,4,0,0,0,0,0,0,
						 0,1,1,1,1,0,0,0,0,0,
						 0,1,1,1,1,0,0,0,0,0};
	BYTE nbGangDownSea[5];

	for(i=0;i<MAXGNUMINHAND;i++)	nbGangDownSea[i] = 0;
	for(i=0;i<70;i++)		nMjNum[i] = nMjTmpNum[i];

	int nProb = 50;
	srand((unsigned)time(NULL));
	for(i=0;i<4;i++)
	{
		if((nbZhuang+i)%4 == 0) nProb = 30;
		else nProb= 60;
		InitDefined(nbMjDefined);
		player[i].SetMjDefined(ZHANGSHU,nbMjDefined);
		for(j=0;j<ZHANGSHU/4;j++)
		{
			for(k=j*16+i*4;k<j*16+i*4+4;k++)
			{
				random = rand()%100;
				if(random <= nProb)
				{
					do{
						random = rand()%ZHANGSHU;
					}while(nbMjDefined[random] == INVALID);
					nbMjAll[k] = nbMjDefined[random];
					nbMjDefined[random] = INVALID;
				}
				else 
				{
					do{
						random = rand()%70;
					}while(nMjNum[random] == 0);
					nbMjAll[k] = random;
					nMjNum[random]--;
				}
			}
		}
		for(k=0;k<ZHANGSHU;k++)
		{
			if(nbMjDefined[k] != INVALID)
				nMjNum[nbMjDefined[k]] ++;
		}
	}
	for(i=(ZHANGSHU-1)*4;i<144;i++)
	{
		do{
			random = rand()%70;
		}while(nMjNum[random] <= 0);
		nbMjAll[i] = random;
		nMjNum[random] --;
	}
	nbStat = KAIJU;
	nbHeadNum = 0;
	nbTailNum = 143;
	nbStartNum = nbZhuangjia;
	if(nbZhuangjia != nbZhuang) 	nbZhuangjia = nbZhuangjia+1;
	if (nbZhuangjia>3)
	{
		nbRoundNum++;
	}
	nbNowPlayer = nbZhuangjia;
	for(i=0;i<4;i++)
	{
		player[i].SetMjInHand(0,nbMjInHand);
		player[i].SetMjOutHand(0,nbMjOutHand);
		player[i].SetMjDownSea(0,nbMjDownSea);
		player[i].SetMjAnGang(0,nbMjAnGang);
		player[i].SetGangDownSea(MAXGNUMINHAND,nbGangDownSea);
		player[i].SetTingpaiStat(0);
		player[i].SetHuapai(CHUN,0);player[i].SetHuapai(XIA,0);		
		player[i].SetHuapai(QIU,0);	player[i].SetHuapai(DONG,0);
		player[i].SetHuapai(MEI,0);player[i].SetHuapai(LAN,0);		
		player[i].SetHuapai(ZHU,0);	player[i].SetHuapai(JU,0);
		player[i].nbPlayerNum = i;
	}
	return 1;
}
BYTE cmj::GetZhuangjia()
{
	return nbZhuangjia;
}
BYTE cmj::InitDefined(BYTE * nbMjDefined)
{
	bool isValid;
	int randomid,randomid1,randomid2,i,nNum;
	BYTE nbTmpCode[3],nbMj[17];
	BYTE nbTmpNum;

	BYTE nbTmp[3][3] = {{-2,-1,0},{-1,0,1},{0,1,2}};
	isValid = false;
	srand((unsigned)time(NULL));

	nNum = -1;nbTmpNum = 0;
	while(nNum < ZHANGSHU-1)
	{
		nbTmpNum = 0;
		do{
			randomid = rand()%50;
			randomid1 = rand()%4;
			if(nMjNum[randomid] <= 0 || randomid1 >= nMjNum[randomid]) 
				isValid = false;
			else 
			{
				isValid = true;
				if(nNum == (ZHANGSHU/4)*4-2)
				{
					nbTmpCode[0] = randomid;nbTmpCode[1] = randomid;
					nbTmpCode[2] = INVALID;nbTmpNum = 2;
				}
				else 
				{
					nbTmpNum = 3;
					randomid1 = rand()%5;
					if(randomid1 != 0 && randomid <= 29)
					{
						if(nMjNum[randomid-2]+nMjNum[randomid-1] >= nMjNum[randomid+1]+nMjNum[randomid+2])
						{
							if(nMjNum[randomid-2] >= nMjNum[randomid+1])	randomid2 = 0;
							else randomid2 = 1;
						}
						else
						{
							if(nMjNum[randomid-1] >= nMjNum[randomid+2])    randomid2 = 1;
							else randomid2 = 2;
						}
						for(i=0;i<3;i++)	nbTmpCode[i] = nbTmp[randomid2][i]+randomid;	
					}
					else 
					{
						nbTmpCode[0] = randomid;nbTmpCode[1] = randomid;
						nbTmpCode[2] = randomid;
					}
				}
				for(i=0;i<nbTmpNum;i++)
				{
					nMjNum[nbTmpCode[i]] --;
					if(nMjNum[nbTmpCode[i]] < 0)  isValid = false;
				}
				for(i=0;i<nbTmpNum;i++)	nMjNum[nbTmpCode[i]]++;
			}
		}while(isValid != true);
		for(i=0;i<nbTmpNum;i++)
		{
			nNum ++;
			nbMj[nNum] = nbTmpCode[i];
			nMjNum[nbTmpCode[i]] --;
		}
	}
	for(i=0;i<ZHANGSHU;i++)
	{
		*nbMjDefined = nbMj[i];
		nbMjDefined++;
	}
	return ZHANGSHU;
}

BYTE cmj::GetStatus()
{
	return nbStat;
}

BYTE cmj::GetMJ(BYTE nbPlayer,BYTE nbNum,BYTE nbMj[17])
{
	BYTE ret;
	ret = INVALID;
	switch(nbNum)
	{
	case 0:
		ret = player[nbPlayer].GetMjDownSea(nbMj);
		break;
	case 1:
		ret = player[nbPlayer].GetMjInHand(nbMj);
		break;
	case 2:
		ret = player[nbPlayer].GetMjOutHand(nbMj);
		break;
	case 3:
		ret = player[nbPlayer].GetMjAnGang(nbMj);
		break;
	case 4:
		ret = player[nbPlayer].GetGangDownSea(nbMj);
		break;
	case 5:
		for(int i=0;i<8;i++)
			nbMj[i] = player[nbPlayer].GetHuapai(i);
		break;
	}
	return ret;
}
BYTE cmj::SetStatus(BYTE nbStatus)
{
	nbStat = nbStatus;
	return nbStat;
}

BYTE cmj::Buhua()
{
	int i,j;
	BYTE nbMjNum,nbMj[17];
		
	for(i=nbZhuangjia;i<nbZhuangjia+4;i++)
	{
		nbMjNum = player[i%4].GetMjInHand(nbMj);
		for(j=0;j<nbMjNum;j++)
		{
			if(nbMj[j] >= 51)	
			{
				player[i%4].SetHuapai(nbMj[j],1);
				while(nbMjAll[nbTailNum] >= 51)
					nbTailNum -- ;
				nbMj[j] = nbMjAll[nbTailNum];
				nbTailNum -- ;
			}
		}
		player[i%4].SortMj(nbMjNum,nbMj);
		player[i%4].SetMjInHand(nbMjNum,nbMj);
	}
	nbStat = DAPAI;
	nbLastPlayer = nbNowPlayer;
	nbLastPlayStat = XUANPAI;
	if(nbNowPlayer != 0) nbNowPlayStat = CHUPAI;	//�ǵ��ԣ�����
	else nbNowPlayStat = XUANPAI;	//���ˣ�ѡ��
	return 0;
}

BYTE cmj::Qipai()
{
	int i;
	BYTE nbMjNum,nbMj[17];
	BYTE ret;

	ret = INVALID;
	nbMjNum = player[nbNowPlayer].GetMjInHand(nbMj);	//�@ȡ������
	if(nbMjNum <= (ZHANGSHU/4-1)*4)						//����16��߀����ץ
	{
		ret = nbMjNum;
		for(i=0;i<4;i++)			//һ��ץ4��
		{					
			nbMj[nbMjNum+i] = nbMjAll[nbHeadNum+i];		//
		}
		nbMjNum += 4;
		nbHeadNum += 4;
		player[nbNowPlayer].SortMj(nbMjNum,nbMj);	//������
		player[nbNowPlayer].SetMjInHand(nbMjNum,nbMj);		//�Ż�����
		nbNowPlayer = (nbNowPlayer+1)%4;		//��ǰ���=��һ���
	}
	else if(nbMjNum == ZHANGSHU-1 && nbNowPlayer == nbZhuangjia)	//�f�Ҷ�ץһ�������ƽY��	
	{
		ret = nbMjNum;
		nbMj[nbMjNum ] = nbMjAll[nbHeadNum];
		nbMjNum ++;
		nbHeadNum ++;
		player[nbNowPlayer].SortMj(nbMjNum,nbMj);
		player[nbNowPlayer].SetMjInHand(nbMjNum,nbMj);
		nbStat = BUHUA;
	}
	else if(nbMjNum == ZHANGSHU-2)
	{
		ret = nbMjNum;
		nbMj[nbMjNum] = nbMjAll[nbHeadNum];
		nbMjNum ++;
		nbHeadNum ++;
		player[nbNowPlayer].SortMj(nbMjNum,nbMj);
		player[nbNowPlayer].SetMjInHand(nbMjNum,nbMj);
		nbNowPlayer = (nbNowPlayer+1)%4;

	}
	return ret;
}

BYTE cmj::WanZhuang(BYTE nbStat)
{
//	BYTE ret;
	if(nbStat == 1 && nbLastPlayer != nbZhuangjia) 	
		RoundBegin(3,(nbZhuangjia+1)%4);
	else RoundBegin(3,nbZhuangjia);
	return 1;
}
BYTE cmj::Kaiju(BYTE& nbGuzi1,BYTE& nbGuzi2)
{
	int random;

	srand((unsigned)time(NULL));
	random = rand();
	nbGuzi1 = random%6+1;
	random = rand();
	nbGuzi2 = random%6+1;
	
	nbStartNum = nbGuzi1 + nbGuzi2;
	nbStat = QIPAI;
	nbNowPlayer = nbZhuangjia;
//	nbZhuangjia = nbZhuang;
//	nbLastPlayer = INVALID;
	return nbStartNum;
}

BYTE cmj::GetNum(BYTE & nbStart,BYTE & nbHead, BYTE& nbTail)
{
	nbStart = nbStartNum; 
	nbHead = nbHeadNum;
	nbTail = nbTailNum;
	return 0;
}

BYTE cmj::GetCipaiStat(BYTE nbPlayer,BYTE nbLast,BYTE nbCode,BYTE &nbChipaiStat)
{
	return player[nbPlayer].adjustCipai(nbLast,nbCode,nbChipaiStat);
}

BYTE cmj::GetGangpaiStat(BYTE nbPlayer,BYTE nbLast,BYTE nbCode,BYTE &nbGangpaiNum,
						 BYTE nbGangpaiCode[5],BYTE nbGangpaiStat[5])
{
	return player[nbPlayer].adjustGangpai(nbLast,nbCode,nbGangpaiNum,nbGangpaiCode,
											nbGangpaiStat);
}

BYTE cmj::GetPostCode()
{
	return nbPostCode;
}
void cmj::GetButtonStat(BYTE nbButtonStat[5])
{
	BYTE Stat;
	BYTE nbTmpCode[5],nbTmpNum,nbTmpStat[5];

	for(int i = 0;i<5;i++)	nbButtonStat[i] = DISABLED;
	Stat = player[0].GetTingpaiStat();
	if(Stat != 0)	
	{
		nbButtonStat[TINGPAI-1] = PUSHED;
		if(Stat == 2)
			if(player[0].adjustHepai(nbLastPlayer,nbPostCode) == 1)
			{
				nbButtonStat[HUPAI-1] = ENABLED;
			}
	}
	else 
	{
		if(player[0].adjustTingpai() == 1)
			nbButtonStat[TINGPAI-1] = ENABLED;
		if(player[0].adjustCipai(nbLastPlayer,nbPostCode,nbTmpStat[0]) == 1)
		{
			nbButtonStat[CHIPAI-1] = ENABLED;
		}
		if(player[0].adjustPenpai(nbLastPlayer,nbPostCode) == 1)
		{
			nbButtonStat[PENPAI-1] = ENABLED;
		}
		if(player[0].adjustHepai(nbLastPlayer,nbPostCode) == 1)
		{
			nbButtonStat[HUPAI-1] = ENABLED;
		}
		if(player[0].adjustGangpai(nbLastPlayer,nbPostCode,nbTmpNum,nbTmpCode,nbTmpStat) == 1)
		{
			nbButtonStat[GANGPAI-1] = ENABLED;
		}
	}
}

BYTE cmj::GetNowPlayerStat()
{
	return nbNowPlayStat;
}

//���ص�ǰ���
BYTE cmj::SetNowPlayerStat(bool isButtonValid)
{
	BYTE nbChipaiStat;
	BYTE nbGangpaiNum,nbGangpaiStat[5],nbGangpaiCode[5];

	nbNowPlayStat = INVALID;
	if(nbLastPlayStat == MOPAI)
	{
		nbNowPlayer = nbLastPlayer;
		if(nbPostCode >= 51) 	
		{
			nbNowPlayStat = BUPAI;
			player[nbLastPlayer].SetHuapai(nbPostCode,1);
		}
		else  
		{
			if(player[nbLastPlayer].GetTingpaiStat() == 2 && player[nbLastPlayer].adjustHepai(nbLastPlayer,nbPostCode) != 1)
				 nbNowPlayStat = CHUPAI;
			else if(nbLastPlayer == 0)
			{
				nbNowPlayStat = XUANPAI;
			}
			else 
			{
				if(player[nbLastPlayer].adjustHepai(nbLastPlayer,nbPostCode) == 1)
					nbNowPlayStat = HUPAI;
				else if(player[nbLastPlayer].adjustGangpai(nbLastPlayer,nbPostCode,nbGangpaiNum,nbGangpaiCode,nbGangpaiStat) == 1)
					nbNowPlayStat = GANGPAI;
				else 
				{
					nbNowPlayStat = CHUPAI;
					if(player[nbLastPlayer].GetTingpaiStat() == 0)
						if(player[nbLastPlayer].adjustTingpai() == 1)
							player[nbLastPlayer].Tingpai();
				}

			}
		}
	}
	else if(nbLastPlayStat == GANGPAI)
	{
		nbNowPlayer = nbLastPlayer;
		nbNowPlayStat = BUPAI;
	}
	else if(nbLastPlayStat == BUPAI)
	{
		nbNowPlayer = nbLastPlayer;
		if(nbPostCode >= 51) 
		{
			nbNowPlayStat = BUPAI;
			player[nbLastPlayer].SetHuapai(nbPostCode,1);
		}
		else 
		{
			if(player[nbLastPlayer].GetTingpaiStat() == 2) nbNowPlayStat = CHUPAI;
			else if(nbLastPlayer == 0)
			{
				nbNowPlayStat = XUANPAI;
			}
			else 
			{
				if(player[nbLastPlayer].adjustHepai(nbLastPlayer,nbPostCode) == 1)
					nbNowPlayStat = HUPAI;
				else  if(player[nbLastPlayer].adjustGangpai(nbLastPlayer,nbPostCode,nbGangpaiNum,nbGangpaiCode,nbGangpaiStat) == 1)
					nbNowPlayStat = GANGPAI;
				else 
				{
					nbNowPlayStat = CHUPAI;
					if(player[nbLastPlayer].GetTingpaiStat() == 0)
						if(player[nbLastPlayer].adjustTingpai() == 1)
							player[nbLastPlayer].Tingpai();
				}
			}
		}
	}
	else if(nbLastPlayStat == CHIPAI || nbLastPlayStat == PENPAI)
	{
		nbNowPlayer = nbLastPlayer;
		if(player[nbLastPlayer].GetTingpaiStat() == 2) nbNowPlayStat = CHUPAI;
		else if(nbLastPlayer == 0)  nbNowPlayStat = XUANPAI;
		else 
		{
			nbNowPlayStat = CHUPAI;
			if(player[nbLastPlayer].GetTingpaiStat() == 0)
				if(player[nbLastPlayer].adjustTingpai() == 1)
					player[nbLastPlayer].Tingpai();
		}
	}
	else if(nbLastPlayStat == CHUPAI)
	{
		int ret;
		if(player[nbLastPlayer].GetTingpaiStat() == 1)
			if(player[nbLastPlayer].adjustTingpai() == 1)
					player[nbLastPlayer].Tingpai();
		for(int i=nbLastPlayer+1;i<nbLastPlayer+4;i++)
		{
			if(isButtonValid && i%4 == 0) continue;
			if(player[i%4].adjustHepai(nbLastPlayer,nbPostCode) == 1 && nbNowPlayStat == INVALID)
			{
				ret = i%4;
				if(ret == 0)  nbNowPlayStat = XUANPAI;
				else          nbNowPlayStat = HUPAI;
				break;
			}
		}
		for(int i=nbLastPlayer+1;i<nbLastPlayer+4;i++)
		{
			if(isButtonValid && i%4 == 0) continue;
			if(player[i%4].GetTingpaiStat() != 0) continue;
			if(player[i%4].adjustGangpai(nbLastPlayer,nbPostCode,nbGangpaiNum,nbGangpaiCode,nbGangpaiStat) == 1 && nbNowPlayStat == INVALID)
			{
				ret = i%4;
				if(ret == 0)  nbNowPlayStat = XUANPAI;
				else   nbNowPlayStat = GANGPAI;
			}
			if(player[i%4].adjustPenpai(nbLastPlayer,nbPostCode) == 1 && nbNowPlayStat == INVALID)
			{
				ret = i%4;
				if(ret == 0)  nbNowPlayStat = XUANPAI;
				else   nbNowPlayStat = PENPAI;
			}
		}
		if(nbNowPlayStat == INVALID && player[(nbLastPlayer+1)%4].adjustCipai(nbLastPlayer,nbPostCode,nbChipaiStat) != 0
			&& player[(nbLastPlayer+1)%4].GetTingpaiStat() == 0)
		{
			if(!(isButtonValid && (nbLastPlayer+1)%4 == 0)) 
			{
				ret = (nbLastPlayer+1)%4;
				if(ret == 0)  nbNowPlayStat = XUANPAI;
				else nbNowPlayStat = CHIPAI;
			}
		}
		if(nbNowPlayStat == INVALID)
		{
			ret = (nbLastPlayer+1)%4;
			nbNowPlayStat = MOPAI;
		}
		nbNowPlayer = ret;
	}
	if(nbNowPlayStat == INVALID) nbNowPlayStat = nbLastPlayStat;
	return nbNowPlayer;
}

BYTE cmj::GetLastPlayer()
{
	return nbLastPlayer;
}

BYTE cmj::GetNowPlayer()
{
	return nbNowPlayer;
}

BYTE cmj::SetNowPlayer(BYTE nbPlayer)
{
	nbNowPlayer = nbPlayer;
	return nbNowPlayer;
}
BYTE cmj::SetLastPlayer(BYTE nbPlayer)
{
	nbLastPlayer = nbPlayer;
	return nbLastPlayer;
}
BYTE cmj::GetLastPlayStat()
{
	return nbLastPlayStat;
}
BYTE cmj::GetNowPlayStat()
{
	return nbNowPlayStat;
}

BYTE cmj::play(
			   BYTE nbPlayerNum,		//��ǰ���
			   BYTE nbStatus,			//��ǰ��Ҡ�B
			   BYTE m_ncSelectedNum		//�ϴβ�������
			   )
{
	BYTE nbChipai,ret;
	BYTE nbGangpaiNum,nbGangpaiCode[5],nbGangpaiStat[5];
	BYTE nbtmpNum,nbtmpMj[17],nbtmpGang[5];
	BYTE TmpMjNum[70] =	{0,4,4,4,4,4,4,4,4,4,
						 0,4,4,4,4,4,4,4,4,4,
						 0,4,4,4,4,4,4,4,4,4,
						 0,4,4,4,4,0,0,0,0,0,
						 0,4,4,4,0,0,0,0,0,0,
						 0,1,1,1,1,0,0,0,0,0,
						 0,1,1,1,1,0,0,0,0,0};
	int i,j;

	ret = 0;
	if(nbStatus == MOPAI)
	{
		ret = player[nbPlayerNum].Mopai(nbMjAll[nbHeadNum]);
		nbHeadNum ++;
		nbLastPlayStat = MOPAI;
	}
	else if(nbStatus == BUPAI && nbHeadNum < nbTailNum)
	{
		ret = player[nbPlayerNum].Bupai(nbMjAll[nbTailNum]);
		nbTailNum --;
		nbLastPlayStat = BUPAI;
	}
	else if(nbStatus == GANGPAI && nbHeadNum < nbTailNum)
	{
		if(nbPlayerNum != 0)
		{
			player[nbPlayerNum].adjustGangpai(nbLastPlayer,nbPostCode,nbGangpaiNum,nbGangpaiCode,nbGangpaiStat);
			ret = player[nbPlayerNum].Gangpai(nbLastPlayer,nbGangpaiCode[0]);
		}
		else if(nbPlayerNum == 0)
		{
			ret = player[nbPlayerNum].Gangpai(nbLastPlayer,m_ncSelectedNum);
		}
		if(nbPlayerNum != nbLastPlayer) 
		{
			nbtmpNum = player[nbLastPlayer].GetMjOutHand(nbtmpMj);
			player[nbLastPlayer].SetMjOutHand(nbtmpNum-1,nbtmpMj);
		}
		nbLastPlayStat = GANGPAI;
	}
	else if(nbStatus == CHIPAI) 
	{
		if(nbPlayerNum != 0)
		{
			player[nbPlayerNum].adjustCipai(nbLastPlayer,nbPostCode,nbChipai);
			ret = player[nbPlayerNum].Chipai(nbPostCode,nbChipai);
		}
		else if(nbPlayerNum == 0)
		{
			ret = player[0].Chipai(nbPostCode,m_ncSelectedNum);
		}
		if(nbPlayerNum != nbLastPlayer) 
		{
			nbtmpNum = player[nbLastPlayer].GetMjOutHand(nbtmpMj);
			player[nbLastPlayer].SetMjOutHand(nbtmpNum-1,nbtmpMj);
		}
		nbLastPlayStat = CHIPAI;
	}
	else if(nbStatus == PENPAI)
	{
		ret = player[nbPlayerNum].Penpai(nbPostCode);
		nbLastPlayStat = PENPAI;
		if(nbPlayerNum != nbLastPlayer) 
		{
			nbtmpNum = player[nbLastPlayer].GetMjOutHand(nbtmpMj);
			player[nbLastPlayer].SetMjOutHand(nbtmpNum-1,nbtmpMj);
		}
	}
	else if(nbStatus == CHUPAI)
	{
		if(player[nbPlayerNum].GetTingpaiStat() == 2)
		{
			nbtmpNum = player[nbPlayerNum].GetMjInHand(nbtmpMj);
			ret = player[nbPlayerNum].Chupai(nbtmpNum-1);
		}
		else if(nbPlayerNum != 0)		
		{
			for(i=0;i<4;i++)
			{
				nbtmpNum = player[i].GetMjOutHand(nbtmpMj);
				for(j=0;j<nbtmpNum;j++)		TmpMjNum[nbtmpMj[j]] -- ;
				nbtmpNum = player[i].GetMjDownSea(nbtmpMj);
				player[i].GetGangDownSea(nbtmpGang);
				for(j=0;j<nbtmpNum;j++)
				{
					TmpMjNum[nbtmpMj[j]] -- ;
					if(nbtmpGang[j/3] == 1 && nbtmpMj[j] == nbtmpMj[j+1] && nbtmpMj[j] == nbtmpMj[j+2]) 
						TmpMjNum[nbtmpMj[j]] -- ;
				}
			}
			ret = player[nbPlayerNum].adjustChupaiNum(TmpMjNum);
			ret = player[nbPlayerNum].Chupai(ret);
		}
		else	ret = player[0].Chupai(m_ncSelectedNum);
		if(player[nbPlayerNum].GetTingpaiStat() == 1)
			player[nbPlayerNum].Tingpai();
		nbLastPlayStat = CHUPAI;
	}
	else if(nbStatus == HUPAI)
	{
		ret = player[nbPlayerNum].HUPAI(nbLastPlayStat,nbLastPlayer,nbPostCode);
		calcTaiShu(nbLastPlayStat,nbPlayerNum,nbLastPlayer,nbPostCode);
		nbStat = WANZHUANG;
	}
	else if(nbStatus == TINGPAI)
	{
		ret = player[nbPlayerNum].Tingpai();
	}
	nbLastPlayer = nbPlayerNum;
	if(nbStatus != TINGPAI) nbPostCode = ret;
	if(nbStatus != HUPAI && nbStatus != TINGPAI) 	SetNowPlayerStat(false);
	return ret;
}

int cmj::calcTaiShu(
					BYTE nbStatus,			//�ϴ���Ҡ�B
					BYTE nbPlayerNum,		//��ǰ���
					BYTE nbLast,			//�ϴ���� 
					BYTE nbCode				//�ϴβ�������
					)
{
	//int i,j;
	player[nbPlayerNum].calcPaiXin(nbStatus,nbLast,nbCode);
	player[nbPlayerNum].GetPaiXin(nbPaiXin);
	if(nbPlayerNum == nbZhuangjia || nbLast == nbZhuangjia)	
		nbPaiXin[ZHUANGJIA] = 1;
	return 1;
}

BYTE cmj::GetPaiXin(BYTE *nbPai)
{
	BYTE ret = 0;
	int i;

	for(i=0;i<PAIXINGSUM;i++)
	{
		*(nbPai+i) = nbPaiXin[i];
		if(nbPaiXin[i] == 1)
		{
			ret += nCent[i];
		}
	}
	return ret;
}
