#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0

//����˳���ջ
#define STACK_SIZE 100	//�洢�ռ��ʼ������ 
#define STACK_INC 10	//�洢�ռ����� 
typedef struct {
	char *base;
	char *top;
	int size;
}SqStack;

//�����ն�ջ
intCreatStack(SqStack &S)
{
	S.base=(char *)malloc(static_SIZE*sizeof(char));
	S.top=S.base;
	S.size=STACK_SIZE;
	return OK;
} 

