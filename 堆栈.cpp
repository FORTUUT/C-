#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

//定义顺序堆栈
#define STACK_SIZE 100 //存储空间初始分配量
#define STACK_INC 10   //存储空间增量
typedef struct
{
	char *base; //栈底
	char *top;	//栈顶
	int size;	//储存空间
} SqStack;

//创建空堆栈
int CreatStack(SqStack &S)
{
	S.base = (char *)malloc(STACK_SIZE * sizeof(char));
	S.top = S.base;
	S.size = STACK_SIZE;
	return OK;
}

//进栈
int Push(SqStack &S, char e)
{
	if (S.top - S.base >= S.size) //栈满，追加存储空间
	{
		S.base = (char *)realloc(S.base, (S.size + STACK_INC) * sizeof(char));
		S.top = S.base + S.size;
		S.size += STACK_INC;
	}
	*S.top = e;
	S.top += 1;
	return OK;
}

//出栈
int Pop(SqStack &S, char &e)
{
	if (S.top == S.base)
		return ERROR;
	S.top -= 1;
	e = *S.top;
	return OK;
}

//括号匹配
int Bracket(SqStack &S, char *str)
{
	int i = 0, flag1 = 0, flag2;
	char e;
	while (str[i] != '\0')
	{
		switch (str[i])
		{
		case '(':
			Push(S, '(');
			break;
		case '[':
			Push(S, '[');
			break;
		case '{':
			Push(S, '{');
			break;
		case ')':
		{
			Pop(S, e);
			if (e != '(')
				flag1 = 1;
			break;
		}
		case ']':
		{
			Pop(S, e);
			if (e != '[')
				flag1 = 1;
			break;
		}
		case '}':
		{
			Pop(S, e);
			if (e != '{')
				flag1 = 1;
			break;
		}
		default:
			break;
		}
		if (flag1)
			break;
		i++;
	}
	flag2 = StackEmpty(S);
	if (!flag1 && flag2)
		printf("括号匹配！\n");
	else
		printf("括号不匹配！\n");
	return OK;
}

//判断是否为空栈
int StackEmpty(SqStack &S){
if(S.top==0) return 1;
else return 0;
} 

//主函数
int main(void)
{
	char temp, flag = 'y';
	while (flag == 'y')
	{
		char str[255];
		SqStack S;
		printf("请输入字符串：");
		scanf("%s", str);
		scanf("%c", &temp);
		CreatStack(S);
		Bracket(S, str);
		printf("你想再试一次吗？(按y继续)：");
		scanf("%c", &flag);
		printf("\n");
	}
	printf("程序结束\n");
	system("pause");
	return 0;
}
