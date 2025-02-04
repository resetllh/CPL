#include "ramfs.h"
#include "shell.h"
#ifndef ONLINE_JUDGE
  #define print(...) printf("\033[31m");printf(__VA_ARGS__);printf("\033[0m");
#else
  #define print(...) 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct path_node{
  char* name;
  int size;
  struct path_node* next;
} path_node;

typedef struct path_list{
  path_node* head;
  path_node* tail;
} path_list;

path_list* pal = NULL;

void free_path() {
  if(pal == NULL)
    return;
  path_node* p = pal->head;
  while(p != NULL) {
    path_node* p1 = p;
    p = p->next;
    free(p1->name);
    free(p1);
  }
  free(pal);
  pal = NULL;
}

void init_path(char* content) {
  if(pal != NULL)
    free_path();
  pal = malloc(sizeof(path_list));
  int size = strlen(content);
  path_node* new_node = malloc(sizeof(path_node));
  new_node->name = malloc(sizeof(char) * (size + 1));
  strcpy(new_node->name, content);
  new_node->size = size;
  new_node->next = NULL;
  pal->head = new_node;
  pal->tail = new_node;
}

void add_head(char* content) {
  if(pal == NULL) {
    init_path(content);
    return;
  }
  int size = strlen(content);
  path_node* new_node = malloc(sizeof(path_node));
  new_node->name = malloc(sizeof(char) * (size + 1));
  strcpy(new_node->name, content);
  new_node->size = size;
  new_node->next = pal->head;
  pal->head = new_node;
}

void add_tail(char* content) {
  if(pal == NULL) {
    init_path(content);
    return;
  }
  int size = strlen(content);
  path_node* new_node = malloc(sizeof(path_node));
  new_node->name = malloc(sizeof(char) * (size + 1));
  strcpy(new_node->name, content);
  new_node->size = size;
  new_node->next = NULL;
  pal->tail->next = new_node;
  pal->tail = new_node;
}

void display_path() {
  if(pal == NULL)
    return;
  path_node* p = pal->head;
  while(p != NULL) {
    printf("%s", p->name);
    p = p->next;
    if(p != NULL)
      printf(":");
  }
}


int sls(const char *pathname) {
  print("ls %s\n", pathname);
  int flag;
  if(pathname[0] == '\0')
    flag = find_flag("/", false);
  else 
    flag = find_flag(pathname, false);
  if(flag == -1) {
    printf("ls: cannot access '%s': Not a directory\n", pathname);
    return 1;
  }
  if(flag == -2) {
    printf("ls: cannot access '%s': No such file or directory\n", pathname);
    return 1;
  }
  node* p;
  if(pathname[0] != '\0')
    p = find(pathname);
  else
    p = find("/");
  if(p->type == DNODE) {
    for(int i = 0; i < p->nrde; i++) {
      int len = strlen(p->name);
      char* pos = p->dirents[i]->name + len;
      if(pos[0] == '/')
        pos++;
      printf("%s ", pos);
    }
  }
  else printf("%s", pathname);
  printf("\n");
  return 0;
}

int scat(const char *pathname) {
  print("cat %s\n", pathname);
  int flag = find_flag(pathname, false);
  if(flag == -1) {
    printf("cat: %s: Not a directory\n", pathname);
    return 1;
  }
  if(flag == -2) {
    printf("cat: %s: No such file or directory\n", pathname);
    return 1;
  }
  node* p = find(pathname);
  if(p->type == DNODE) {
    printf("cat: %s: Is a directory\n", pathname);
    return 1;
  }
  char* content = (char*) p->content;
  for(int i = 0; i < p->size; i++)
    printf("%c", content[i]);
  printf("\n");
  return 0;
}

int smkdir(const char *pathname) {
  print("mkdir %s\n", pathname);
  if(pathname[0] != '/') {
    printf("mkdir: cannot create directory '%s': No such file or directory\n", pathname);
    return 1;
  }
  node* p = find(pathname);
  if(p != NULL) {
    printf("mkdir: cannot create directory '%s': File exists\n", pathname);
    return 1;
  }
  else {
    char* par = get_process(pathname, true);
    p = find(par);
    if(p != NULL) {
      if(p->type == FNODE) {
        printf("mkdir: cannot create directory '%s': Not a directory\n", pathname);
        free(par);
        return 1;
      }
      else {
        rmkdir(pathname);
        free(par);
        return 0;
      }
    }
    else {
      int pid = get_problem(par);
      if(pid == 1) {
        printf("mkdir: cannot create directory '%s': No such file or directory\n", pathname);
        free(par);
        return 1;
      }
      else {
        printf("mkdir: cannot create directory '%s': Not a directory\n", pathname);
        free(par);
        return 1;
      }
    }
  }
}

int stouch(const char *pathname) {
  print("touch %s\n", pathname);
  if(pathname[0] != '/') {
    printf("touch: cannot touch '%s': No such file or directory\n", pathname);
    return 1;
  }
  node* p = find(pathname);
  if(p != NULL) {
    if(p->type == FNODE)
      return 0;
    else {
      printf("touch: cannot touch '%s': Not a directory\n", pathname);
      return 1;
    }
  }
  else {
    char* par = get_process(pathname, true);
    p = find(par);
    if(p != NULL) {
      if(p->type == FNODE) {
        printf("touch: cannot touch '%s': Not a directory\n", pathname);
        free(par);
        return 1;
      }
      else {
        rmkfile(pathname);
        free(par);
        return 0;
      }
    }
    else {
      int pid = get_problem(par);
      if(pid == 1) {
        printf("touch: cannot touch '%s': No such file or directory\n", pathname);
        free(par);
        return 1;
      }
      else {
        printf("touch: cannot touch '%s': Not a directory\n", pathname);
        free(par);
        return 1;
      }
    }
  }
}

int secho(const char *content) {
  print("echo %s\n", content);
  int i = 0, len = strlen(content);
  while(i < len) {
    if(content[i] == '\\') {
      if(i + 1 < len) {
        if(content[i + 1] == '$') {
          printf("$");
          i += 2;
        }
        else {
          i += 1;
        }
      }
    }
    else if(content[i] == '$') {
      display_path();
      i += 5;
    }
    else {
      printf("%c", content[i]);
      i++;
    }
  }
  printf("\n");
  return 0;
}

int swhich(const char *cmd) {
  // display_path();
  print("which %s\n", cmd);
  if(pal == NULL) {
    printf("\n");
    return 1;
  }
  path_node* p = pal->head;
  while(p != NULL) {
    // printf("pname %s\n", p->name);
    node* q = find(p->name);
    int l = strlen(q->name);
    if(q != NULL && q->type == DNODE) {
      for(int i = 0; i < q->nrde; i++) {
        char* r= q->dirents[i]->name + l;
        if(r[0] == '/')
          r++;
        if(strcmp(r, cmd) == 0) {
          printf("%s\n", q->dirents[i]->name);
          return 0;
        }
      }       
    }
    p = p->next;
  }
  printf("\n");
  return 1;
}

void init_shell() {
  int fd = ropen("/home/ubuntu/.bashrc", O_RDONLY);
  if(fd != -1) {
    int size = get_size(fd);
    void* buf = malloc(sizeof(char) * (size + 1) );
    int cnt = rread(fd, buf, size);
    char* buffer = (char*) buf;
    buffer[size] = '\0';

    char* row = strtok(buffer, "\n");
    while(row != NULL) {
      char* content = row;
      while(content[0] != '=')
        content++;
      content++;
      char* p = content;
      while(p[0] != '\0' && p[0] != ':')
        p++;
      if(p[0] == ':') {
        p[0] = '\0';
        if(content[0] == '$')
          add_tail(content + 6);
        else 
          add_head(content);
      }
      else {
        init_path(content);
      }
      row = strtok(NULL, "\n");
    }
  }
}

void close_shell() {
  free_path();
}