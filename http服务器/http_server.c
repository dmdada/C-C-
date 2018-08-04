#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include"http_server.h"
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

void HandleRequest(int new_sock){
//1.读取并解析请求
//2.静态或者动态生成页面
//3.生成结果，并返回
int err_code=200;
Request req;
memset(&req,0,sizeof(req));
//从socket读出首行
if(ReadLine(new_sock,req.first_line)<0){
err_code=404;
goto END;
}
//解析url和method
if(ParseFirstLine(req.first_line,&req.url,&req.method)){

err_code=404;
goto END;
}
//解析url中url_path和query_string
if(ParseQueryString(req.url,&req.url_path,&req.query_string)){

err_code=404;
goto END;
}
//处理头
if(ParseHeader(sock,&req.content_length)){
}

err_code=404;
goto END;
//2.get请求，无query_string
if(strcmp(req.method,"GET")==0&&req.query_string==NULL){

err_code=  HandlerStaticFile();
}
else if (strcmp(req.method,"GET")==0&&req.query_string!=NULL){
 err_code= HandlerCGI();
}
else if (strcmp(req.method,"POST")==0){
 err_code= HandlerCGI();
}
else{
END:
  if(err_code!=200){
    Handler404(new_sock);
  }
  close(new_sock);
  return;
  //错误处理
 }
//  b)如果有参数，返回动态页面
//  如果请求POST请求（一定带参数，参数通过body来传给服务器，那么也返回动态界面。
//  
 }



void* ThreadEntry(void* arg){
  int64_t new_sock = (int64_t)arg;
  HandleRequest(new_sock); //具体处理请求过程
  return NULL;
}
void Http_ServerStart(const char *ip,short port){
int listen_sock=socket(AF_INET,SOCK_STREAM,0);
if(listen_sock<0){
  perror("socket");
  return;
}
sockaddr_in addr;
addr.sin_family=AF_INET;
addr.sin_port=htons(port);
addr.sin_addr.s_addr=inet_addr(ip);
int ret=bind(listen_sock,(sockaddr*)&addr,sizeof(addr));
if(ret<0){
perror("bind");
return;
}
ret=listen(listen_sock,5);
if(ret<0){
  perror("listen");
  return;
}
printf("server init is ok!");
while(1){
sockaddr_in peer;
socklen_t len =sizeof(peer);
int64_t new_sock=accept(listen_sock,(sockaddr*)&peer,&len);
if(new_sock<0){
perror("accept";)
return;
}
pthread_t tid;
pthread_create(&tid,NULL,ThreadEntry,(void*)new_sock);
pthread_detach(tid);
}
}


int main(int argc, char* argv[]) {
  if(argc!=3){
    printf("usage.http_server[ip][port]\n");
    return 1;
  }
  Http_ServerStart(argv[1],atoi(argv[2]));
  return 0;
}

