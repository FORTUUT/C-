#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct{
	int num;
	int grade;
	int rank;
}stu[30];
int main()
{	
	int su(int na);
	int output(int na);
	
	int people=0,number=0,tuorfa=1;
	int exce=0,good=0,medi=0,pass=0,npas=0;
	printf("students'number:");
	scanf("%d",&people);
	for(int i=0;i<people;i++)
	{
		printf("input the %2d's number and grade:",i+1);
		scanf("%d %d",&stu[i].num,&stu[i].grade);
		stu[i].rank=people;
	}
	printf("\n\n");
	su(people);
	output(people);
	
	for(int i=0;i<people;i++)
	{
		if(stu[i].grade>=90)
		{
			exce++;
			continue;
		}
		if(stu[i].grade>=80)
		{
			good++;
			continue;
		}
		if(stu[i].grade>=70)
		{
			medi++;
			continue;
		}
		if(stu[i].grade>=60)
		{
			pass++;
			continue;
		}
		else
		{
			npas++;
			continue;
		}
	}
	printf("\n\n");
	printf("Excellent 	students are %d of %.2f%%\n",
						exce,(float)exce/people*100);
	printf("Good 		students are %d of %.2f%%\n",
						good,(float)good/people*100);
	printf("Medium 		students are %d of %.2f%%\n",
						medi,(float)medi/people*100);
	printf("Pass 		students are %d of %.2f%%\n",
						pass,(float)pass/people*100);
	printf("Nopass 		students are %d of %.2f%%\n",
						npas,(float)npas/people*100);
	printf("\n\n");
	while(tuorfa)
	{
		printf("students' number:");
		scanf("%d",&number);
		for(int i=0;i<people;i++)
			if(stu[i].num==number)
				printf("rank:%2d  grade:%3d\n",
						stu[i].rank,stu[i].grade);		
		printf("continue or finish  '1' or '0' :");
		scanf("%d",&tuorfa);
	}
	system("pause");
	return 0;
}
int su(int na)
{
	int temp;
	int x,y;
	for(int a=0;a<na-1;a++)
	{
		for(int i=0;i<na-1;i++)
		{
			x=stu[i].grade;
			if(stu[i].rank==na)
			{
				temp=i;
				break;
			} 
		}
		for(int i=0;i<na;i++)
		{
			y=stu[i].grade;
			if(stu[i].rank!=na||(i==temp))
				continue;
			if(x<y)
			{
				temp=i;
				x=y;
			}	
		}
		stu[temp].rank=a+1;
	}
	return 0;
}
int output(int na)
{
	int x=na;
	for(int i=0;i<na;i++)
		for(int n=0;n<x;n++)
			if(stu[n].rank-1==i)
				printf("number:%2d  grade:%3d   rank:%2d\n",
						stu[n].num,stu[n].grade,stu[n].rank);
	return 0;
}
