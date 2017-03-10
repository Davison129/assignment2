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
	//int slottype;
	//int slotposition;
	int slots;
	int slotT;
};

//void makeslots(struct list array[], int slotnum);
void attack(struct list record[],int set,int slotnum,int o);

int main(void)
{
		setbuf(stdout,NULL);
		srand(time(NULL));
		int set,slotnum,p;
		
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
		
		struct list record[slotnum];
		int i;

		//set players and type numbers
		for(i=0;i<set;i++)
		{
			printf("\nInput player %d:\n",i);
			printf("Select player type(1=Elf, 2=Human, 3=Ogre, 4=Wizard): ");
			scanf("%d",&record[i].pType);//input integer representing type then assigning that value to struc
			while(record[i].pType<1||record[i].pType>4)
			{
				printf("\nError. Re-enter player type.\n");
				printf("Select player type(1=Elf, 2=Human, 3=Ogre, 4=Wizard): ");
				scanf("%d",&record[i].pType);//input integer representing type then assigning that value to struc
			}
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
		
		for(i=0;i<slotnum;i++)
		{
			record[i].slotT=rand()%3;//0=Level Ground, 1=Hill, 2=City
			printf("\nSlotT %d: %d\n",i,record[i].slotT);
		}
		
		record[0].slots=0;
		record[1].slots=8;
		record[2].slots=10;
		record[3].slots=15;
		
		for(i=0;i<set;i++)
		{
			printf("\nPlayer %d lp: %d\n",i,record[i].lp);
			printf("\nPlayer %d smartness: %d\n",i,record[i].smartness);
			printf("\nPlayer %d strength: %d\n",i,record[i].strength);
			printf("\nPlayer %d magicskills: %d\n",i,record[i].magicskills);
			printf("\nPlayer %d luck: %d\n",i,record[i].luck);
			printf("\nPlayer %d dexterity: %d\n",i,record[i].dexterity);
			printf("\nPlayer %d slots: %d\n",i,record[i].slots);
		}
		
		//makeslots(record, slotnum);
		
		/*for(i=0;i<set;i++)
		{
			printf("%d\n", record[i]);
			int playerz = record[i];
			//attack(,set,slotnum);
		}*/
		
		for(i=0;i<set;i++)
		{
			attack(record,set,slotnum,i);
			
			
			for(p=0;i<set;i++)
			{
				printf("\n%s ",i,record[p].player);
				if(record[p].pType==1)
				{
					printf("%s, ","Elf");
				}
				else if(record[p].pType==2)
				{
					printf("%s, ","Human");
				}
				else if(record[p].pType==3)
				{
					printf("%s, ","Ogre");
				}
				else if(record[p].pType==4)
				{
					printf("%s, ","Wizard");
				}
				printf("%d)",i,record[p].lp);
			}
		}
		
		/*for(i=0;i<set;i++)
		{
			if slot on one or both sides are empty
			offer move as an option as well as attack nearest player as an option
			
			else if slot on both sides is full
			attack nearest player
			attack(record[i])
			
			print all player names, types and life points after each move
		}*/

	return 0;
}

/*void makeslots(struct list array[], int slotnum)
{
	int x,z;
	
	for(x=0; x<slotnum; x++)
	{
		
		z=rand()%3;
		
		if (z==0)
		{
			array[x].slottype=0;
		}
		else if (z==1)
		{
			array[x].slottype=1;
        }
        else if (z==2)
		{
			array[x].slottype=2;
		}
    }
	
    for(x=0; x<slotnum; x++)
	{
		printf("%d.%s\n",array[x].slotposition, array[x].slottype);
    }
}*/

void attack(struct list record[],int set,int slotnum, int o)
{
	int j,f,k,z=0,w=0,q,person,diff=0,victim;
	unsigned int other=22;
	
	for(f=0;f<set;f++)
	{
		diff=record[o].slots-record[f].slots;
		
		if(diff<0)
		{
			diff=diff*(-1);
		}
		
		if(diff<other&&diff!=0)
		{
			victim=diff;
			other=diff;
		}
		printf("\nDiff %d: %d",f,diff);
		printf("\nVICTIM %d: %d",f,victim);
		printf("\nOTHER %d: %d",f,other);
	}
	
	other=set-1;
	
	printf("\nPlayers, player %d is allowed to attack:",o);
	for(f=0;f<set;f++)
	{
		if(record[f].slots==record[o].slots+victim)
		{
			printf("\nPlayer %d: %s",f,record[f].player);
			z=f;
		}
		if(record[f].slots==record[o].slots-victim)
		{
			printf("\nPlayer %d: %s",f,record[f].player);
			w=f;
		}
	}
	
	printf("\nEnter the number of the player you would like to attack: ");
	scanf("%d",&person);
	
	while(person!=z||person!=w)
	{
		printf("\nError.");
		printf("\nEnter the number of the player you would like to attack: ");
		scanf("%d",&person);
	}
	
	if(record[person].strength<=70)
	{
		record[person].lp=record[person].lp-(0.5*record[person].strength);
	}
	else if(record[person].strength>70)
	{
		record[o].lp=record[o].lp-(0.3*record[person].strength);
	}
}
