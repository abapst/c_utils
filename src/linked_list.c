#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


node_t *list_init()
{
    node_t *head = malloc(sizeof(node_t));
    head->next = NULL;
    head->data = NULL;
    head->id = 0;
    return head;
}


void print_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        printf("%d ",current->id);
        current = current->next;
    }
    printf("\n");
}


void push_end(node_t *head, int id, void *data)
{
    node_t *current = head;

    while(current->next != NULL) {
      current = current->next;
    }

    current->next = malloc(sizeof(node_t));
    current->next->next = NULL;
    current->next->data = data;
    current->next->id = id;
}


void push_start(node_t **head, int id, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->id = id;
    new_node->data = data;

    new_node->next = *head;
    *head = new_node;
}


node_t *pop_start(node_t **head)
{
    node_t *next_node = NULL;
    node_t *retval = NULL;

    if (*head == NULL) {
        return NULL;
    }

    next_node = (*head)->next;
    retval = *head;
    *head = next_node;

    return retval;
}


node_t *pop_end(node_t **head)
{
    node_t *current = *head;
    node_t *retval = NULL;

    if (*head == NULL) {
        return NULL;
    }

    if (current->next == NULL) {
        *head = NULL;
        return current;
    }

    while(current->next->next != NULL) {
        current = current->next;
    }

    retval = current->next;
    current->next = NULL;
    return retval;
}


void delete_node(node_t *node)
{
    free(node->data);
    free(node);
}


void delete_list(node_t **head)
{
    node_t *current = *head;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        delete_node(current);
        current = next;
    }
    *head = NULL;
}


node_t *reverse_list(node_t *head)
{
    node_t *prev = NULL;
    node_t *current = head;
    node_t *temp;

    while(current->next != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    current->next = prev;
    return current;
}


int list_length(node_t *head)
{
    int cnt = 1;
    node_t *current = head;

    while (current->next != NULL) {
        current = current->next;
        cnt++;
    }

    return cnt;
}
