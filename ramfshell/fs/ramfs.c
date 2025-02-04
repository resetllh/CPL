#include "ramfs.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

node *root = NULL;

#define NRFD 4096
FD fdesc[NRFD];

int get_size(int fd) {
    return fdesc[fd].f->size;
}

int get_problem(const char* pathname) {
    if(pathname[0] != '/') return 1;
    char* pro_path = get_process(pathname, false);
    node* p = root;
    while(strstr(pro_path, p->name) == pro_path) {
        if(strlen(pro_path) == strlen(p->name)) {
            free(pro_path);
            return 0;
        }
        if(p->type == FNODE) {
            free(pro_path);
            return 2;
        }
        bool flag = false;
        for(int i = 0; i < p->nrde; i++) {
            if(p->dirents[i] != NULL && strstr(pro_path, p->dirents[i]->name) == pro_path) {
                p = p->dirents[i];
                flag = true;
                break;
            }
        }
        if(!flag) {
            free(pro_path);
            return 1;
        }
    }
}

int find_flag(const char* pathname, bool is_par) {
    if(pathname[0] != '/') return -2;
    char* pro_path = get_process(pathname, is_par);
    node* p = root;
    while(strstr(pro_path, p->name) == pro_path) {
        if(strlen(pro_path) == strlen(p->name)) {
            free(pro_path);
            return 1;
        }
        if(p->dirents == NULL) {
            free(pro_path);
            if(p->type == FNODE)
                return -1;
            else
                return -2;
        }
        bool flag = false;
        for(int i = 0; i < p->nrde; i++) {
            if(p->dirents[i] != NULL && strstr(pro_path, p->dirents[i]->name) == pro_path) {
                p = p->dirents[i];
                flag = true;
                break;
            }
        }
        if(!flag) {
            free(pro_path);
            return -2;
        }
    }
}

bool is_legal_char(char s) {
    return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')
            || (s == '.') || (s >= '0' && s <='9');
}

bool is_legal_base(const char* basename) {
    if(strlen(basename) > 32) return false;
    for(int i = 0; basename[i]; i++)
        if(!is_legal_char(basename[i]))
            return false;
    return true;
}

char* copy_str(const char* pathname) {
    int len = strlen(pathname) + 1;
    char* s = malloc(len * sizeof(char));
    s = strcpy(s, pathname);
    return s;
}

char* process(char* pathname) {
    int len = strlen(pathname) + 1;
    char* s = malloc(len * sizeof(char));
    strcpy(s, "/");
    char* p = strtok(pathname, "/");
    while(p != NULL) {
        strcat(s, p);
        p = strtok(NULL, "/");
        if(p != NULL)
            strcat(s, "/");
    }
    return s;
}

char* par_process(char* pathname) {
    int len = strlen(pathname) + 1;
    char* s = malloc(len * sizeof(char));
    strcpy(s, "/");
    char* p = strtok(pathname, "/");
    char* q = strtok(NULL, "/");
    while(q != NULL) {
        strcat(s, p);
        p = q;
        q = strtok(NULL, "/");
        if(q != NULL)
            strcat(s, "/");
    }
    return s;
}

char* get_process(const char* pathname, bool is_par) {
    char* s = copy_str(pathname);
    char* p;
    if(is_par)
        p = par_process(s);
    else
        p = process(s);
    free(s);
    return p;
}

node *find(const char *pathname) {
    if(pathname == NULL || pathname[0] != '/') return NULL;
    char* pro_path = get_process(pathname, false);
    node* p = root;
    while(strstr(pro_path, p->name) == pro_path) {
        if(strlen(pro_path) == strlen(p->name)) {
            free(pro_path);
            return p;
        }
        if(p->dirents == NULL) {
            free(pro_path);
            return NULL;
        }
        bool flag = false;
        for(int i = 0; i < p->nrde; i++) {
            if(strstr(pro_path, p->dirents[i]->name) == pro_path) {
                p = p->dirents[i];
                flag = true;
                break;
            }
        }
        if(!flag) {
            free(pro_path);
            return NULL;
        }
    }
}

int ropen(const char *pathname, int flags) {
    int tag = 0;
    if((O_TRUNC | O_WRONLY | O_RDWR) == flags) tag = O_TRUNC | O_WRONLY;
    else if((O_CREAT | O_WRONLY | O_RDWR) == flags) tag = O_CREAT | O_WRONLY;
    else if((O_APPEND | O_WRONLY) == flags) tag = O_APPEND | O_WRONLY;
    else if((O_APPEND | O_RDWR) == flags) tag = O_APPEND | O_RDWR;
    else if((O_CREAT | O_WRONLY) == flags) tag = O_CREAT | O_WRONLY;
    else if((O_CREAT | O_RDONLY) == flags) tag = O_CREAT | O_RDONLY;
    else if((O_CREAT | O_RDWR) == flags) tag = O_CREAT | O_RDWR;
    else if(O_CREAT == flags) tag = O_CREAT;
    else if(O_RDONLY == flags) tag = O_RDONLY;
    else if(O_WRONLY == flags) tag = O_WRONLY;
    else if(O_RDWR) tag = O_RDWR;

    if(pathname == NULL || pathname[0] != '/')
        return -1;

    node* p = find(pathname);
    if(p == NULL) {
        if((tag & O_CREAT) != 0) {
            p = rmkfile(pathname);
            if(p == NULL)
                return -1;
        }
        else {
            return -1;
        }
    }


    if(p->type == FNODE && (tag & O_TRUNC) != 0) {
        if(p->content != NULL)
            free(p->content);
        p->content = NULL;
        p->size = 0;
    }

    int i = 0;
    while(i < NRFD && fdesc[i].used == true)
        i++;
    if(i == NRFD)
        return -1;

    fdesc[i].used = true;
    fdesc[i].flags = tag;
    fdesc[i].f = p;
    fdesc[i].offset = ((tag & O_APPEND) == 0) ? 0: p->size;

    return i;
}

int rclose(int fd) {
    if(fd < 0 || fd >= NRFD || fdesc[fd].used == false)
        return -1;
    
    fdesc[fd].used = false;
    fdesc[fd].flags = 0;
    fdesc[fd].offset = 0;
    fdesc[fd].f = NULL;
    return 0;
}

ssize_t rwrite(int fd, const void *buf, size_t count) {
    if(fd < 0 || fd >= NRFD || fdesc[fd].used == false || buf == NULL || count < 0)
        return -1;
    
    if((fdesc[fd].flags & 03) == 0)
        return -1;

    if(fdesc[fd].f->type == DNODE)
        return -1;
    
    if(fdesc[fd].f->content == NULL) {
        ssize_t cnt = fdesc[fd].offset + count;
        fdesc[fd].f->content = malloc(sizeof(char) * cnt);
        fdesc[fd].f->size = cnt;

        char* content = (char*) fdesc[fd].f->content;
        char* buffer = (char*) buf;
        for(int i = 0; i < fdesc[fd].offset; i++)
            content[i] = '\0';
        for(int i = 0; i < count; i++) {
            content[fdesc[fd].offset] = buffer[i];
            fdesc[fd].offset++;
        }
        return count;
    }
    else {
        int size = fdesc[fd].f->size;
        if(size < count + fdesc[fd].offset) {
            fdesc[fd].f->content = realloc(fdesc[fd].f->content, (count + fdesc[fd].offset) * sizeof(char));
            fdesc[fd].f->size = count + fdesc[fd].offset;
        }
        char* content = (char*) fdesc[fd].f->content;
        char* buffer = (char*) buf;
        for(int i = size; i < fdesc[fd].offset; i++)
            content[i] = '\0';
        for(int i = 0; i < count; i++) {
            content[fdesc[fd].offset] = buffer[i];
            fdesc[fd].offset++;
        }
        return count;
    }
}

ssize_t rread(int fd, void *buf, size_t count) {
    if(fd < 0 || fd >= NRFD || fdesc[fd].used == false || buf == NULL || count < 0)
        return -1;

    if((fdesc[fd].flags & 01) == 1)
        return -1;
    
    if(fdesc[fd].f->type == DNODE)
        return -1;
    
    char* buffer = (char*) buf;
    char* content = (char*) fdesc[fd].f->content;

    ssize_t cnt = 0;
    while(cnt < count && fdesc[fd].offset < fdesc[fd].f->size) {
        buffer[cnt] = content[fdesc[fd].offset];
        cnt++;
        fdesc[fd].offset++;
    }
    return cnt;
}

off_t rseek(int fd, off_t offset, int whence) {
    if((whence != SEEK_CUR) && (whence != SEEK_END) && (whence != SEEK_SET))
        return -1;
    
    if(fd < 0 || fd >= NRFD)
        return -1;
    
    if(fdesc[fd].used == false || fdesc[fd].f->type == DNODE)
        return -1;

    off_t of = offset;
    if(whence == SEEK_CUR)
        of += fdesc[fd].offset;
    else if(whence == SEEK_END)
        of += fdesc[fd].f->size;
    
    if(of < 0)
        return -1;

    fdesc[fd].offset = of;
    return of;
}

int rmkdir(const char *pathname) {
    if(pathname == NULL || pathname[0] != '/')
        return -1;
    
    node* p = find(pathname);
    if(p != NULL)
        return -1;
    
    char* par = get_process(pathname, true);
    node* q = find(par);
    free(par);
    if(q == NULL || q->type == FNODE)
        return -1;
    
    char* pro_path = get_process(pathname, false);
    char* basename = pro_path + strlen(q->name);
    if(basename[0] == '/') basename++;
    if(!is_legal_base(basename)) {
        free(pro_path);
        return -1;
    }

    int index = q->nrde;
    q->nrde++;
    if(q->dirents == NULL)
        q->dirents = malloc(sizeof(node*));
    else
        q->dirents = realloc(q->dirents, q->nrde * sizeof(node*));

    q->dirents[index] = malloc(sizeof(node));
    q->dirents[index]->name = malloc(sizeof(char) * (strlen(pro_path) + 1));
    strcpy(q->dirents[index]->name, pro_path);
    free(pro_path);

    q->dirents[index]->type = DNODE;
    q->dirents[index]->dirents = NULL;
    q->dirents[index]->nrde = 0;
    q->dirents[index]->content = NULL;
    q->dirents[index]->size = 0;
    return 0;
}

node* rmkfile(const char *pathname) {
    if(pathname == NULL || pathname[0] != '/')
        return NULL;
    
    node* p = find(pathname);
    if(p != NULL)
        return p;

    char* par = get_process(pathname, true);
    node* q = find(par);
    free(par);
    if(q == NULL || q->type == FNODE)
        return NULL;

    char* pro_path = get_process(pathname, false);
    char* basename = pro_path + strlen(q->name);
    if(basename[0] == '/') basename++;
    if(!is_legal_base(basename)) {
        free(pro_path);
        return NULL;
    }

    int index = q->nrde;
    q->nrde++;
    if(q->dirents == NULL)
        q->dirents = malloc(sizeof(node*));
    else
        q->dirents = realloc(q->dirents, q->nrde * sizeof(node*));

    q->dirents[index] = malloc(sizeof(node));
    q->dirents[index]->name = malloc(sizeof(char) * (strlen(pro_path) + 1));
    strcpy(q->dirents[index]->name, pro_path);
    free(pro_path);
    q->dirents[index]->type = FNODE;
    q->dirents[index]->dirents = NULL;
    q->dirents[index]->nrde = 0;
    q->dirents[index]->content = NULL;
    q->dirents[index]->size = 0;
    return q->dirents[index];
}

int rrmdir(const char *pathname) {
    node* p = find(pathname);
    if(p == NULL || p->type == FNODE || p == root || p->nrde != 0) 
        return -1;

    char* par = get_process(pathname, true);
    node* q = find(par);
    free(par);
    for(int i = 0; i < q->nrde; i++)
        if(q->dirents[i] == p) {
            q->dirents[i] = q->dirents[q->nrde - 1];
            q->nrde--;
            break;
        }
    if(q->nrde == 0) {
        free(q->dirents);
        q->dirents = NULL;
    }
    else
        q->dirents = realloc(q->dirents, q->nrde * sizeof(node*));
    
    if(p->name != NULL) {
        free(p->name);
        p->name = NULL;
    }
    if(p->dirents != NULL) {
        free(p->dirents);
        p->dirents = NULL;
    }
    free(p);
    p = NULL;
    return 0;
}

int runlink(const char *pathname) {
    node* p = find(pathname);
    if(p == NULL || p->type == DNODE)
        return -1;
    char* par = get_process(pathname, true);
    node* q = find(par);
    free(par);

    for(int i = 0; i < q->nrde; i++)
        if(q->dirents[i] == p) {
            q->dirents[i] = q->dirents[q->nrde - 1];
            q->nrde--;
            break;
        }
    if(q->nrde == 0) {
        free(q->dirents);
        q->dirents = NULL;
    }
    else
        q->dirents = realloc(q->dirents, q->nrde * sizeof(node*));
    
    for(int i = 0; i < NRFD; i++)
        if(fdesc[i].used == true && fdesc[i].f == p) {
            fdesc[i].used = false;
            fdesc[i].offset = 0;
            fdesc[i].flags = 0;
            fdesc[i].f = NULL;
        }
    
    if(p->name != NULL) {
        free(p->name);
        p->name = NULL;
    }
    if(p->content != NULL) {
        free(p->content);
        p->content = NULL;
    }
    free(p);
    p = NULL;
    return 0; 
}

void init_ramfs() {
    root = malloc(sizeof(node));
    root->name = malloc(sizeof(char) * 2);
    strcpy(root->name, "/");
    root->type = DNODE;
    root->dirents = NULL;
    root->nrde = 0;
    root->content = NULL;
    root->size = 0;
}

void free_node(node* p) {
    if(p == NULL)
        return;
    if(p->name != NULL) {
        free(p->name);
        p->name = NULL;
    }
    if(p->content != NULL) {
        free(p->content);
        p->content = NULL;
    }
    if(p->dirents != NULL) {
        for(int i = 0; i < p->nrde; i++)
            free_node(p->dirents[i]);
        p->dirents = NULL;
    }
    free(p);
}

void close_ramfs() {
    free_node(root);
    root = NULL;
}