#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 50
void push(char item);
char pop(void);
int top=-1;
int call(char c);
char stack[MAX],input[10],str2[15],str1[8]="",c;
void prn(int j)
{
 int i;
 for(i=j;input[i]!='\0';i++)
 printf("%c",input[i]);
}
void prnstack(int top){
    int i;
 for(i=0;i<top;i++)
 printf("%c",stack[i]);
}
void main()
{
 char str1[6],*cmp="",c[8]="";
 int i=0,cn=0, k,j;
 FILE *ptr, *gptr;
 clrscr();
 printf("\n\n enter the expression :\n");
 scanf("%s",input);
 push('0');
 printf("\n\n\t STACK \t\t COMPARISION \t\t OUTPUT \n\n");
 do
 {
 printf("");
 prnstack(top);
 printf("\t\t");
 prn(i);
 if(strcmp(cmp,"1$")==0)
 {
strcpy(str2,"accepted");
printf("\n\nthe input is accepted");
getch();
exit(0);
 }
 else
 {
cmp[0]=stack[top];
cmp[1]=input[i];
cmp[2]='\0';
if((ptr=fopen("d:\\lrtable.doc","r"))==NULL)
 printf("\n\n FILE CAN NOT BE OPEN");
 else
{
 while(!feof(ptr))
 {
fscanf(ptr, "%s%s",str1,str2);
if(strcmp(str1,cmp)==0)
{
 if(str2[0]=='s')
 {
 push(input[i]);
 push(str2[1]);
 i++;
 break;
 }
else if(str2[0]=='r')
{
 cn=call(str2[1]);
 for(k=0;k<(cn*2);k++)
 pop();
 c[0]=stack[top];
 push(str2[0]);
 c[1]=stack[top];
 c[2]='
\0';
 if(strcmp(c,"0E")==0)
 push('1');
 else if(strcmp(c,"0T")==0)
 push('2');
 else if(strcmp(c,"0F")==0)
 push('3');
 else if(strcmp(c,"0E")==0)
 push('8');
 else if(strcmp(c,"0T")==0)
 push('2');
 else if(strcmp(c,"0F")==0)
 push('3');

else if(strcmp(c,"0T")==0)
 push('9');
 else if(strcmp(c,"0F")==0)
 push('3');
 else if(strcmp(c,"0F")==0)
 push('t');

}
 else if(strcmp(str2,"0")==0) 
 {
 printf("
\
n
\n the string is not accepted");
 break; }

}

}
}
 fclose(ptr);

}
 printf("
\
t
\t%s
\
t
\
t
\n",cmp,str2);

}
 while(input[i]!='
\0');
 getch(); }
int call(char c) {
 int count =0;
 switch(c)

{
 case 1: strcpy(str2,"E
->E+T");
count=3;
break ;
 case 2: strcpy(str2,"E->T");
 count=1;
 break;
 case 3: strcpy(str2,"T->T*F");
 count=3;
 break;
 case 4: strcpy(str2,"T->F");
 count=1;
 break;
 case 5: strcpy(str2,"F->(E)");
 count=3;
 break;
 case 6: strcpy(str2,"F->id");
 count=1;
 break;
 }
 return count ;
 }
void push(char item)
{
 if(top==MAX)
 printf("\n\n stack overflow");
 else
 {
 top=top+1;
 stack[top]=item;
 }
}
char pop(void)
{
 char item;
 if(top==-1)
 printf("\n\n stack underlow");
 else
 {
 item=stack[top];
 top--;
 }
 return item;
}