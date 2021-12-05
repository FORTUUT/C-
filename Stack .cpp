/*********************
数据结构：堆栈之括号匹配
*********************/
#include <stdio.h>
#include <stdlib.h>

//栈的定义
typedef struct
{
    char *base; //栈底
    char *top;  //栈顶
    int size;   //标识栈的大小
} Sqstack;

//栈的创建
int creat(Sqstack &s)
{
    s.base = (char *)malloc(100 * (sizeof(char)));
    s.top = s.base;
    s.size = 100;
    return 0;
}

//入栈
int push(Sqstack &s, char a)
{
    if (s.top - s.base == s.size) //栈满，追加空间
    {
        s.base = (char *)realloc(s.base, s.size + 10 * sizeof(char));
        s.top = s.base + s.size;
        s.size += 10;
    }
    *s.top = a;
    s.top += 1;
    return 0;
}

//出栈
int pop(Sqstack &s, char &a)
{
    if (s.top == s.base)
        return 0;
    s.top -= 1;
    a = *s.top;
    return 0;
}

//判断是否为空栈
int Stackempty(Sqstack &s)
{
    if (s.top == s.base)
        return true;
    else
        return false;
}

//括号匹配
int breacket(Sqstack &s, char *str)
{

    int i = 0;
    char a;
    bool ans = true;
    while (str[i] != '\0')
    {
        switch (str[i])
        {
        case '(': //'('进栈
            push(s, '(');
            break;
        case '[': //'['进栈
            push(s, '[');
            break;
        case '{': //'{'进栈
            push(s, '{');
            break;
        case ')': //出栈，判断是否为'('
            pop(s, a);
            if (a != '(')
                ans = false;
            break;
        case ']': //出栈，判断是否为'['
            pop(s, a);
            if (a != '[')
                ans = false;
            break;
        case '}': //出栈，判断是否为'{'
            pop(s, a);
            if (a != '{')
                ans = false;
            break;
        default:
            break;
        }
        i++;
    }
    if (ans && Stackempty(s))
        printf("括号匹配\n");
    else
        printf("括号不匹配\n");
    return 0;
}

int main(void)
{
    char str[200];
    Sqstack s;
    creat(s);
    printf("请输入字符串:");
    scanf("%s", str);
    breacket(s, str);
    system("pause");
    return 0;
}
