// MJPLAYER.h: interface for the CMJPLAYER class.
//
//////////////////////////////////////////////////////////////////////

#include "Defined.h"

class cmjplayer  
{
public:
	cmjplayer();
	virtual ~cmjplayer();
public:
	BYTE adjustHepai(BYTE nbPlayerNum,BYTE nbMjCode);
	BYTE adjustPenpai(BYTE nbPlayerNum,BYTE nbMjCode);
	BYTE adjustCipai(BYTE nbPlayerNum,BYTE nbMjCode,BYTE &nbChipaiStat);
	BYTE adjustGangpai(BYTE nbLastNum,BYTE nbMjCode,
						BYTE& nbGangpaiNum,BYTE nbGangpaiCode[5],BYTE nbGangpaiStat[5]);
	BYTE adjustTingpai();
	BYTE adjustChupaiNum(BYTE nbMjNum[70]);
	BYTE Chipai(BYTE nbCode,BYTE nbChipaiStat);
	BYTE HUPAI(BYTE nbStatus,BYTE nbLast,BYTE nbCode);
	BYTE Penpai(BYTE nbCode);
	BYTE Gangpai(BYTE nbLast,BYTE nbCode);
	BYTE Chupai(BYTE m_ncSelectedNum);
	BYTE Tingpai();
	BYTE Mopai(BYTE nbCode);
	BYTE Bupai(BYTE nbCode);

	BYTE GetTingpaiStat();
	BYTE SetTingpaiStat(BYTE stat);
	BYTE GetMjInHand(BYTE * nbInHand);
	BYTE GetMjDefined(BYTE * nbDefined);
	BYTE GetMjDownSea(BYTE * nbDownSea);
	BYTE GetMjOutHand(BYTE * nbOutHand);
	BYTE GetMjAnGang(BYTE * nbAnGang);
	BYTE GetGangDownSea(BYTE * nbGangDownSea);
	BYTE GetPaiXin(BYTE * nbPai);
	BYTE SetMjInHand(BYTE nbNum,BYTE * nbInHand);
	BYTE SetMjDefined(BYTE nbNum,BYTE * nbDefined);
	BYTE SetMjOutHand(BYTE nbNum,BYTE * nbOutHand);
	BYTE SetMjDownSea(BYTE nbNum,BYTE * nbDownSea);
	BYTE SetMjAnGang(BYTE nbNum,BYTE *nbAnGang);
	BYTE SetGangDownSea(BYTE nbNum,BYTE * nbGangDownSea);
	BYTE GetPlayStat();
	BYTE SetPlayStat(BYTE nbStat);
	void SortMj(BYTE nbNum,BYTE *nbMj);
	BYTE findMj(BYTE nbNum,BYTE *nbMj,BYTE  nbMjCode);
	int  calcPaiXin(BYTE nbStatus,BYTE nbLastPlayer,BYTE nbCode);
	BYTE SetHuapai(BYTE nbNum,BYTE nbValue);
	BYTE GetHuapai(BYTE nbNum);
	BYTE		nbPlayerNum;
private:
	BYTE        nbHuapai[8];
	BYTE		nbMjInHand[17];
	BYTE		nbMjDefined[17];
	BYTE		nbNumInHand;
	BYTE		nbMjDownSea[17];
	BYTE		nbGangDownSea[5];
	BYTE		nbNumDownSea;
	BYTE        nbMjAnGang[5];
	BYTE		nbNumAnGang;
	BYTE		nbMjOutHand[25];
	BYTE		nbNumOutHand;
	BYTE		nbPaiXin[100];
	BYTE		nbTingPaiStat;
	
	BYTE		adjustQingyiSe(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);			//整理牌型的函数
	BYTE		adjustPenpenHu(BYTE nbGroupDownSea[6],BYTE nbLast,BYTE nbCode,BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE		adjustFengPai(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE		adjustYitiaoLong(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE		adjustEbeiKou(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE		adjustSanSe(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE		adjustDuanyaoJiu(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE		adjustSanyuanPai(BYTE nbMjCode,BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6]);
	BYTE        adjustMenQing(BYTE nbGroupDownSea[6]);

	BYTE		findMjGroup(BYTE nbNum,BYTE * nbMj,BYTE *nbGNum,BYTE *nbGroupStat,BYTE *nbGroupColor,BYTE *nbGroupNum,BYTE *nbMjGroup);
	/*搜索牌组*/
	BYTE		findMjUnGrouped(BYTE nbTmpNumInHand,BYTE nbTmpMjInHand[17],
								BYTE& nbNumSeq,BYTE nbMjSeq[10],BYTE& nbNumDouble,BYTE nbMjDouble[10],
								BYTE& nbNumInterv,BYTE nbMjInterv[10],BYTE& nbNumSingle,BYTE nbMjSingle[17]);
	/*搜索未成组牌数目*/
	BYTE		findMjGroupNum(BYTE& nbTmpNumInHand,BYTE nbTmpMjInHand[17],BYTE nbGroupStat[6]);
	/*得到成组牌数目*/
	BYTE		modifyMjDefined(BYTE nbTmpNumInHand,BYTE nbTmpMjInHand[17],BYTE nbCodeStat[6]);
	BYTE		findSeq(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp);
	BYTE		findjiang(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp);
	BYTE		findPen(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp);
	BYTE		findGang(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp);
};
