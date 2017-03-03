/* assignment2.c
Created on: 24 Feb 2017
Author: Anna Davison
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct list
{
	int pType;
	char player[10];
	int lp;
	int smartness;
	int strength;
	int magicskills;
	int luck;
	int dexterity;
	int slots;
	int slotsT[10];
};

void attack(struct list record[i]);

int main(void)
{
		setbuf(stdout,NULL);
		srand(time(NULL));
		int set,slotnum;
		
		printf("\nInput the number of players to be inputed(max six): ");
		scanf("%d",&set);
		
		while(set<2||set>6)
		{
			
			printf("\nIncorrect number of players.\n\nInput the number of players to be inputed(max six): ");
			scanf("%d",&set);
		}
		
		printf("\nInput the number of slots on the board(max 20): ");
		scanf("%d",&slotnum);
		
		while(slotnum<set||slotnum>20)
		{
			
			printf("\nIncorrect number of slots.\n\nInput the number of slots on the board(max 20): ");
			scanf("%d",&slotnum);
		}
		
		struct list record[set];
		int i;

		//set players and type numbers
		for(i=0;i<set;i++)
		{
			printf("\nInput player %d:\n",i+1);
			printf("Select player type(1=Elf, 2=Human, 3=Ogre, 4=Wizard): ");
			scanf("%d",&record[i].pType);//input integer representing type then assigning that value to struc
			printf("\nInput player name: ");
			scanf("%s",&record[i].player);//same method as integer
		}
		
		for(i=0;i<set;i++)
		{
			if(record[i].pType==1)
			{
				//elf characteristics
				record[i].lp=100;
				record[i].smartness=70+rand()%30;
				record[i].strength=1+rand()%49;
				record[i].magicskills=50+rand()%29;
				record[i].luck=60+rand()%40;
				record[i].dexterity=1+rand()%99;
			}
			else if(record[i].pType==2)
			{
				//human characteristics
				int hsum=300;
				record[i].lp=100;
				record[i].smartness=1+rand()%99;
				record[i].strength=1+rand()%99;
				record[i].magicskills=1+rand()%99;
				record[i].luck=1+rand()%99;
				record[i].dexterity=1+rand()%99;
				while(record[i].smartness+record[i].strength+record[i].magicskills+record[i].luck+record[i].dexterity>=300)
				{
					record[i].smartness=1+rand()%99;
					record[i].strength=1+rand()%99;
					record[i].magicskills=1+rand()%99;
					record[i].luck=1+rand()%99;
					record[i].dexterity=1+rand()%99;
				}
			}
			else if(record[i].pType==3)
			{
				int sum=50;
				//ogre characteristics
				record[i].lp=100;
				record[i].smartness=rand()%20;
				sum=sum-record[i].smartness;
				record[i].strength=80+rand()%20;
				record[i].magicskills=0;
				record[i].luck=rand()%sum;
				record[i].dexterity=80+rand()%20;
			}
			else if(record[i].pType==4)
			{
				//wizard characteristics
				record[i].lp=100;
				record[i].smartness=90+rand()%10;
				record[i].strength=1+rand()%19;
				record[i].magicskills=80+rand()%20;
				record[i].luck=50+rand()%50;
				record[i].dexterity=1+rand()%99;
			}
		}
		
		for(i=0;i<set;i++)
		{
			printf("\nPlayer %d lp: %d\n",i+1,record[i].lp);
			printf("\nPlayer %d smartness: %d\n",i+1,record[i].smartness);
			printf("\nPlayer %d strength: %d\n",i+1,record[i].strength);
			printf("\nPlayer %d magicskills: %d\n",i+1,record[i].magicskills);
			printf("\nPlayer %d luck: %d\n",i+1,record[i].luck);
			printf("\nPlayer %d dexterity: %d\n",i+1,record[i].dexterity);
		}
		
		/*for(i=0;i<set;i++)
		{
			//if slot on one or both sides are empty
			//offer move as an option as well as attack nearest player as an option
			
			//else if slot on both sides is full
			//attack nearest player
			//attack(record[i])
		}*/

		return 0;
}
void attack(struct list record[i])
{
	
}