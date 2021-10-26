#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0

//定义顺序堆栈
#define STACK_SIZE 100	//存储空间初始分配量 
#define STACK_INC 10	//存储空间增量 
typedef struct {
	char *base;
	char *top;
	int size;
}SqStack;

//创建空堆栈
intCreatStack(SqStack &S)
{
	S.base=(char *)malloc(static_SIZE*sizeof(char));
	S.top=S.base;
	S.size=STACK_SIZE;
	return OK;
} 

