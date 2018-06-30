#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
 int pid;

pid= fork();
if (pid<0)
{
printf("error");  
}
if (pid==0)
{
printf("i am parent pocess %d\n",getpid());  
}

else
{
printf("i am chilid pocess %d\n",getpid());
}
sleep(2);
wait();
return 0;
}
