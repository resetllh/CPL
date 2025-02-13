#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#define O_APPEND 02000
#define O_CREAT 0100
#define O_TRUNC 01000
#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

typedef struct node {
  enum { FNODE, DNODE } type;
  struct node **dirents; // if DTYPE
  void *content;
  int nrde;
  char *name;
  int size;
} node;

typedef struct FD {
  bool used;
  int offset;
  int flags;
  node *f;
} FD;

typedef intptr_t ssize_t;
typedef uintptr_t size_t;
typedef long off_t;

int get_size(int fd);
int get_problem(const char* pathname);
int find_flag(const char* pathname, bool is_par);
char* get_process(const char* pathname, bool is_par);
int ropen(const char *pathname, int flags);
int rclose(int fd);
ssize_t rwrite(int fd, const void *buf, size_t count);
ssize_t rread(int fd, void *buf, size_t count);
off_t rseek(int fd, off_t offset, int whence);
int rmkdir(const char *pathname);
node* rmkfile(const char* pathname);
int rrmdir(const char *pathname);
int runlink(const char *pathname);
void init_ramfs();
void close_ramfs();
node *find(const char *pathname);