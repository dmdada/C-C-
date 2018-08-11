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


int ReadLine(int sock,char buf[],ssize_t size){
  //从socket中一次读取一个字符，如果读到换行\n就返回
  char c='\0';
  ssize_t i=0;
  while(i<size-1 && c!='\n'){
    ssize_t read_size=recv(sock,&c,1,0);
    if(read_size<0){
     return -1;
    }
    if(read_size==0){
     return -1;
    }
    if(c=='\r'){
     recv(sock,&c,1,MSG_PEEK);
     if(c=='\n'){
       recv(sock,&c,1,0);
     }
     else{
       c='\n';//统一换行为\n
     }
    }
    buf[i++]=c;
  }
  buf[i]='\0';
  return i;
}
int Split(char input[],char* split_char,char* output[],int output_size){
int i = 0;
char* tmp=NULL;
char* pch;
//使用线程安全的strtok_r
pch = strtok_r(input,split_char,&tmp);
while(pch != NULL){
  if(i >= output_size){
    return i;
  }
  output[i++]=pch; 
  pch=strtok_r(NULL,split_char,&tmp);
  }
return i;
}
int ParseFirstLine(char first_line[],char** p_url, char** p_method){
  char* tok[10];
  int tok_size=Split(first_line," ", tok, 10);
  if(tok_size!=3){
    printf("Split failed!tok_size=%d\n",tok_size);
    return -1;  
  }
  *p_method=tok[0];
  *p_url=tok[1];
  return 0;
}
int ParseQueryString(char *url,char** p_url_path,char** p_query_string){
  *p_url_path=url;
  char*p=url;
  for(;*p!='\0';++p){
    if(*p=='?'){
      *p='\0';
      *p_query_string=p + 1;
      return 0;
    }
  }
  //无query_string
  *p_query_string=NULL;
  return 0;
}
int ParseHeader(int sock,int *content_length){
  //循环读出一行
  char buf[SIZE]={0};
  while(1){
  ssize_t read_size=ReadLine(sock,buf,sizeof(buf));
  if(read_size<=0){
    return -1;
  }
  if(strcmp(buf,"\n")==0){
   return 0;
  }
//是不是content_length
const char* content_length_str="content_length: ";
  if(content_length!=NULL&&strncmp(buf,content_length_str,strlen(content_length_str))==0){
*content_length=atoi(buf+strlen(content_length_str));
  }
 }
 return 0;
  //空行
}
void Handler404(int sock){
  const char* first_line="HTTP/1.1 404 Not Found\n";
  const char* blank_line="\n";
  const char* html="<h1>你的页面丢失</h1>";
  send(sock, first_line, strlen(first_line),0);
  send(sock, blank_line, strlen(blank_line),0);
  send(sock, html, strlen(html), 0);
  return;
}
int HandlerStaticFile(){
  return 404;
}
int HandlerCGI(){
  return 404;
 }
void PrintfRequest(Request* req){
printf("method: %s\n",req->method);
printf("url_path：%s\n",req->url_path);
printf("query_string: %s\n",req->query_string);
printf("content_length: %d\n",req->content_length);
return;
}

void HandleRequest(int new_sock){
//1.读取并解析请求
//2.静态或者动态生成页面
//3.生成结果，并返回
int err_code=200;
Request req;
memset(&req,0,sizeof(req));
//从socket读出首行
if(ReadLine(new_sock,req.first_line,sizeof(req.first_line))<0){
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
if(ParseHeader(new_sock,&req.content_length)){
err_code=404;
goto END;
}
PrintfRequest(&req);
//2.get请求，无query_string
if(strcasecmp(req.method,"GET")==0&&req.query_string==NULL){
err_code=  HandlerStaticFile();
}
else if (strcasecmp(req.method,"GET")==0&&req.query_string!=NULL){
 err_code= HandlerCGI();
}
else if (strcasecmp(req.method,"POST")==0){
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
printf("server init is ok!\n");
while(1){
sockaddr_in peer;
socklen_t len =sizeof(peer);
int64_t new_sock=accept(listen_sock,(sockaddr*)&peer,&len);
if(new_sock<0){
perror("accept");
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

