#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct student
{
	int num;
	struct student *next;
} LinkList;

int main()
{

	LinkList *tim(LinkList * p);
	LinkList *dele(LinkList * de);

	LinkList *head, *node, *end;
	head = (LinkList *)malloc(sizeof(LinkList));
	end = head;
	end->num = 1;
	for (int i = 1; i < 30; i++)
	{

		node = (LinkList *)malloc(sizeof(LinkList));
		end->next = node;
		end = node;
		end->num = (i + 1);
	}
	end->next = head;

	node = head;
	for (int i = 1; i <= 30; i++)
	{

		//printf("%5d\t",node->num);
		if (i % 5 == 0)
			printf("\n");
		node = node->next;
	}

	node = head;
	for (int i = 2, sum = 0; sum < 15; i++)
	{
		node = tim(node); //iΪ�������Ԫ�ص�����
		if (i == 8)
		{
			//printf("%d\n",node->num);
			dele(node);
			//printf("%d\n",node->num);
			i = 0;
			sum++;
		}
	}

	node = head;
	printf("the students' number:\n");
	for (int i = 1; i <= 15; i++)
	{

		printf("%5d\t", node->num);
		if (i % 5 == 0)
			printf("\n");
		node = node->next;
	}
	system("pause");
	return 0;
}

LinkList *tim(LinkList *p)
{
	LinkList *one;
	one = p->next;
	return one;
}

LinkList *dele(LinkList *de)
{
	LinkList *after;
	after = de->next;
	after = after->next;
	//free(after);
	de->next = after;
	return 0;
}