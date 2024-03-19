// MJPLAYER.cpp: implementation of the CMJPLAYER class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Mjplayer.h"

cmjplayer::cmjplayer()
{
}

cmjplayer::~cmjplayer()
{
}

BYTE cmjplayer::SetMjDownSea(BYTE nbNum,BYTE * nbMj)
{
	int i;
	nbNumDownSea = nbNum;
	for(i=0;i<nbNumDownSea;i++)
	{
		nbMjDownSea[i] = *nbMj;
		nbMj ++;
	}
	return nbNumDownSea;
}

BYTE cmjplayer::SetGangDownSea(BYTE nbNum,BYTE *nbGangDownSea)
{
	int i;
	for(i=0;i<nbNum;i++)
	{
		nbMjDownSea[i] = *nbGangDownSea;
		nbGangDownSea ++;
	}
	return nbNum;
}

BYTE cmjplayer::SetMjInHand(BYTE  nbNum,BYTE * nbMj)
{
	int i;
	nbNumInHand = nbNum;
	for(i=0;i<nbNumInHand;i++)
	{
		nbMjInHand[i] = *nbMj;
		nbMj ++;
	}
	return nbNumInHand;
}

BYTE cmjplayer::SetMjDefined(BYTE  nbNum,BYTE * nbMj)
{
	int i;
	for(i=0;i<nbNum;i++)
	{
		nbMjDefined[i] = *nbMj;
		nbMj ++;
	}
	return nbNum;
}

BYTE cmjplayer::SetMjOutHand(BYTE  nbNum,BYTE * nbMj)
{
	int i;
	nbNumOutHand = nbNum;
	for(i=0;i<nbNumOutHand;i++)
	{
		nbMjOutHand[i] = *nbMj;
		nbMj ++;
	}
	return nbNumOutHand;
}

BYTE cmjplayer::SetMjAnGang(BYTE nbNum,BYTE * nbMj)
{
	int i;
	nbNumAnGang = nbNum;
	for(i=0;i<nbNumAnGang;i++)
	{
		nbMjAnGang[i] = *nbMj;
		nbMj ++;
	}
	return nbNumAnGang;
}

BYTE cmjplayer::GetMjDownSea(BYTE * nbMj)
{
	int i;
	for(i=0;i<nbNumDownSea;i++)
	{
		*nbMj = nbMjDownSea[i];
		nbMj ++;
	}
	return nbNumDownSea;
}

BYTE cmjplayer::GetGangDownSea(BYTE * nbMj)
{
	int i;
	for(i=0;i<MAXGNUMINHAND;i++)
	{
		*nbMj = nbGangDownSea[i];
		nbMj ++;
	}
	return MAXGNUMINHAND;
}

BYTE cmjplayer::GetMjInHand(BYTE * nbMj)
{
	int i;
	for(i=0;i<nbNumInHand;i++)
	{
		*nbMj = nbMjInHand[i];
		nbMj ++;
	}
	return nbNumInHand;
}

BYTE cmjplayer::GetMjDefined(BYTE * nbMj)
{
	int i;
	for(i=0;i<ZHANGSHU;i++)
	{
		*nbMj = nbMjDefined[i];
		nbMj ++;
	}
	return ZHANGSHU;
}

BYTE cmjplayer::GetMjOutHand(BYTE * nbMj)
{
	int i;
	for(i=0;i<nbNumOutHand;i++)
	{
		*nbMj = nbMjOutHand[i];
		nbMj ++;
	}
	return nbNumOutHand;
}

BYTE cmjplayer::GetTingpaiStat()
{
	return nbTingPaiStat;
}

BYTE cmjplayer::SetTingpaiStat(BYTE stat)
{
	nbTingPaiStat = stat;
	return nbTingPaiStat;
}

BYTE cmjplayer::GetMjAnGang(BYTE * nbMj)
{
	int i;
	for(i=0;i<nbNumAnGang;i++)
	{
		*nbMj = nbMjAnGang[i];
		nbMj ++;
	}
	return nbNumAnGang;
}

void cmjplayer::SortMj(BYTE nbNum,BYTE *nbMj)
{
	int i,j,tmp;
	
	for(i=0;i<nbNum;i++)
	{
		for(j=0;j<nbNum-1;j++)
		{
			if(*(nbMj+j)>*(nbMj+j+1))
			{
				tmp = *(nbMj+j) ;
				*(nbMj+j) = *(nbMj+j+1);
				*(nbMj+j+1) = tmp;
			}
		}
	}
}

BYTE cmjplayer::adjustTingpai()
{
	int i,j;
	BYTE ret;
	BYTE tmpMj;
	ret = 0;
	for(i=0;i<nbNumInHand;i++)
	{
		tmpMj = nbMjInHand[i];
		for(j=1;j<=43;j++) 
		{
			if(j%10 == 0 || j>=35 && j<= 39) continue;
			nbMjInHand[i] = j;
			if(adjustHepai(nbPlayerNum,j) == 1)
				ret = 1;
		}
		nbMjInHand[i] = tmpMj;
	}
	return ret;
}

BYTE cmjplayer::adjustHepai(BYTE nbLastNum,BYTE nbMjCode)
{
	int i;
	BYTE ret,nbGNum,nbTmpNum;
	BYTE nbTmpGroup[18],nbGroupStat[6],nbGroupColor[6],nbGroupNum[6];
	BYTE nbTmpCode[17];
	for(i=0;i<ZHANGSHU;i++)	nbTmpCode[i] = 0;

	for(i=0;i<nbNumInHand;i++)		nbTmpCode[i] = nbMjInHand[i];
	if(nbLastNum != nbPlayerNum)
	{
		nbTmpCode[nbNumInHand] = nbMjCode;
		nbTmpNum = nbNumInHand+1;
	}
	else nbTmpNum = nbNumInHand;
	SortMj(nbTmpNum,nbTmpCode);
	nbGNum = 0;
	if(findMjGroup(nbTmpNum,nbTmpCode,&nbGNum,nbGroupNum,nbGroupColor,nbGroupStat,nbTmpGroup) == 1)
	{
		ret = 1;
	}
	else 
	{
		BYTE nbMjSingle[17],nbMjSeq[10],nbMjInterv[10],nbMjDouble[10];
		BYTE nbNumSingle,nbNumSeq,nbNumInterv,nbNumDouble;

		nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;

		findMjUnGrouped(nbTmpNum,nbTmpCode,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
						nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
		if(nbNumDouble==7 && ZHANGSHU==14)
		{
			ret = 1;
		}
		else 
		{
			ret = 0;
		}
	}

	return ret;
}

BYTE cmjplayer::findMjGroup(BYTE nbNum,BYTE * nbMj,BYTE *nbGNum,BYTE *nbGroupNum,BYTE *nbGroupColor,
							BYTE *nbGroupStat,BYTE * nbMjGroup)
{
	BYTE ret;
	BYTE nbTmpCode[3],nbTmp[3];

	ret = 0;
	if(nbNum == 2)
	{
		if(*nbMj == *(nbMj+1))
		{
			ret = 1;
			*nbGroupStat = JIANGPAI;*nbGroupNum = (*nbMj)%10;*nbGroupColor=(*nbMj)/10;
			*nbMjGroup = *nbMj;*(nbMjGroup+1) = *nbMj;
			(*nbGNum)++;
		}
		else ret = 0;
	}
	else if(nbNum == 3)
	{
		if(*nbMj == *(nbMj+1) && *nbMj == *(nbMj+2))
		{
			ret = 1;
			*nbGroupStat = KEZI;*nbGroupNum = (*nbMj)%10;*nbGroupColor=(*nbMj)/10;
			*nbMjGroup = *nbMj;*(nbMjGroup+1) = *nbMj;*(nbMjGroup+2) = *nbMj;
			(*nbGNum)++;
		}
		else if(*nbMj+1 == *(nbMj+1) && *nbMj+2 == *(nbMj+2) && (*nbMj)/10 <=2 )
		{
			ret = 1;
			*nbGroupStat = SHUNZI;*nbGroupColor = (*nbMj)/10;*nbGroupNum = (*nbMj)%10;
			*nbMjGroup = *nbMj;*(nbMjGroup+1) = *(nbMj+1);*(nbMjGroup+2) = *(nbMj+2);
			(*nbGNum)++;
		}
		else ret = 0;
	}
	else 
	{
		if(findPen(nbNum,nbMj,*nbMj,nbTmp) != INVALID)
		{
			nbTmpCode[0] = *(nbMj+nbTmp[0]);nbTmpCode[1] = *(nbMj+nbTmp[1]);nbTmpCode[2] =*(nbMj+nbTmp[2]);
			*(nbMj+nbTmp[0]) = INVALID;	*(nbMj+nbTmp[1]) = INVALID;	*(nbMj+nbTmp[2]) = INVALID;
			*nbGroupStat = KEZI;*nbGroupColor = (nbTmpCode[0])/10;*nbGroupNum = (nbTmpCode[0])%10;
			*nbMjGroup = nbTmpCode[0];*(nbMjGroup+1) = nbTmpCode[1];*(nbMjGroup+2) = nbTmpCode[2];
			(*nbGNum)++;
			SortMj(nbNum,nbMj);
			if(findMjGroup(nbNum-3,nbMj,nbGNum,nbGroupNum+1,nbGroupColor+1,nbGroupStat+1,nbMjGroup+3) != 1)
			{
				ret = 0;
				(*nbGNum)--;
			}
			else ret = 1;
			*(nbMj+nbNum-3) = nbTmpCode[0];*(nbMj+nbNum-3+1) = nbTmpCode[1];*(nbMj+nbNum-3+2) = nbTmpCode[2];
			SortMj(nbNum,nbMj);
		}
		if(findSeq(nbNum,nbMj,*nbMj,nbTmp) != INVALID && ret == 0)
		{
			nbTmpCode[0] = *(nbMj+nbTmp[0]);nbTmpCode[1] = *(nbMj+nbTmp[1]);nbTmpCode[2] =*(nbMj+nbTmp[2]);
			*(nbMj+nbTmp[0]) = INVALID;	*(nbMj+nbTmp[1]) = INVALID;	*(nbMj+nbTmp[2]) = INVALID;
			*nbGroupStat = SHUNZI;*nbGroupColor = (nbTmpCode[0])/10;*nbGroupNum = (nbTmpCode[0])%10;
			*nbMjGroup = nbTmpCode[0];*(nbMjGroup+1) = nbTmpCode[1];*(nbMjGroup+2) = nbTmpCode[2];
			(*nbGNum)++;
			SortMj(nbNum,nbMj);
			if(findMjGroup(nbNum-3,nbMj,nbGNum,nbGroupNum+1,nbGroupColor+1,nbGroupStat+1,nbMjGroup+3) != 1)
			{
				ret = 0;
				(*nbGNum)--;
			}
			else ret = 1;
			*(nbMj+nbNum-3) = nbTmpCode[0];*(nbMj+nbNum+1-3) = nbTmpCode[1];*(nbMj+nbNum+2-3) = nbTmpCode[2];
			SortMj(nbNum,nbMj);
		}
		if(ret == 0 && findjiang(nbNum,nbMj,*nbMj,nbTmp) != INVALID && nbNum%3 == 2)
		{
			nbTmpCode[0] = *(nbMj+nbTmp[0]);nbTmpCode[1] = *(nbMj+nbTmp[1]);
			*(nbMj+nbTmp[0]) = INVALID;	*(nbMj+nbTmp[1]) = INVALID;
			*nbGroupStat = JIANGPAI;*nbGroupColor= (nbTmpCode[0])/10;*nbGroupNum = (nbTmpCode[0])%10;
			*nbMjGroup = nbTmpCode[0];*(nbMjGroup+1) = nbTmpCode[1];
			(*nbGNum)++;
			SortMj(nbNum,nbMj);
			if(findMjGroup(nbNum-2,nbMj,nbGNum,nbGroupNum+1,nbGroupColor+1,nbGroupStat+1,nbMjGroup+3) != 1)
			{
				ret = 0;
				(*nbGNum)--;
			}
			else ret = 1;
			*(nbMj+nbNum-2) = nbTmpCode[0];*(nbMj+nbNum-2+1) = nbTmpCode[1];
			SortMj(nbNum,nbMj);
		}
	}
	return ret;
}

BYTE cmjplayer::findSeq(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp)
{
	BYTE ret;

	ret = 1;
	if(nbCode >= 31) ret = INVALID;
	*nbTmp = findMj(nbNum,nbMj,nbCode);
	*(nbTmp+1) = findMj(nbNum,nbMj,nbCode+1);
	*(nbTmp+2) = findMj(nbNum,nbMj,nbCode+2);
	if(*nbTmp == INVALID || *(nbTmp+1) == INVALID || *(nbTmp+2) == INVALID)
		ret = INVALID;
	return ret;
}

BYTE cmjplayer::findjiang(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp)
{
	BYTE ret;
	
	ret = 1;
	*nbTmp = findMj(nbNum,nbMj,nbCode);
	if(*nbTmp == INVALID)	ret = INVALID;
	else
	{
		*(nbMj+*nbTmp) = INVALID;
		*(nbTmp+1) = findMj(nbNum,nbMj,nbCode);
		if(*(nbTmp+1) == INVALID) ret = INVALID;
		*(nbMj+*nbTmp) = nbCode;
	}
	return ret;
}
BYTE cmjplayer::findPen(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp)
{
	BYTE ret;
	
	ret = 1;
	*nbTmp = findMj(nbNum,nbMj,nbCode);
	if(*nbTmp == INVALID)	ret = INVALID;
	else
	{
		*(nbMj+*nbTmp) = INVALID;
		*(nbTmp+1) = findMj(nbNum,nbMj,nbCode);
		if(*(nbTmp+1) == INVALID) ret = INVALID;
		else
		{
			*(nbMj+*(nbTmp+1)) = INVALID;
			*(nbTmp+2) = findMj(nbNum,nbMj,nbCode);
			if(*(nbTmp+2) == INVALID) ret = INVALID;
			*(nbMj+*(nbTmp+1)) = nbCode;
		}
		*(nbMj+*nbTmp) = nbCode;
	}
	return ret;
}

BYTE cmjplayer::findGang(BYTE nbNum,BYTE *  nbMj,BYTE nbCode,BYTE * nbTmp)
{
	BYTE ret;
	
	ret = 1;
	*nbTmp = findMj(nbNum,nbMj,nbCode);
	if(*nbTmp == INVALID)	ret = INVALID;
	else
	{
		*(nbMj+*nbTmp) = INVALID;
		*(nbTmp+1) = findMj(nbNum,nbMj,nbCode);
		if(*(nbTmp+1) == INVALID) ret = INVALID;
		else
		{
			*(nbMj+*(nbTmp+1)) = INVALID;
			*(nbTmp+2) = findMj(nbNum,nbMj,nbCode);
			if(*(nbTmp+2) == INVALID) ret = INVALID;
			else 
			{
				*(nbMj+*(nbTmp+2)) = INVALID;
				*(nbTmp+3) = findMj(nbNum,nbMj,nbCode);
				if(*(nbTmp+3) == INVALID) ret = INVALID;
				*(nbMj+*(nbTmp+2)) = nbCode;
			}
			*(nbMj+*(nbTmp+1)) = nbCode;
		}
		*(nbMj+*nbTmp) = nbCode;
	}
	return ret;
}

BYTE cmjplayer::adjustPenpai(BYTE nbLastNum,BYTE nbMjCode)
{
	int i;
	BYTE ret;
	BYTE nbTmpNumInHand,nbTmpMjInHand[17],nbCodeStat[6],nbTmp[3],nbTmpCode[3];
	BYTE nbTmpNum1,nbTmpNum2,nbretNum1,nbretNum2;
	BYTE nbMjSingle[17],nbMjSeq[10],nbMjInterv[10],nbMjDouble[10];
	BYTE nbNumSingle,nbNumSeq,nbNumInterv,nbNumDouble;
	

	ret = 0;
	if(nbPlayerNum != nbLastNum)
	{
		if(findjiang(nbNumInHand,nbMjInHand,nbMjCode,nbTmp) != INVALID)
		{
			if(nbPlayerNum == 0) ret = 1;
			else
			{
				for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];
				nbTmpNumInHand = nbNumInHand;
				nbretNum1 = findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
				nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
				findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
								nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
				nbretNum2 = nbNumDouble;
				for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];
				nbTmpNumInHand = nbNumInHand;
				nbTmpMjInHand[nbTmp[0]] = INVALID;nbTmpMjInHand[nbTmp[1]] = INVALID;
				SortMj(nbTmpNumInHand,nbTmpMjInHand);nbTmpNumInHand -= 2;
				nbTmpNum1 = findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
				nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
				findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
								nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
				nbTmpNum2 = nbNumDouble;
				if(nbTmpNum1+1 > nbretNum1)
				{
					if(nbTmpNum2 != 0) ret = 1;
				}
				if(ret == 1)
				{
					for(i=0;i<3;i++)	nbTmpCode[i] = nbMjCode;
					for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];
					findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
					modifyMjDefined(3,nbTmpCode,nbCodeStat);
				}
			}
		}
	}	
	return ret;
}

BYTE cmjplayer::adjustGangpai(BYTE nbLastNum,BYTE nbMjCode,BYTE & nbGangpaiNum,BYTE nbGangpaiCode[5],BYTE nbGangpaiStat[5])
{
	int i,j;
	BYTE ret;
	BYTE nbTmp[4],nbFlag;
	BYTE nbTmpNumInHand,nbTmpMjInHand[17],nbCodeStat[6];
	BYTE nbTmpNum1,nbTmpNum2,nbretNum1,nbretNum2;
	BYTE nbMjSingle[17],nbMjSeq[10],nbMjInterv[10],nbMjDouble[10];
	BYTE nbNumSingle,nbNumSeq,nbNumInterv,nbNumDouble;

	ret = 0;nbGangpaiNum = 0; nbFlag = 0;
	for(i=0;i<MAXGNUMINHAND;i++)	nbGangpaiCode[i] = INVALID;
	if(nbPlayerNum == nbLastNum)
	{
		for(i=0;i<nbNumInHand;i++)
		{
			if(findGang(nbNumInHand,nbMjInHand,nbMjInHand[i],nbTmp) != INVALID)
			{
				nbFlag = 1;
				for(j=0;j<nbGangpaiNum;j++)
				{
					if(nbGangpaiCode[j] == nbMjInHand[i]) nbFlag = 0;
				}
				if(nbFlag == 1) 
				{
					nbGangpaiCode[nbGangpaiNum] = nbMjInHand[i];nbGangpaiStat[nbGangpaiNum] = ANGANG;
					nbGangpaiNum ++;
				}
				ret = 1;
			}
		}
		for(i=0;i<nbNumDownSea;i++)
		{
			if(nbMjDownSea[i] == nbMjCode && nbMjDownSea[i+1] == nbMjCode && nbMjDownSea[i+2] == nbMjCode)
			{
				nbGangpaiCode[nbGangpaiNum] = nbMjCode;nbGangpaiStat[nbGangpaiNum] = MINGGANG;
				nbGangpaiNum ++;
				ret = 1;
			}
		}
	}
	else if(nbPlayerNum != nbLastNum)
	{
		if(findPen(nbNumInHand,nbMjInHand,nbMjCode,nbTmp) != INVALID)
		{
			nbGangpaiCode[nbGangpaiNum] = nbMjCode;nbGangpaiStat[nbGangpaiNum] = MINGGANG;
			nbGangpaiNum ++;
			ret = 1;
		}
	}
	if(ret == 1 && nbPlayerNum != 0)
	{
		ret = 0;
		for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];
		nbTmpNumInHand = nbNumInHand;
		nbretNum1 = findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
		nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
		findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
						nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
		nbretNum2 = nbNumDouble+nbNumInterv+nbNumSeq;
		for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];
		nbTmpNumInHand = nbNumInHand; j=0;
		for(i=0;i<nbTmpNumInHand;i++)
		{
			if(nbTmpMjInHand[i] == nbMjCode)	
			{
				nbTmpMjInHand[i] = INVALID;
				j++;
			}
		}
		SortMj(nbTmpNumInHand,nbTmpMjInHand);nbTmpNumInHand -= j;
		nbTmpNum1 = findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
		nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
		findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
						nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
		nbTmpNum2 = nbNumDouble+nbNumInterv+nbNumSeq;
		if(nbTmpNum1+1 >= nbretNum1)			ret = 1;
		else if(nbTmpNum2 >= nbretNum2 && nbTmpNum1+1 == nbretNum1)	ret = 1;
	}
	return ret;
}

BYTE cmjplayer::modifyMjDefined(BYTE nbTmpNumInHand,BYTE nbTmpMjInHand[17],BYTE nbCodeStat[6])
{
	int i,j,k,l;
	BYTE ret,nbTmp[3];
	BYTE nbGroupNum[6],nbGroupColor[6],nbGroupStat[6],nbTmpCode[17],nbGNum;
	
	ret = 0;
	for(i=0;i<MAXGNUMINHAND;i++)  
	{
		findMjGroup(3,&nbMjDefined[i*3],&nbGNum,&nbGroupNum[i],&nbGroupColor[i],&nbGroupStat[i],&nbTmpCode[i*3]);
	}
	findMjGroup(2,&nbMjDefined[MAXGNUMINHAND*3],&nbGNum,&nbGroupNum[MAXGNUMINHAND],&nbGroupColor[MAXGNUMINHAND],&nbGroupStat[MAXGNUMINHAND],&nbTmpCode[MAXGNUMINHAND*3]);
	for(i=0;i<nbTmpNumInHand;i++)
	{
		k = INVALID;
		if(findSeq(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i],nbTmp) != INVALID)
		{
			for(j=0;j<MAXGNUMINHAND;j++)
				if(nbCodeStat[j] == 2 && nbGroupStat[j] == SHUNZI && nbGroupColor[j] == nbTmpMjInHand[i]/10 
					&& nbGroupNum[j] <= nbTmpMjInHand[i]%10 && nbGroupNum[j]+2 >= nbTmpMjInHand[i]%10)
					k=j;
			if(k== INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[j] == 1 && nbGroupColor[j] == nbTmpMjInHand[i]/10 
						&& nbGroupNum[j]<= nbTmpMjInHand[i]%10 && nbGroupNum[j]+2 >= nbTmpMjInHand[i]%10)
						k=j;
			if(k==INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[i] == 0)	k = j;
			if(k== INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[i] == 1)	k = j;
			if(k== INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[i] == 2) k = j;
		}
		else if(findPen(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i],nbTmp) != INVALID)
		{
			if(k== INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[j] == 1 && nbGroupColor[j] == nbTmpMjInHand[i]/10 
						&& nbGroupNum[j]<= nbTmpMjInHand[i]%10 && nbGroupNum[j]+2 >= nbTmpMjInHand[i]%10)
						k=j;
			if(k==INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[i] == 0)	k = j;
			if(k== INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[i] == 1)	k = j;
			if(k== INVALID)
				for(j=0;j<MAXGNUMINHAND;j++)
					if(nbCodeStat[i] == 2) k = j;
		}
		if(k != INVALID)
		{
			for(l=0;l<3;l++)
			{
				nbMjDefined[k*3+l] = nbTmpMjInHand[nbTmp[l]];
				nbTmpMjInHand[nbTmp[l]] = INVALID;
				nbCodeStat[k] = 3;	
			}
			i = 0;
			SortMj(nbTmpNumInHand,nbTmpMjInHand);nbTmpNumInHand -= 3;ret += 3;
		}
	}
	if(findjiang(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[MAXGNUM]+nbGroupColor[MAXGNUM]*10,nbTmp) != INVALID)
	{
		nbCodeStat[MAXGNUMINHAND] = 3;
		nbTmpMjInHand[nbTmp[0]] = INVALID;nbTmpMjInHand[nbTmp[1]] = INVALID;
		SortMj(nbTmpNumInHand,nbTmpMjInHand);nbTmpNumInHand -= 2; ret += 2;
	}
	else
	{
		for(i=0;i<nbTmpNumInHand;i++)
		{
			if(findjiang(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i],nbTmp) != INVALID)
			{
				nbMjDefined[MAXGNUMINHAND*3] = nbTmpMjInHand[i];nbMjDefined[MAXGNUMINHAND*3+1]=nbTmpMjInHand[i];
				nbTmpMjInHand[nbTmp[0]] = INVALID;nbTmpMjInHand[nbTmp[1]] = INVALID;
				SortMj(nbTmpNumInHand,nbTmpMjInHand);	nbTmpNumInHand -= 2; ret += 2;
				break;
			}
		}
	}
	return ret;
}

BYTE cmjplayer::findMjGroupNum(BYTE& nbTmpNumInHand,BYTE nbTmpMjInHand[17],BYTE nbCodeStat[6])
{
	int i,j,k,l;
	bool haveJiang;
	BYTE ret,nbTmp[3];
	BYTE nbGroupNum[6],nbGroupColor[6],nbGroupStat[6],nbTmpCode[18],nbGNum;

	ret = 0;nbGNum = 0; haveJiang = false;
	for(i=0;i<MAXGNUMINHAND;i++)  
		findMjGroup(3,&nbMjDefined[i*3],&nbGNum,&nbGroupNum[i],&nbGroupColor[i],&nbGroupStat[i],&nbTmpCode[i*3]);
	findMjGroup(2,&nbMjDefined[MAXGNUMINHAND*3],&nbGNum,&nbGroupNum[MAXGNUMINHAND],&nbGroupColor[MAXGNUMINHAND],&nbGroupStat[MAXGNUMINHAND],&nbTmpCode[MAXGNUMINHAND*3]);
	
	for(i=0;i<MAXGNUM;i++)  	nbCodeStat[i] = 0;
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbGroupStat[i] == KEZI||nbGroupStat[i] == GANGZI)
		{
			if(findPen(nbNumDownSea,nbMjDownSea,nbGroupNum[i]+nbGroupColor[i]*10,nbTmp) != INVALID)
			{
				if(nbTmp[0] == nbTmp[1] -1 && nbTmp[1] == nbTmp[2] -1)		nbCodeStat[i] = 3;
			}
			else if(findMj(nbNumAnGang,nbMjAnGang,nbGroupNum[i]+nbGroupColor[i]*10) != INVALID)
				nbCodeStat[i] = 3;
			else if(findPen(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10,nbTmp) != INVALID)
			{
				nbCodeStat[i] = 3;
				for(j=0;j<3;j++)	nbTmpMjInHand[nbTmp[j]] = INVALID;
				SortMj(nbTmpNumInHand,nbTmpMjInHand);nbTmpNumInHand -= 3;
			}
		}
		else if(nbGroupStat[i] == SHUNZI)
		{
			if(findSeq(nbNumDownSea,nbMjDownSea,nbGroupNum[i]+nbGroupColor[i]*10,nbTmp) != INVALID)
			{
				if(nbTmp[0] == nbTmp[1]-1 && nbTmp[1] == nbTmp[2] -1)	nbCodeStat[i] = 3;
			}
			else if(findSeq(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10,nbTmp) != INVALID)
			{
				nbCodeStat[i] = 3;
				for(j=0;j<3;j++)	nbTmpMjInHand[nbTmp[j]] = INVALID;
				SortMj(nbTmpNumInHand,nbTmpMjInHand);nbTmpNumInHand -= 3;
			}
		}
		if(nbCodeStat[i] == 3) ret ++;
	}
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbCodeStat[i] == 0 && nbGroupStat[i] == SHUNZI)
		{
			j = findMj(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10);
			k = findMj(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10+1);
			l = findMj(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10+2);
			if(j != INVALID)	nbCodeStat[i] ++;
			if(k != INVALID)	nbCodeStat[i] ++;
			if(l != INVALID)	nbCodeStat[i] ++;
		}
		else if(nbCodeStat[i] == 0 && nbGroupStat[i] == KEZI)
		{
			if(findjiang(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10,nbTmp) != INVALID)
				nbCodeStat[i] = 2;
			else if(findMj(nbTmpNumInHand,nbTmpMjInHand,nbGroupNum[i]+nbGroupColor[i]*10) != INVALID)
				nbCodeStat[i] = 1;
		}
	}
	return ret;
}

BYTE cmjplayer::findMjUnGrouped(BYTE nbTmpNumInHand,BYTE nbTmpMjInHand[17],
								BYTE& nbNumSeq,BYTE nbMjSeq[10],BYTE& nbNumDouble,BYTE nbMjDouble[10],
								BYTE& nbNumInterv,BYTE nbMjInterv[10],BYTE& nbNumSingle,BYTE nbMjSingle[17])
{
	BYTE ret,nbTmp[3];
	int i,j;

	ret = 100;
	for(i=0;i<nbTmpNumInHand;i++)
	{
		j = findMj(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i]+1); 
		if(j != INVALID && nbTmpMjInHand[i]%10 != 1 && nbTmpMjInHand[i]%10 != 8 && nbTmpMjInHand[i] <= 29)
		{
			nbMjSeq[nbNumSeq] = nbTmpMjInHand[i];
			nbNumSeq ++;
			nbTmpMjInHand[i] = INVALID;nbTmpMjInHand[j] = INVALID;
			SortMj(nbTmpNumInHand,nbTmpMjInHand);
			nbTmpNumInHand -= 2;i=0;
		}
	}
	for(i=0;i<nbTmpNumInHand;i++)
	{
		if(findjiang(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i],nbTmp) != INVALID)
		{
			nbMjDouble[nbNumDouble] = nbTmpMjInHand[i];
			nbNumDouble++;
			for(j=0;j<2;j++)	nbTmpMjInHand[nbTmp[j]] = INVALID;
			SortMj(nbTmpNumInHand,nbTmpMjInHand);
			nbTmpNumInHand -= 2;i=0;
		}
	}
	for(i=0;i<nbTmpNumInHand;i++)
	{
		j = findMj(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i]+2); 
		if(j != INVALID && nbTmpMjInHand[i] <= 29 && nbTmpMjInHand[i]+2 <= 29 && nbTmpMjInHand[i]/10 == (nbTmpMjInHand[i]+2)/10)
		{
			nbMjInterv[nbNumInterv] = nbTmpMjInHand[i];
			nbNumInterv ++;
			nbTmpMjInHand[i] = INVALID;nbTmpMjInHand[j] = INVALID;
			SortMj(nbTmpNumInHand,nbTmpMjInHand);
			nbTmpNumInHand -= 2;i=0;
		}
	}
	for(i=0;i<nbTmpNumInHand;i++)
	{
		j = findMj(nbTmpNumInHand,nbTmpMjInHand,nbTmpMjInHand[i]+1); 
		if(j != INVALID && nbTmpMjInHand[i]+1 <= 29)
		{
			nbMjSeq[nbNumSeq] = nbTmpMjInHand[i];
			nbNumSeq ++;
			nbTmpMjInHand[i] = INVALID;nbTmpMjInHand[j] = INVALID;
			SortMj(nbTmpNumInHand,nbTmpMjInHand);
			nbTmpNumInHand -= 2;i=0;
		}
	}
	for(i=0;i<nbTmpNumInHand;i++)
	{
		nbMjSingle[nbNumSingle] = nbTmpMjInHand[i];
		nbNumSingle ++;
	}
	nbTmpNumInHand = 0;
	return ret;
}

BYTE cmjplayer::adjustChupaiNum(BYTE nbMjNum[70])
{
	int i,tmp,retStat;
	BYTE nbCodeStat[6],nbTmpMjInHand[17],nbTmpNumInHand,nbRetCode;
	BYTE nbMjSingle[17],nbMjSeq[10],nbMjInterv[10],nbMjDouble[10];
	BYTE nbNumSingle,nbNumSeq,nbNumInterv,nbNumDouble,ret;

	nbTmpNumInHand = nbNumInHand;
	for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];

	findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
	tmp = modifyMjDefined(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
	nbTmpNumInHand -= tmp;
	nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
	findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
					nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
	retStat = 65535;
	if(nbNumSingle == 0)
	{
		for(i=0;i<nbNumDouble;i++)
		{
			if(nbNumDouble == 1) tmp = 10;
			else 	tmp = nbMjNum[nbMjDouble[i]]+2;
			if(tmp<retStat) 
			{
				retStat = tmp;
				nbMjSingle[0] = nbMjSingle[1] = nbMjDouble[i];
			}
		}
		for(i=0;i<nbNumInterv;i++)
		{
			tmp = nbMjNum[nbMjInterv[i]+1];
			if(tmp<=retStat) 
			{
				retStat = tmp;
				nbMjSingle[0] = nbMjInterv[i];nbMjSingle[1] = nbMjInterv[i]+2;
			}
		}
		for(i=0;i<nbNumSeq;i++)
		{
			tmp = nbMjNum[nbMjSeq[i]-1]+nbMjNum[nbMjSeq[i]+2];
			if(tmp<=retStat)
			{
				retStat = tmp;
				nbMjSingle[0] = nbMjSeq[i];nbMjSingle[1] = nbMjSeq[i]+1;
			}
		}
		nbNumSingle += 2;
	}
	retStat = 65535;
	for(i=0;i<nbNumSingle;i++)
	{
		if(nbMjSingle[i] >=1 && nbMjSingle[i] <= 29) 
		{
			tmp = nbMjNum[nbMjSingle[i]+1]+nbMjNum[nbMjSingle[i]-1]+nbMjNum[nbMjSingle[i]];
			if(findMj(nbNumInHand,nbMjInHand,nbMjSingle[i]-1) != INVALID)	
				tmp += nbMjNum[nbMjSingle[i]+1]+nbMjNum[nbMjSingle[i]-2];
			else if(findMj(nbNumInHand,nbMjInHand,nbMjSingle[i]+1) != INVALID)
				tmp += nbMjNum[nbMjSingle[i]-1]+nbMjNum[nbMjSingle[i]+2];
			else if(findMj(nbNumInHand,nbMjInHand,nbMjSingle[i]-2) != INVALID)
				tmp += nbMjNum[nbMjSingle[i]-1];
			else if(findMj(nbNumInHand,nbMjInHand,nbMjSingle[i]+2) != INVALID)
				tmp += nbMjNum[nbMjSingle[i]+1];
		}
		else tmp = nbMjNum[nbMjSingle[i]];
		if(tmp < retStat)
		{
			retStat = tmp;nbRetCode = nbMjSingle[i];			
		}
	}
	for(i=0;i<nbNumInHand;i++)
	{
		if(nbMjInHand[i] == nbRetCode)	ret = i;
	}
	return ret;
}

BYTE cmjplayer::adjustCipai(BYTE nbLastNum,BYTE nbMjCode,BYTE & nbChipaiStat)
{
	int i,j,k;
	BYTE ret,nbStatus,nbTmpStatus;
	BYTE nbTmpNumInHand,nbTmpMjInHand[17],nbCodeStat[6],nbTmp[3],nbTmpCode[3];
	BYTE nbTmpNum1,nbTmpNum2,nbretNum1,nbretNum2;
	BYTE nbMjSingle[17],nbMjSeq[10],nbMjInterv[10],nbMjDouble[10];
	BYTE nbNumSingle,nbNumSeq,nbNumInterv,nbNumDouble;
	

	ret = 0;nbStatus = 0;
	for(i=0;i<nbNumInHand;i++)	nbTmpMjInHand[i] = nbMjInHand[i];
	nbTmpNumInHand = nbNumInHand;
	if(nbPlayerNum == (nbLastNum+1)%4 && nbMjCode < 30 && nbLastNum >= 0 && nbLastNum <= 3)
	{
		if(findMj(nbNumInHand,nbMjInHand,nbMjCode-2) != INVALID && findMj(nbNumInHand,nbMjInHand,nbMjCode-1) != INVALID)
				nbStatus = 1;
		if(findMj(nbNumInHand,nbMjInHand,nbMjCode+1) != INVALID && findMj(nbNumInHand,nbMjInHand,nbMjCode-1) != INVALID)
				nbStatus = nbStatus*10 + 2;
		if(findMj(nbNumInHand,nbMjInHand,nbMjCode+1) != INVALID && findMj(nbNumInHand,nbMjInHand,nbMjCode+2) != INVALID)
				nbStatus = nbStatus*10 +3;
	}
	if(nbStatus != 0)
	{
		if(nbPlayerNum != 0)
		{
			nbretNum1 = findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
			nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
			findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
									nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
			nbretNum2 = nbNumSingle;
			for(i=0;i<3;i++)
			{
				nbTmpStatus = (nbStatus>>(i*4))%10;	
				if(nbTmpStatus < 1 || nbTmpStatus > 3) continue;
				for(j=0;j<nbNumInHand;j++)  		nbTmpMjInHand[j] = nbMjInHand[j];
				nbTmpMjInHand[nbNumInHand] = nbMjCode;nbTmpNumInHand = nbNumInHand +1;
				if(findSeq(nbTmpNumInHand,nbTmpMjInHand,nbMjCode+nbStatus-3,nbTmp) != INVALID)
				{
					for(k=0;k<3;k++)	nbTmpMjInHand[nbTmp[k]] = INVALID;
				}
				SortMj(nbTmpNumInHand,nbTmpMjInHand);
				nbTmpNumInHand -= 3;
				nbTmpNum1 = findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
				nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;
				findMjUnGrouped(nbTmpNumInHand,nbTmpMjInHand,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
									nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
				nbTmpNum2 = nbNumSingle;
				if(nbTmpNum1+1 > nbretNum1)
				{
					ret = 1;	nbStatus = nbTmpStatus;
					nbretNum1 = nbTmpNum1;
				}
				else if(nbTmpNum1+1 == nbretNum1 &&  i!= 0 ) 
				{
					if(nbTmpNum2 <  nbretNum2)
					{
						ret = 1;nbStatus = nbTmpStatus;
							nbretNum2 = nbTmpNum2;
					}
				}
			}
			if(ret == 1)
			{
				for(j=0;j<nbNumInHand;j++)  		nbTmpMjInHand[j] = nbMjInHand[j];
				findMjGroupNum(nbTmpNumInHand,nbTmpMjInHand,nbCodeStat);
				for(k=0;k<3;k++)	nbTmpCode[k] = nbMjCode+nbStatus-3+k;
				modifyMjDefined(3,nbTmpCode,nbCodeStat);
			}
		}
		else ret = 1;
	}
	nbChipaiStat = nbStatus;
	return ret;
}

BYTE cmjplayer::findMj(BYTE nbNum,BYTE * nbMj,BYTE  nbMjCode)
{
	int i;
	BYTE ret = INVALID;
	for(i=0;i<nbNum;i++)
	{
		if(*(nbMj+i) == nbMjCode)
			ret = i;
	}
	return ret;
}

/*BYTE cmjplayer::GetPlayStat()
{
	return nbPlayStat;
}
*/
BYTE cmjplayer::GetPaiXin(BYTE * nbPai)
{
	int i;
	for(i=0;i<100;i++)
	{
		*(nbPai+i) = nbPaiXin[i];
	}
	return 100;
}

/*BYTE cmjplayer::SetPlayStat(BYTE nbStat)
{
	nbPlayStat = nbStat;
	return nbPlayStat;
}*/

BYTE cmjplayer::Chipai(BYTE nbCode,BYTE nbChipaiStat)
{
	int i;
	BYTE nbTmpCode[3],nbNum;
	nbTmpCode[1] = nbCode;
	if(nbChipaiStat == 1) 
	{
		nbTmpCode[0] = nbCode-2;nbTmpCode[2] = nbCode-1;
	}
	else if(nbChipaiStat == 2)
	{
		nbTmpCode[0] = nbCode-1;nbTmpCode[2] = nbCode+1;
	}
	else if(nbChipaiStat == 3)
	{
		nbTmpCode[0] = nbCode+1;nbTmpCode[2] = nbCode +2;
	}
	nbNum = findMj(nbNumInHand,nbMjInHand,nbTmpCode[0]);
	if (nbNum<nbNumInHand) nbMjInHand[nbNum] = INVALID;
	nbNum = findMj(nbNumInHand,nbMjInHand,nbTmpCode[2]);
	if (nbNum<nbNumInHand) nbMjInHand[nbNum] = INVALID;
	for(i=0;i<3;i++)		nbMjDownSea[nbNumDownSea +i] = nbTmpCode[i];
	SortMj(nbNumInHand,nbMjInHand);
	nbNumInHand -= 2;
	nbNumDownSea += 3;
	return 0;
}

BYTE cmjplayer::Penpai(BYTE nbCode)
{
	int i;
	BYTE nbNum;
	nbNum = findMj(nbNumInHand,nbMjInHand,nbCode);		nbMjInHand[nbNum] = INVALID;
	nbNum = findMj(nbNumInHand,nbMjInHand,nbCode);		nbMjInHand[nbNum] = INVALID;
	for(i=0;i<3;i++)	nbMjDownSea[nbNumDownSea+i] = nbCode;
	SortMj(nbNumInHand,nbMjInHand);
	nbNumInHand -= 2;
	nbNumDownSea += 3;
	return 0;
}

BYTE cmjplayer::Gangpai(BYTE nbLast,BYTE nbCode)
{
	int i;
	BYTE nbNum,nbTmp;
	BYTE nbTmpCode;
	BYTE  nbCodeDownSea;
	
	nbTmpCode = nbCode;
	nbCodeDownSea = INVALID;
	for(i=0;i<nbNumDownSea-2;i++)
	{
		if(nbMjDownSea[i] == nbTmpCode && nbMjDownSea[i+1] == nbTmpCode && nbMjDownSea[i+2] == nbTmpCode)
		{
			nbCodeDownSea = i;
		}
	}
	nbTmp = 0;
	if(nbCodeDownSea == INVALID)
	{
		nbNum = 0;
		while(nbNum != INVALID)
		{
			nbNum = findMj(nbNumInHand,nbMjInHand,nbTmpCode);
			nbMjInHand[nbNum] = INVALID;
			nbTmp++;
		}
		nbTmp --;
		if(nbLast == nbPlayerNum)
		{
			nbMjAnGang[nbNumAnGang] = nbTmpCode;
			nbNumAnGang ++;
		}
		else 
		{
			for(i=0;i<3;i++)	nbMjDownSea[nbNumDownSea+i] = nbTmpCode;
			nbGangDownSea[nbNumDownSea/3] = 1;
			nbNumDownSea += 3;
		}
	}
	else if(nbCodeDownSea >= 0 && nbCodeDownSea <= nbNumDownSea-2)
	{
		nbGangDownSea[nbCodeDownSea/3] = 1;
		nbNum = findMj(nbNumInHand,nbMjInHand,nbTmpCode);
		nbMjInHand[nbNum] = INVALID;
		nbTmp = 1;
	}
	SortMj(nbNumInHand,nbMjInHand);
	nbNumInHand -= nbTmp;
	nbNum = 0;
	return 0;
}

BYTE cmjplayer::Mopai(BYTE nbCode)
{
	BYTE ret;

	ret = nbCode;
	nbMjInHand[nbNumInHand] = nbCode;
	nbNumInHand ++;
//	SortMj();
	return ret;
}

BYTE cmjplayer::GetHuapai(BYTE nbNum)
{
	return nbHuapai[nbNum];
}

BYTE cmjplayer::SetHuapai(BYTE nbNum,BYTE nbValue)
{
	BYTE nbTmpNum;
	nbTmpNum = nbNum%10-1 + nbNum/60*4;
	nbHuapai[nbTmpNum] = nbValue;
	return nbHuapai[nbTmpNum];
}

BYTE cmjplayer::Bupai(BYTE nbCode)
{
	BYTE ret;

	ret = nbCode;
	if(nbMjInHand[nbNumInHand-1] >= 51) 	nbNumInHand --;
	nbMjInHand[nbNumInHand] = nbCode;
	nbNumInHand ++;
	return ret;
}

BYTE cmjplayer::HUPAI(BYTE nbStatus,BYTE nbLast,BYTE nbCode)
{
	return calcPaiXin(nbStatus,nbLast,nbCode);
}

BYTE cmjplayer::Chupai(BYTE m_ncSelectedNum)
{
	BYTE ret;

	ret = nbMjInHand[m_ncSelectedNum];
	nbMjInHand[m_ncSelectedNum] = INVALID;
	SortMj(nbNumInHand,nbMjInHand);
	nbNumInHand --;
	nbMjOutHand[nbNumOutHand] = ret;
	nbNumOutHand ++;
	return ret;
}

BYTE cmjplayer::Tingpai()
{
	if(nbTingPaiStat == 0) nbTingPaiStat = 1;
	else if(nbTingPaiStat ==1) nbTingPaiStat = 2;
	return nbTingPaiStat;
}

int	cmjplayer::calcPaiXin(BYTE nbStatus,BYTE nbLast,BYTE nbCode)
{
	int i;
	BYTE ret;
	BYTE nbGNum,nbTmpGroup[18],nbGroupStat[6],nbGroupColor[6],nbGroupNum[6];
	BYTE nbDownSea[6];
	BYTE nbTmpCode[17],nbTmpNum;

	nbGNum = 0;nbTmpNum = 0;ret=1;
	i=MAXSHU;
	for(i=0;i<ZHANGSHU;i++)	nbTmpCode[i] = 0;
	for(i=0;i<100;i++)	nbPaiXin[i] = 0;
	for(i=0;i<MAXGNUM;i++)	
	{
		nbGroupStat[i] = INVALID;nbGroupColor[i] = INVALID;
		nbGroupNum[i] = INVALID;nbDownSea[i] = INVALID;
	}
	for(i=0;i<nbNumInHand;i++)		nbTmpCode[i] = nbMjInHand[i];
	if(nbLast == nbPlayerNum)	nbTmpNum = nbNumInHand;
	else 
	{
		nbTmpCode[nbNumInHand] = nbCode;
		nbTmpNum = nbNumInHand+1;
	}
	SortMj(nbTmpNum,nbTmpCode);
	if(findMjGroup(nbTmpNum,nbTmpCode,&nbGNum,nbGroupNum,nbGroupColor,nbGroupStat,nbTmpGroup) != 1)
	{
		ret = 0;

		BYTE nbMjSingle[17],nbMjSeq[10],nbMjInterv[10],nbMjDouble[10];
		BYTE nbNumSingle,nbNumSeq,nbNumInterv,nbNumDouble;
		nbNumSeq = 0;nbNumDouble = 0;nbNumInterv = 0;nbNumSingle = 0;

		findMjUnGrouped(nbTmpNum,nbTmpCode,nbNumSeq,nbMjSeq,nbNumDouble,nbMjDouble,
						nbNumInterv,nbMjInterv,nbNumSingle,nbMjSingle);
		if(nbNumDouble==7)
		{
			nbPaiXin[QIDUI]=1;
			if(nbLast == nbPlayerNum) nbPaiXin[ZIMO] = 1;
			return 1;
		}

	}
	if(ret != 0)
	{
		for(i=0;i<nbNumAnGang;i++)
		{
			nbGroupStat[nbGNum+i] = GANGZI;nbGroupColor[nbGNum+i] = nbMjAnGang[i]/10;nbGroupNum[nbGNum+i] = nbMjAnGang[i]%10;
			for(int j=0;j<3;j++)   nbTmpGroup[nbGNum*3+j] = nbMjAnGang[i];
		}
		nbGNum += nbNumAnGang;
	}
	for(i=0;i<nbGNum;i++)	nbDownSea[i] = 0;
	for(i=nbGNum;i<MAXGNUM;i++) nbDownSea[i] = 1;
	if(ret != 0)
	{
		for(i=0;i<nbNumDownSea/3;i++)
		{
			nbTmpCode[0] = nbMjDownSea[i*3];nbTmpCode[1] = nbMjDownSea[i*3+1];nbTmpCode[2] = nbMjDownSea[i*3+2]; 
			nbTmpNum = 3;
			SortMj(nbTmpNum,nbTmpCode);
			ret = findMjGroup(nbTmpNum,nbTmpCode,&nbGNum,&nbGroupNum[nbGNum],&nbGroupColor[nbGNum],
						   &nbGroupStat[nbGNum],&nbTmpGroup[nbGNum*3]);
			if(nbGroupStat[nbGNum] == KEZI && nbGangDownSea[i] == 1)
				nbGroupStat[nbGNum] = GANGZI;
		}
	}
	if(ret != 0) 
	{
		nbPaiXin[PIHU] = 1;
		if(nbTingPaiStat == 2) nbPaiXin[LIZHI] = 1;
	}

		
	ret = adjustMenQing(nbDownSea);
	if(ret != INVALID)
	{
		if(ret == MENQING && nbLast == nbPlayerNum)		nbPaiXin[MENQINGZIMO] = 1;
		else if(ret == MENQING)			nbPaiXin[MENQING] = 1;
		else if(ret == QUANQIUREN && nbLast != nbPlayerNum)	nbPaiXin[QUANQIUREN] = 1;
	}
	else if(nbLast == nbPlayerNum) nbPaiXin[ZIMO] = 1;
	if(nbStatus == BUPAI)	nbPaiXin[GANGSHANGKAIHUA] = 1;
	ret = adjustQingyiSe(nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	ret = adjustPenpenHu(nbDownSea,nbLast,nbCode,nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	ret = adjustSanSe(nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	ret = adjustYitiaoLong(nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbGroupStat[i] == SHUNZI && nbGroupNum[i] == 7)
			nbGroupNum[i] = 9;
	}
	ret = adjustDuanyaoJiu(nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	ret = adjustEbeiKou(nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	ret = adjustFengPai(nbGroupNum,nbGroupColor,nbGroupStat);
	if(ret != INVALID)  nbPaiXin[ret] = 1;
	else 
	{
		if(adjustSanyuanPai(HONGZHONG,nbGroupNum,nbGroupColor,nbGroupStat) != INVALID)
			nbPaiXin[HONGZHONGPAI] = 1;
		if(adjustSanyuanPai(BAIBAN,nbGroupNum,nbGroupColor,nbGroupStat) != INVALID)
			nbPaiXin[BAIBANPAI] = 1;
		if(adjustSanyuanPai(FACAI,nbGroupNum,nbGroupColor,nbGroupStat) != INVALID)
			nbPaiXin[FACAIPAI] = 1;
	}
	return 1;
}

BYTE cmjplayer::adjustQingyiSe(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i;
	BYTE ret,Color;

	Color = nbGroupColor[0];
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbGroupColor[i] >=0 && nbGroupColor[i] <=2)
		{
			Color = nbGroupColor[i];
			break;
		}
	}
	if(Color > 2)	ret = ZIYISE;
	else
	{
		ret = QINGYISE;
		for(i=0;i<MAXGNUM;i++)
		{
			if(nbGroupColor[i] != Color && nbGroupColor[i] <=2)
			{
				ret = INVALID;
				break;
			}
			else if(nbGroupColor[i] != Color)
					ret = HUNYISE;
		}
	}
	return ret;
}

BYTE cmjplayer::adjustPenpenHu(BYTE nbGroupDownSea[6],BYTE nbLast,BYTE nbCode,BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i;
	BYTE ret;
	BYTE nbNumOfKe,nbNumOfShun,nbNumOfGang;
	bool isAnke;

	ret = INVALID;isAnke = false;
	nbNumOfKe = 0;nbNumOfShun=0;nbNumOfGang=0;
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbGroupStat[i] == SHUNZI)	nbNumOfShun++;
		if((nbGroupStat[i] == KEZI||nbGroupStat[i] == GANGZI)
			&& nbGroupDownSea[i] == 0)
			nbNumOfKe++;
		if(nbGroupStat[i] == GANGZI)	nbNumOfGang++;
		if(nbLast != nbPlayerNum && nbGroupStat[i] == SHUNZI && nbGroupColor[i] == nbCode/10
			&& nbGroupDownSea[i] == 0 && nbGroupNum[i] <= nbCode%10 && nbGroupNum[i]+3 > nbCode%10)
			isAnke = true;
	}
	if(isAnke == false)
	{
		for(i=0;i<MAXGNUM;i++)
		{
			if(nbGroupNum[i] == nbCode%10 && nbGroupStat[i] == KEZI && nbGroupDownSea[i] == 0
				&& nbGroupColor[i] == nbCode/10)
				nbNumOfKe--;
		}
	}
	if(ret == INVALID && nbNumOfKe == 5)  ret = WUANKE;
	else if(ret == INVALID && nbNumOfGang == 4)  ret = SIGANGZI;
	else if(ret == INVALID && nbNumOfKe == 4)  ret = SIANKE;
	else if(ret == INVALID && nbNumOfShun == 0)  ret = PENPENHU;
	else if(ret == INVALID && nbNumOfGang == 3)  ret = SANGANGZI;
	else if(ret == INVALID && nbNumOfKe == 3)  ret = SANANKE;
	else if(nbNumOfShun == MAXGNUMINHAND) ret = PINGHU;
	return ret;
}

BYTE cmjplayer::adjustSanSe(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i,j,k;
	BYTE ret;

	ret = INVALID;
	for(i=0;i<MAXGNUM;i++)
	{
		for(j=0;j<MAXGNUM;j++)
		{
			for(k=0;k<MAXGNUM;k++)
			{
				if(nbGroupColor[i] <=2 && nbGroupColor[j] <=2 && nbGroupColor[k] <= 2 &&
					nbGroupNum[i] == nbGroupNum[k] && nbGroupNum[k] == nbGroupNum[j] &&
					nbGroupColor[i] != nbGroupColor[j] && nbGroupColor[i] != nbGroupColor[k] && nbGroupColor[j] != nbGroupColor[k] &&
					nbGroupStat[i] == nbGroupStat[j] && nbGroupStat[k] == nbGroupStat[j])
				{
					if(nbGroupStat[i] == KEZI) ret = SANSETONGKE;
					else if(nbGroupStat[i] == SHUNZI) ret = SANSETONGSHUN;
				}
			}
		}
	}
	return ret;
}

BYTE cmjplayer::adjustFengPai(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i,j,k,l;
	BYTE ret;
	ret = INVALID;

	i = adjustSanyuanPai(HONGZHONG,nbGroupNum,nbGroupColor,nbGroupStat);
	j = adjustSanyuanPai(BAIBAN,nbGroupNum,nbGroupColor,nbGroupStat);
	k = adjustSanyuanPai(FACAI,nbGroupNum,nbGroupColor,nbGroupStat);
	if(i!= INVALID && j != INVALID && k!= INVALID)
	{
		if(nbGroupStat[i] == JIANGPAI || nbGroupStat[j] == JIANGPAI || nbGroupStat[k] == JIANGPAI)
			ret = XIAOSANYUAN;
		else ret = DASANYUAN;
	}
	i = adjustSanyuanPai(DONGFENG,nbGroupNum,nbGroupColor,nbGroupStat);
	j = adjustSanyuanPai(NANFENG,nbGroupNum,nbGroupColor,nbGroupStat);
	k = adjustSanyuanPai(XIFENG,nbGroupNum,nbGroupColor,nbGroupStat);
	l = adjustSanyuanPai(BEIFENG,nbGroupNum,nbGroupColor,nbGroupStat);
	if(i!= INVALID && j != INVALID && k!= INVALID && l != INVALID)
	{
		if(nbGroupStat[i] == JIANGPAI || nbGroupStat[j] == JIANGPAI || nbGroupStat[k] == JIANGPAI
			|| nbGroupStat[l] == JIANGPAI)
			ret = XIAOSIXI;
		else ret = DASIXI;
	}
	return ret;
}

BYTE cmjplayer::adjustSanyuanPai(BYTE nbMjCode,BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i;
	BYTE ret ;
	ret = INVALID;
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbGroupNum[i] == nbMjCode%10 && nbGroupColor[i] == nbMjCode/10 && nbGroupStat[i] != SHUNZI)
			ret = i;
	}
	return ret;
}

BYTE cmjplayer::adjustDuanyaoJiu(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i;
	BYTE ret,nbNumOfKe,nbNumOfZi,nbNumOfYao;
	ret = INVALID;
	nbNumOfKe = 0;nbNumOfZi = 0;nbNumOfYao = 0;
	for(i=0;i<MAXGNUM;i++)
	{
		if((nbGroupNum[i] == 1 || nbGroupNum[i] == 9) && nbGroupColor[i] <=2)
			nbNumOfYao++;
		else if(nbGroupColor[i]>2)		nbNumOfZi++;
		if(nbGroupStat[i] == KEZI)         nbNumOfKe++;
	}
	if(nbNumOfYao == MAXGNUM)		ret = CUNQUANDAIYAO;
	else if(nbNumOfYao + nbNumOfZi == MAXGNUM && nbNumOfKe == MAXGNUM && nbNumOfYao != 0) ret = HUNLAOTOU;
	else if(nbNumOfYao + nbNumOfZi == MAXGNUM && nbNumOfYao != 0) ret = HUNQUANDAIYAO;
	else if(nbNumOfYao == 0 && nbNumOfZi != MAXGNUM) ret = DUANYAOJIU;
	return ret;
}

BYTE cmjplayer::adjustYitiaoLong(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i,j,k;
	BYTE ret;

	ret = INVALID;
	for(i=0;i<MAXGNUM;i++)
	{
		for(j=0;j<MAXGNUM;j++)
		{
			for(k=0;k<MAXGNUM;k++)
			{
				if(nbGroupNum[i] == 1 && nbGroupNum[j] == 4 && nbGroupNum[k] == 9 &&
					nbGroupColor[i] == nbGroupColor[j] && nbGroupColor[j] == nbGroupColor[k] &&
					nbGroupStat[i] == SHUNZI && nbGroupStat[j] == SHUNZI && nbGroupStat[k] == SHUNZI)
					ret = YITIAOLONG;
			}
		}
	}
	return ret;
}

BYTE cmjplayer::adjustEbeiKou(BYTE nbGroupNum[6],BYTE nbGroupColor[6],BYTE nbGroupStat[6])
{
	int i,j;
	BYTE ret,nbTmpNum;

	ret = INVALID;nbTmpNum = 0;
	for(i=0;i<MAXGNUM;i++)
	{
		for(j=0;j<MAXGNUM;j++)
		{
			if(j != i && nbGroupNum[j] == nbGroupNum[i] && nbGroupColor[j] == nbGroupColor[i] && 
				nbGroupStat[j] == SHUNZI && nbGroupStat[i] == SHUNZI)
				nbTmpNum ++;
		}
	}
	if(nbTmpNum == 4) ret = EBEIKOU;
	else if(nbTmpNum == 2) ret = YIBEIKOU;
	return ret;
}

BYTE cmjplayer::adjustMenQing(BYTE nbGroupDownSea[6])
{
	int i;
	BYTE nbNum,ret;

	nbNum = 0;ret = INVALID;
	for(i=0;i<MAXGNUM;i++)
	{
		if(nbGroupDownSea[i] == 1)  nbNum ++;
	}
	if(nbNum == MAXGNUMINHAND)	ret = QUANQIUREN;
	else if(nbNum == 0) ret = MENQING;
	return ret;
}
