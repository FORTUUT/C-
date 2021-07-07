#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int output(int *p,int num,int n);
 	int feedback[40]={0};
 	int times[10]={0};
 	int max=0,mode=0,med1=0,med2=0;
 	float mean=0,median=0;
	for(int i=0;i<40;i++)
		scanf("%d",&feedback[i]); 
	for(int i=0;i<10;i++)
		for(int n=0;n<40;n++)
			if(feedback[n]==i+1)
				times[i]++;
	for(int i=0;i<10;i++)
		if(max<times[i])
			max=times[i];
	for(int i=0;i<10;i++)
		output(times+i,i,max);
	for(int i=0;i<max+17;i++)
		printf("-");
	printf("\n");
	for(int i=0;i<40;i++)//ƽ���� 
		mean+=feedback[i];	
	mean/=40;
	for(int i=0,x=0;i<10;i++)//���� 
		if(x<times[i])
		{
			x=times[i];
			mode=i+1;
		}
	for(int i=0,x=0;i<10;i++)//��λ�� 
	{
		for(int n=0;n<40;n++)
		{
			if(feedback[n]==i+1)
				x++;
			if(x==20&&median==0)
				median+=i+1;
			if(x==21)
			{
				median+=i+1;
				goto out;
			}
		}
	}
	out:
	median/=2;
	printf("mean is %.2f median is %.2f mode is %d\n",mean,median,mode);
	system("pause");
	return 0;
}
int output(int *P,int num,int n)
{
	for(int i=0;i<n+17;i++)
		printf("-");
	printf("\n");
	printf("|  %-3d|  %-3d|",num+1, *P);
	for(int i=0;i<*P;i++)
		printf("%c",42);
	for(int i=0;i<n+3-(*P);i++)
		printf(" ");
	printf("|");
	printf("\n");
	return 0;
}
	
	