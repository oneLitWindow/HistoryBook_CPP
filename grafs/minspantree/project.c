
//minimum spanning tree
//copyrights: www.syncedit.com

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define INFINITY	0xFFFFFFF
#define MAXLINES	2000
typedef int boolean;

struct DataLine
{
	char chBegin,chEnd;
	int iWeight;
};

struct Path
{
	char chNode,chNodeNeighbor;	//the node and its neighbor node
	int iExist;					//1==the node exists, 0==not (i.e. node Z may not exist in data file)
};

//check if the node is in data file, return 1/0 for yes/no
boolean HasTheNode(struct DataLine*pl,int iNumLine,char chNode);

//open and read data file
//return: 0==error, or number of valid lines (not number of lines in file)
int OpenAndReadDataFile(char*pszFile,struct DataLine*pFl,int iNumLine);

//check current line read,
//return: -1==error, 1==OK, 
//0==repeated (skip the line, i.e. A->B and B->A with same weight)
int CheckCurrentLine(struct DataLine*pFl,int iNumLine);

//initialize data and start search
boolean StartSearch(struct DataLine*pl,int iNumLine,struct Path*pp);

//most important function
//this is loop function for finding next fixed node
//return 1==OK, 0==error, see function body for details
boolean SearchForNextFixedNode(struct DataLine*pl,int iNumLine,struct Path*pp);

//get weight between 2 nodes, return INFINITY if no such route
int GetWeightBetweenTwoNodes(struct DataLine*pl,int iNumLine,char chNode0,char chNode1);

//get minimum weight from the tentative node to fixed set, return INFINITY if no such route
//pchNodeNeighbor is for its neighbor node
int GetMinimumWeightToFixedSet(struct DataLine*pl,int iNumLine,struct Path*pp,char chNode,char*pchNodeNeighbor);

//print the file line if error to show why 
void PrintTheLine(struct DataLine fl);

int main(int argc, char*argv[])
{
	//to store info of data file, maximum lines are MAXLINES
	struct DataLine filelines[MAXLINES];
	//node set
	struct Path path[26];

	//variables
	int i,iNumLines,iWeight,iWeightTree;

	printf("\n\n");

	//check if argc is 2
	if(argc!=2)
	{
		printf("error: argc is not 2, it is %d\n",argc);
		printf("command must be in format of: filename start destination\n");
		return 1;
	}

	//print argv
	printf("%s %s\n",argv[0],argv[1]);

	//open and read data file, MAXLINES is maximum lines 
	iNumLines=OpenAndReadDataFile(argv[1],filelines,MAXLINES);
	//if error, stop here
	if((iNumLines==0)||(iNumLines>MAXLINES))	return 1;

	//display successful reading info and number of valid lines
	printf("successfully read the file, number of valid lines is %d\n",iNumLines);

	StartSearch(filelines,iNumLines,path);

	printf("\n");

	//check if minimum spanning tree exists
	for(i=0;i<26;i++)
	{
		if(path[i].iExist&&(path[i].chNodeNeighbor==0))
		{
			printf("error: the tree can not be generated because of node %c\n",path[i].chNode);
			return 1;
		}
	}

	printf("\n");

	printf("node -- node , weight:\n");
	//print from start node to destination
	iWeightTree=0;
	for(i=0;i<26;i++)
	{
		if(path[i].iExist&&(path[i].chNode!=path[i].chNodeNeighbor))
		{
			iWeight=GetWeightBetweenTwoNodes(filelines,iNumLines,path[i].chNode,path[i].chNodeNeighbor);
			printf("%c -- %c , %d\n",path[i].chNode,path[i].chNodeNeighbor,iWeight);

			iWeightTree+=iWeight;
		}
	}

	//print destination node, total weight is in "start node" because seaching is backward
	printf("total weight of the minimum spanning tree is %d \n\n",iWeightTree);

	return 0;
}

int OpenAndReadDataFile(char*pszFile,struct DataLine*pFl,int iMaxLines)
{
	FILE*file;
	char sz[256],*p;
	int iLineCur=0,iLineFile=0,iCheck;

	//print error for file name if any
	if((pszFile==0)||strlen(pszFile)==0)
	{
		printf("error: in format of filename\n");
		return 0;
	}

	//open the file
	//print error if any
	file=fopen(pszFile,"r");
	if(file==0)
	{
		printf("error: can not open %s",pszFile);
		return 0;
	}

	//read data, maxmum valid lines are MAXLINES
	while(iLineCur<iMaxLines)
	{
		//read the line, break at end or failed
		if(!fgets(sz,256,file))	break;
		if(strlen(sz)==0)	continue;

		p=sz;
		pFl[iLineCur].chBegin=*p;
		p+=2;
		pFl[iLineCur].chEnd=*p;
		p+=2;

		pFl[iLineCur].iWeight=atoi(p);

		iCheck=CheckCurrentLine(pFl,iLineCur);

		if(iCheck<0)	return 0;

		if(iCheck>0)	iLineCur++;
		iLineFile++;
	}

	if(iLineCur==0)
	{
		printf("error: there is no data in %s\n",pszFile);
		return 0;
	}

	//error if lines in data file are over MAXLINES
	if(iLineFile>=iMaxLines)
	{
		printf("error: number of lines in %s is over %d\n",pszFile,iLineFile);
		return iLineFile;
	}

	//return number of valid lines
	return iLineCur;
}

//check for current data line
int CheckCurrentLine(struct DataLine*pFl,int iLineCur)
{
	int i;

	if(pFl[iLineCur].chBegin==pFl[iLineCur].chEnd)
	{
		printf(	"error: begine is the same as end in line %d (%s)\n",iLineCur);
		PrintTheLine(pFl[iLineCur]);
		return -1;
	}
	if(pFl[iLineCur].iWeight<0)
	{
		printf("error: weight in line %d is < 0\n",iLineCur);
		PrintTheLine(pFl[iLineCur]);
		return -1;
	}

	//if the line is first one, OK
	if(iLineCur==0)	return 1;

	//check for contradictions with previous lines
	for(i=0;i<iLineCur;i++)
	{
		if(	((pFl[i].chBegin==pFl[iLineCur].chBegin)&&(pFl[i].chEnd==pFl[iLineCur].chEnd))||
			((pFl[i].chBegin==pFl[iLineCur].chEnd)&&(pFl[i].chEnd==pFl[iLineCur].chBegin)))
		{
			if(pFl[i].iWeight!=pFl[iLineCur].iWeight)
			{
				printf(	"error: contradictions of weight in lines %d and %d\n",i,iLineCur);
				PrintTheLine(pFl[i]);
				PrintTheLine(pFl[iLineCur]);

				//error
				return -1;
			}
			//repeat line, i.e. A->B and B->A with same weight
			return 0;
		}
	}
	return 1;	//OK
}

void PrintTheLine(struct DataLine fl)
{
	printf("\t%2c,%2c,%15d\n",fl.chBegin,fl.chEnd,fl.iWeight);
}

boolean HasTheNode(struct DataLine*pl,int iNumLine,char chNode)
{
	int i;
	for(i=0;i<iNumLine;i++)
	{
		if(pl[i].chBegin==chNode)	return 1;
		if(pl[i].chEnd==chNode)		return 1;
	}
	return 0;
}

boolean StartSearch(struct DataLine*pl,int iNumLine,struct Path*pp)
{
	int i,iFirst=-1;

	//initialize data
	for(i=0;i<26;i++)
	{
		pp[i].chNode='A'+i;
		if(HasTheNode(pl,iNumLine,pp[i].chNode))
		{
			pp[i].iExist=1;
			if(iFirst==-1)	iFirst=i;
		}
		pp[i].chNodeNeighbor=0; 
	}

	if(iFirst==-1)	return 0;

	//initialize first node
	pp[iFirst].chNodeNeighbor=pp[iFirst].chNode;	//to itself

	//go to loop function
	return SearchForNextFixedNode(pl,iNumLine,pp);
}

int GetMinimumWeightToFixedSet(struct DataLine*pl,int iNumLine,struct Path*pp,char chNode,char*pchNodeNeighbor)
{
	int iWeight,iWeightMin=INFINITY;
	int i;
	//index of the node
	int iNow=chNode-'A';
	for(i=0;i<26;i++)
	{
		//not for the node itself
		if(i==iNow)			continue;
		//continue if the node is not in fixed set 
		if(pp[i].chNodeNeighbor==0)	continue;

		//get weight from the node to pp[i].chNode
		iWeight=GetWeightBetweenTwoNodes(pl,iNumLine,chNode,pp[i].chNode);
		//continue if no such route
		if(iWeight==INFINITY)	continue;
		
		//set minimum one
		if(iWeight<iWeightMin)
		{
			iWeightMin=iWeight;
			*pchNodeNeighbor=pp[i].chNode;
		}
	}
	return iWeightMin;
}

boolean SearchForNextFixedNode(struct DataLine*pl,int iNumLine,struct Path*pp)
{
	int i,iFixed;

	int iWeightMin,iWeightFixed=INFINITY;
	char chNodeNeighbor,chNodeFiixed=0;

	for(i=0;i<26;i++)
	{
		//continue if the node doesn't exist in data file
		if(pp[i].iExist==0)			continue;
		//continue if the node is in fixed set
		if(pp[i].chNodeNeighbor)	continue;

		//find minimum weight to fixed set (total weight to target)
		iWeightMin=GetMinimumWeightToFixedSet(pl,iNumLine,pp,pp[i].chNode,&chNodeNeighbor);
		//continue if no such route
		if(iWeightMin==INFINITY)	continue;

		//set the node by minimum weight 
		if(iWeightMin<iWeightFixed)
		{
			chNodeFiixed=chNodeNeighbor;
			iWeightFixed	=iWeightMin;
			iFixed=i;
		}
	}

	//error if no such route 
	if(iWeightFixed==INFINITY)	return 0;

	//set the node to fixed set
	pp[iFixed].chNodeNeighbor	=chNodeFiixed;

	//do next loop
	return SearchForNextFixedNode(pl,iNumLine,pp);
}

int GetWeightBetweenTwoNodes(struct DataLine*pl,int iNumLine,char chNode0,char chNode1)
{
	int i;
	for(i=0;i<iNumLine;i++)
	{
		if((pl[i].chBegin==chNode0)&&(pl[i].chEnd==chNode1))	return pl[i].iWeight;
		if((pl[i].chBegin==chNode1)&&(pl[i].chEnd==chNode0))	return pl[i].iWeight;
	}
	return INFINITY;
}
