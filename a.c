#include<stdio.h>
void fun(char* str)
{
char tmp='a';
char*src=str+1;
int count =0;
while(*str!='\0')
{  count=0;
  src=str+1;
  while(*src!='\0')
{
if (*str==*src) 
{
  count++;
  tmp=*src;
}
src++;
}
if (count == 1)
{
   printf("找到了字符是：%c\n", tmp);
  return;         
}
str++;

}
printf("没找到！");
}

int main()
{
char*str="abacdebaf";
fun(str);
  return 0;
}
