#pragma once
#define SIZE 10240

typedef struct Request{
  char first_line[SIZE];
  char *method;
  char *url;
  char *url_path;
  char *query_string;
  //char *version
  int content_length;
}Requst;

