#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

typedef struct FdSet{
  fd_set set;
  int max_fd;

}FdSet;

void FdSetInit(FdSet*fdset)
{
  FD_ZERO(&fdset->set);
  fdset->max_fd=0;
  return;
}

void FdSetAdd(FdSet*fdset,int fd)
{
FD_SET(fd,&fdset->set);
if(fd>fdset->max_fd)
{
  fdset->max_fd=fd;
}
}

void FdSetDel(FdSet*fdset,int fd)
{
FD_CLR(fd,&fdset->set);
int max_fd=-1;
int i=0;
for (;i< fdset->max_fd;++i) 
{
  if(!FD_ISSET(i,&fdset->set))
  {
     if(i>max_fd)
     {
       max_fd=i;
     }
  }
  fdset->max_fd=max_fd;
}
}

int ProessRequest(int new_sock)
{
  char buf[1024]={0};
  ssize_t read_size=read(new_sock,buf,sizeof(buf)-1);
  if(read_size<0)
  {
    perror("read");
    return -1;
  }
  if(read_size==0){
    printf("read done!\n");
    return 0;
  }
buf[read_size-1]='\0';
printf("[client%d] say%s\n",new_sock,buf);
write(new_sock,buf,strlen(buf));
return 1;
}

int ServerInit(char*ip,short port)
{
  int fd=socket(AF_INET,SOCK_STREAM,0);
  if(fd<0)
  {
    perror("socket");
    return -1;
  }
  sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr=inet_addr(ip);
  addr.sin_port=htons(port);
  int ret =bind(fd,(sockaddr*)&addr,sizeof(addr));
  if(ret<0)
  {
    perror("bind");
    return -1;
  }
  ret=listen(fd,5);
  if(ret<0)
  {
    perror("listen");
   return -1;
  }
  return fd;
}


int main(int argc, char* argv[]) {
 if(argc!=3)
 {
   printf("uses ./stcpservec [ip][port]");
   return 1;
 }
 //初始化，创建socket
 int listen_sockt =ServerInit(argv[1],atoi(argv[2]));
 if(listen_sockt<0)
   {
     printf("serverinit falied!");
     return 1;
   }
 printf("server init ok!");
 //把lisebt_sock添加到select对于位图
FdSet fds;
FdSetInit(&fds);
FdSetAdd(&fds,listen_sockt);
 while(1)
 {
   FdSet tmp_fds=fds;
  int ret=select(tmp_fds.max_fd + 1,&tmp_fds.set,NULL,NULL,NULL);
  if(ret<0){
    perror("select");
    continue;
  }
  if(FD_ISSET(listen_sockt,&tmp_fds.set)){
  sockaddr_in peer;
  socklen_t len=sizeof(peer);
  int new_sock=accept(listen_sockt,(sockaddr*)&peer,&len);
  if(new_sock<0)
  {
    perror("accept");
      continue;
  }
  FdSetAdd(&tmp_fds,new_sock);
  printf("[client%d]\n",new_sock);
  }
  else{ 
    int i=0;
    for (; i <tmp_fds.max_fd; ++i) {
      if(!FD_ISSET(i,&tmp_fds.set))
      {
        continue;
      }
   int ret= ProessRequest(i);
   if(ret==0)
    {
     //对端关闭
     close(i);
     FdSetDel(&fds,i);
    }
   }
  }
 }
  return 0;
}

