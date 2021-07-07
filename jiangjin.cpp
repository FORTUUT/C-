#include<stdio.h>
#include<stdlib.h>
int main()
{
	int contr(char contribution,int grade,int *p);
	int game_gra(int num1,int num2,int num3,int *p);
	int study(int num1,int num2,int *p);
	
	int Awards=0;
	struct 
	{
		int study_grade,class_grade;
		int game_grade_1,game_grade_2,game_grade_3;
		char contribution;
	}one;
	
	printf("please input final grade point average:");
	scanf("%d",&one.study_grade);
	printf("the class final grade point average:");
	scanf("%d",&one.class_grade);
	printf("times of the game rank 1:");
	scanf("%d",&one.game_grade_1);
	printf("times of the game rank 2:");
	scanf("%d",&one.game_grade_2);
	printf("times of the game rank 3:");
	scanf("%d",&one.game_grade_3);
	fflush(stdin);
	printf("Class contribution: 'y' or 'n':");
	scanf("%c",&one.contribution);
	
	contr(one.contribution,one.class_grade,&Awards);
	game_gra(one.game_grade_1,one.game_grade_2,one.game_grade_3,&Awards);
	study(one.study_grade,one.class_grade,&Awards);
	
	printf("Awards should be:%d",Awards);
	
	system("pause");
	return 0;
}

int contr(char contribution,int grade,int *p)
{
	if(contribution=='y'&&grade>80)
		*p+=500;
	return 0;
}

int game_gra(int num1,int num2,int num3,int *p)
{
	*p+=num1*800+num2*500+num3*300;
	return 0;
}

int study(int num1,int num2,int *p)
{
	if(num2>90)
	{
		if(num1>95)
		{
			*p+=2000;
			goto end1;
		}
		if(num1>90)
		{
			*p+=1500;
			goto end1;
		}
		if(num1>85)
		{
			*p+=1000;
			goto end1;
		}
		else
			*p+=500;	
		end1:
		fflush(stdin);
	}
	
 	else if(num2>85)
	{
		if(num1>90)
		{
			*p+=1500;
			goto end2;
		}
		if(num1>85)
		{
			*p+=1000;
			goto end2;
		}
		else
			*p+=500;
		end2:
		fflush(stdin);
	}
	else if(num2>80&&num1>85)
		*p+=1000;
	else if(num2>80||num1>85)	
		*p+=500;
	return 0; 
}