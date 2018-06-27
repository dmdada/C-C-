#include<stdio.h>
void move(int n,char form,char to)
{
printf("%d号盘从%c移到%c\n",n,form,to);
}

void hanoi(int n,int p1,int p2,int p3)
{
  if (n==1) {
    move(n,p1,p3);
  }
  else{
    hanoi(n-1,p1,p3,p2);
    move(n,p1,p3);
    hanoi(n-1,p2,p1,p3);
  }
}
int main() {
  printf("please input num!\n");
  int num=0;
  scanf("%d",&num);
  hanoi(num,'A','B','C');
  return 0;
}
