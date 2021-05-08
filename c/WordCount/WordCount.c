#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fpr;
    char name[100] = {0};
	char type[2];
    int ch;
    int number = 0;
    int character = 0;
    int space = 0;
    int total = 0;
	int word = 1;	
	scanf(" %s",type);
    scanf(" %s",name);
    if((fpr = fopen(name,"r")) == NULL)
    {
        printf("Can't open %s\n",name);
        exit(1);
    }
    while((ch = fgetc(fpr)) != EOF)
    {
       if(ch>=48 &&ch<=57)//数字
       {
            number++;
       }
       if((ch>=65&&ch<=90) || (ch>=97&&ch<=122))//字母
       {
           character++;
       }
       if(ch == 32)//空格
       {
           space++;
		   word++;
       }
	   if(ch == 44)
		   word++;
       total++;
    }
	if(strcmp(type,"-c")==0)
		printf("字符数：%d\n",total);
	if(strcmp(type,"-w")==0)
		printf("单词数：%d\n",word);
	system("pause");
	return 0;
}
