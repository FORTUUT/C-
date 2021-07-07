#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int capital=0;
	int time=0;
	int way=0;
	float rate=0;
	float deposit=0;
	
	scanf("%d %d",&capital,&time);
	switch(time)
	{
		case 1:
			rate=0.0225;
			break;
		case 2:
			rate=0.0243;
			break;
		case 3:
			rate=0.0243;
			break;
		case 5:
			rate=0.0288;
			break;
		case 8:
			rate=0.0300;
			break;
		default:
			printf("Error year!");
			return 0;
	}
	printf("fuli is 1 putonglixi is 0\n");
	scanf("%d",&way);
	
	
	if(way)//���� 
	{
		deposit=capital*pow(1+rate,time);
	}
	else//��ͨ��Ϣ 
	{
		deposit=capital*(1+rate*time);
	}
	
	printf("the money you can take is %.4f\n",deposit);
	
	system("pause");
	return 0;
}