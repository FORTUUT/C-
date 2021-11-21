#include<bits/stdc++.h>
#define num1 94
using namespace std;
char surname[][3]={"ÁÎ","³Â","Àî","ÂÀ","Áõ","Áú","Ñî","Íõ","»Æ","ÕÔ","ÖÜ","Ëï","ÂŞ","ºú","Öì","Îâ","»Æ","¹ù","ÁÖ","¸ß","Ğì","Âí","ºÎ"};
char admini_name[][7]={"ÕÔÍøËë","Áõİ¹ÅÂ","ºú½İ","»Æõ»äı","ÂíäìÇ¤","ÂŞ¼â","»ÆÂ¤Ö¥","Îâ½Ø","ºÎ¹ß","ºÎêÖß¢"};
int *ID;
int id_len=1;
int use_surname=0;
void creat(char *str)
{	
	char name[] = "";
	int length = rand()%2+1, i, a, b;
    int id;
    int check;
	int age=rand()%6+17;
	int s=rand()%2+0;
	int rand_name=rand()%23;
	int rand_admini_name=rand()%10+0;
	int salary=rand()%1000+3000;
	int c=rand()%10+1;
	while(salary%10!=0){
		salary=rand()%1000+3000;
	}
	while(1){
		check=0;
		id=rand()%250+2021100;
		for(int i=0;i<id_len;i++){
			if(id!=*(ID+i)){
				check++;
			}
			if(check==id_len &&i==id_len-1){
				*(ID+id_len-1)=id;
				id_len++;
				ID=(int *)realloc(ID,sizeof(int)*id_len);
				goto l1;
			}
		}
	}
l1:	str = (char*)malloc((2*length + 1)*sizeof(char));
	for(i = 0; i < length; i++)
	{
		a = rand()%(87 - 16 + 1) + 16;
		if(a == 55)
			b = rand()%(89 - 1 + 1) + 1; 
		else
			b = rand()%num1 + 1;
		str[2*i] = a - 96;
		str[2*i + 1] = b - 96; 
	}
	str[2*length] = '\0';
	if(s==1){
		cout<<"insert into Ô±¹¤ values('"<<surname[rand_name]<<str<<"',"<<age<<","<<"'"<<"ÄĞ"<<"',"<<id<<","<<salary<<","<<20210+c<<",'"<<admini_name[rand_admini_name]<<"')"<<endl;
	}
	else{
		cout<<"insert into Ô±¹¤ values('"<<surname[rand_name]<<str<<"',"<<age<<","<<"'"<<"Å®"<<"',"<<id<<","<<salary<<","<<20210+c<<",'"<<admini_name[rand_admini_name]<<"')"<<endl;
	}
}

int main()
{	
    ID=(int *)malloc(sizeof(int)*id_len);
	srand(time(NULL));
	char str[] = "";
	int i;
	for(i=0;i<204;i++)
		creat(str);
	system("pause");
	return 0;
}

