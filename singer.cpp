#include <stdio.h>
#include <stdlib.h>
struct
{
	float score;
	int rank;
} singer[6];
int main()
{
	int input(int number);
	int su();
	int output();
	printf("Please input singer's score:\n");
	for (int i = 0; i < 6; i++)
	{
		input(i);
		singer[i].rank = 6;
	}
	su();
	output();
	system("pause");
	return 0;
}

int input(int number)
{
	short num[6];
	float ave = 0;
	scanf("%hd %hd %hd %hd %hd %hd", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	float x = num[0];
	for (int i = 0; i < 6; i++)
	{
		float y = num[i];
		if (x > y)
			x = y;
	}
	ave += x;
	x = num[0];
	for (int i = 0; i < 6; i++)
	{
		float y = num[i];
		if (x < y)
			x = y;
	}
	ave += x;
	singer[number].score = ((float)(num[0] + num[1] + num[2] + num[3] + num[4] + num[5]) - ave) / 4;
}
int su()
{
	int temp;
	float x, y;
	for (int a = 0; a < 5; a++)
	{
		for (int i = 0; i < 5; i++)
		{
			x = singer[i].score;
			if (singer[i].rank == 6)
			{
				temp = i;
				break;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			y = singer[i].score;
			if (singer[i].rank != 6 || (i == temp))
				continue;
			if (x < y)
			{
				temp = i;
				x = y;
			}
		}
		singer[temp].rank = a + 1;
	}
}

int output()
{
	int x = 6;
	for (int i = 0; i < 6; i++)
		for (int n = 0; n < x; n++)
			if (singer[n].rank - 1 == i)
				printf("singer:%d   score%.2f\n", n + 1, singer[n].score);
}