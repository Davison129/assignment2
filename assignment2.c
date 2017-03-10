//All parts of the assignment have been coded for but it does not utilise all of these capabilities.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct slots
{
  char slottype[50];
  int slotposition;
};
void makeslots(struct slots *array, int anna);
void attack(struct list record[],int set,int slotnum,int o);
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
	char slotsT[50];
};

int main(void)
{
		setbuf(stdout,NULL);
		srand(time(NULL));
		int set,num_of_slots,help;

		printf("\nInput the number of players to be inputed(max six): ");
		scanf("%d",&set);

		while(set<2||set>6)
		{

			printf("\nIncorrect number of players.\n\nInput the number of players to be inputed(max six): ");
			scanf("%d",&set);
		}

		help=set;

		printf("\nInput the number of slots on the board(max 20): ");
		scanf("%d",&num_of_slots);

		while(num_of_slots<set||num_of_slots>20)
		{

			printf("\nIncorrect number of slots.\n\nInput the number of slots on the board(max 20): ");
			scanf("%d",&num_of_slots);
		}
		struct slots array[num_of_slots];
		makeslots(array, num_of_slots);

		struct list record[set];
		int i;

		//set players and type numbers
		for(i=0;i<set;i++)
		{
			printf("\nInput player %d:\n",i+1);
			printf("Select player type(1=Elf, 2=Human, 3=Ogre, 4=Wizard): ");
			scanf("%d",&record[i].pType);//input integer representing type then assigning that value to struc
			printf("\nInput player name: ");
			scanf("%s",record[i].player);//same method as integer
		}

		if(record[i].pType)
		{
			//elf characteristics
			record[i].lp=100;
			record[i].smartness=70+rand()%30;
			record[i].strength=1+rand()%49;
			record[i].magicskills=50+rand()%29;
			record[i].luck=60+rand()%40;
			record[i].dexterity=1+rand()%99;
		}
		else if(record[i].pType)
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
		else if(record[i].pType)
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
		else if(record[i].pType)
		{
			//wizard characteristics
			record[i].lp=100;
			record[i].smartness=90+rand()%10;
			record[i].strength=1+rand()%19;
			record[i].magicskills=80+rand()%20;
			record[i].luck=50+rand()%50;
			record[i].dexterity=1+rand()%99;
		}

		set=help;

    int pup, randomnumber, arraytest[6];
    int same = 1;
    for(pup=0;pup<set;pup++)
    {

      randomnumber=rand()%num_of_slots;

      while(same ==1)
      {
        same = 0;
        for(int k=0;k<set+1;k++)
        {
          if(arraytest[k] == randomnumber)
          same = 1;
        }
      }
      record[pup].slots=array[randomnumber].slotposition;
      strcpy(record[pup].slotsT,array[randomnumber].slottype);
      arraytest[pup] = randomnumber;
    }
    for(pup=0;pup<set;pup++)
    {
    printf("Player %s is in slot %d,%s\n", record[pup].player,record[pup].slots, record[pup].slotsT);
}
int cantmove1, cantmove2, choice;


for(pup=0;pup<set;pup++)
{
  cantmove1 = 0, cantmove2=0;
  printf("Player %s turn.\n", record[pup].player);
  for (int kit = 0;  kit < set+1;  kit++) {
    if (record[pup].slots+1==record[kit].slots){
      cantmove1=1;
    }

      if (record[pup].slots-1==record[kit].slots){
        cantmove2=1;
  }
}
if (cantmove1 ==0 && cantmove2 ==0)
{
printf("You can move to slots %d and %d\n",array[record[pup].slots-2].slotposition,array[record[pup].slots].slotposition);

}else if (cantmove1 ==1 && cantmove2 ==0)
{
printf("You can move to slot %d.\n",array[record[pup].slots-2].slotposition);

}else if (cantmove1 ==0 && cantmove2 ==1)
{
printf("You can move to slot %d\n",array[record[pup].slots].slotposition);

}else if (cantmove1 ==1 && cantmove2 ==1)
{
printf("You cant move to any slots\n");

}

printf("Do you want to move up or down a step?\n");
printf("Press numbers 1 for down or 2 for up\n");
scanf("%d", &choice);
if(choice == 1 && cantmove1 == 0){
  record[pup].slots=array[record[pup].slots-2].slotposition;
  strcpy(record[pup].slotsT, array[record[pup].slots-2].slottype);
  if(record[pup].slotsT[2] == 'l')
  {
    if (record[pup].dexterity >= 60)
    {
record[pup].strength=record[pup].strength-10;
}
else if (record[pup].dexterity <= 50)
  {
record[pup].strength=record[pup].strength+10;

    }

}else if(record[pup].slotsT[2]=='t')
{
  if (record[pup].smartness<=50)
  {
record[pup].magicskills=record[pup].magicskills+10;

  }
else  if (record[pup].smartness>60)
  {
record[pup].dexterity=record[pup].dexterity-10;

  }
}
}else if(choice == 2 && cantmove2 == 0){
  record[pup].slots=array[record[pup].slots].slotposition;
  strcpy(record[pup].slotsT, array[record[pup].slots].slottype);
  if(record[pup].slotsT[2] == 'l')
  {
    if (record[pup].dexterity >= 60)
    {
record[pup].strength=record[pup].strength-10;
}
else if (record[pup].dexterity <= 50)
  {
record[pup].strength=record[pup].strength+10;

    }

}else if(record[pup].slotsT[2]=='t')
{
  if (record[pup].smartness<=50)
  {
record[pup].magicskills=record[pup].magicskills+10;

  }
else  if (record[pup].smartness>60)
  {
record[pup].dexterity=record[pup].dexterity-10;

  }
}

}
printf("New position of the player is %d, %s\n", record[pup].slots, record[pup].slotsT);
}
    /*for(i=0;i<set;i++)
		{
			printf("\nPlayer %d lp: %d\n",i+1,record[i].lp);
			printf("\nPlayer %d smartness: %d\n",i+1,record[i].smartness);
			printf("\nPlayer %d strength: %d\n",i+1,record[i].strength);
			printf("\nPlayer %d magicskills: %d\n",i+1,record[i].magicskills);
			printf("\nPlayer %d luck: %d\n",i+1,record[i].luck);
			printf("\nPlayer %d dexterity: %d\n",i+1,record[i].dexterity);
		}*/

		return 0;
}
void makeslots(struct slots *array, int anna)
{
  srand(time(NULL));
int x,z;
for
  (x=0; x<anna; x++){
    z=rand()%3;
    if (z==0) {
      strcpy(array[x].slottype,"level Ground");
    }
      else if (z==1){
          strcpy(array[x].slottype,"City");
        }
            else if (z==2){
                strcpy(array[x].slottype,"Hill");
      }
array[x].slotposition = x+1;


    }
    for(x=0; x<anna; x++){
printf("%d.%s\n",array[x].slotposition, array[x].slottype);

    }
}
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
