#include "fileio.h"


void collapse_list(node_t *head, struct strlist *items)
{
    int cnt = 0;
    node_t *current = head;
    node_t *prev = NULL;

    while(current != NULL) {
        items->data[cnt++] = (char *)current->data;
        prev = current;
        current = current->next;
        free(prev);
    }
}


struct strlist *read_strlist(const char *filename)
{
    FILE *fd = fopen(filename,"r");

    if (fd == NULL) {
        fprintf(stderr,"File %s not found!\n",filename);
        exit(-1);
    }

    int cnt = 0;
    char *buf = malloc(MAXLINE);
    node_t *list = list_init();

    /* build list */
    while (fgets(buf,MAXLINE,fd) != NULL) {
        REMOVEN(buf);
        char *buf2 = malloc(MAXLINE);
        strncpy(buf2,buf,MAXLINE);
        if (cnt == 0) {
            list->id = cnt;
            list->data = buf2;
            cnt++;
        } else {
            push_end(list,cnt++,buf2);
        }
    }
    fclose(fd);
    free(buf);

    if (cnt == 0) {
        fprintf(stderr,
            "[read_strlist]: nothing to read in file %s\n", filename);
        return NULL;
    }

    struct strlist *items = malloc(sizeof(struct strlist));
    items->n = cnt;
    items->data = malloc((items->n)*sizeof(char *));

    collapse_list(list,items);

    return items;
}


void delete_strlist(struct strlist *items)
{
    int ii;
    for (ii = 0; ii < items->n; ii++) {
        free(items->data[ii]);
    }
    free(items->data);
    free(items);
}


void print_strlist(struct strlist *items)
{
    int ii;
    printf("List length = %d\n",items->n);
    for (ii = 0; ii < items->n; ii++) {
        printf("%s\n",items->data[ii]);
    }
}
