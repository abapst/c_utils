#ifndef FILEIO_H
#define FILEIO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

#define MAXLINE 2048
#define REMOVEN(s) (s[strcspn(s,"\n")] = 0) // remove newline from strings

struct strlist {
    int n;
    char **data;
};

struct strlist *read_string_list(const char *filename);
void collapse_list(node_t *head, struct strlist *items);
void delete_strlist(struct strlist *items);
void print_strlist(struct strlist *items);

#endif
