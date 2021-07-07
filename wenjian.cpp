#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2,*fp3;
	int number(FILE *P);
	int num1=0,num2=0;
	int min=0,node=0,smaller=0;
	
	fp1=fopen("f01.txt","r");
	fp2=fopen("f02.txt","r");
	fp3=fopen("f.txt","w");
	
	num1=number(fp1);
	num2=number(fp2);
	
	
	int a=1;
	min=INT_MIN;
	for(int i=0;i<num1+num2;i++)
	{
		int n=1;
		if(i>0)
			min=smaller;
		smaller=INT_MAX;
		rewind(fp1);
		for(int i=0;i<num1;i++)
		{
			fscanf(fp1,"%d",&node);
			if(node==min)
			{
		 		if(n<=a)
		 		{
		 			n++;
 					continue;
				}
				else
				{
					smaller=node;
					a++;
					goto bottom;
				}
			}
			if(node<min)
				continue; 
			if(node<smaller)
				smaller=node;
		}
		rewind(fp2);
		for(int i=0;i<num2;i++)
		{
			fscanf(fp2,"%d",&node);
			if(node==min)
			{
		 		if(n<=a)
		 		{
		 			n++;
 					continue;
				}
				else
				{
					smaller=node;
					a++;
					goto bottom;
				}
			}
			if(node<min)
				continue; 
			if(node<smaller)
				smaller=node;
		}
		bottom:
		fprintf(fp3,"%d ",smaller);
		if(smaller!=min)
			a=1;
	}
	printf("!!SUCCESSED!!\n");
	system("pause");
	return 0;
}
int number(FILE *p)
{
	int num=0,n,b;
	while(true)
	{
		fscanf(p,"%d",&b);
		if(ftell(p)==n)
			break;
		n=ftell(p);
		num++;
	}
	return num;
}