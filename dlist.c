#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dlist.h"


dnode* dnode_create(int data, dnode* prev, dnode* next){
    dnode* d_node = malloc(sizeof(d_node));
    d_node->data = data;
    d_node->next = next;
    d_node->prev = prev;
    return d_node;
}

dlist* dlist_create(void){
    dlist* d_list = malloc(sizeof(d_list));
    d_list->head = NULL;
    d_list->tail = NULL;
    d_list->size = 0;
    return d_list;
}

bool dlist_empty(dlist* list){ //if the list is empty or not
    return list->size == 0;
}

size_t dlist_size(dlist* list){ //size of the list
    return list->size;
}

void dlist_popfront(dlist* list){ //get rid of first node
    if(dlist_empty(list)){
        return;
    }
    dnode* d_node = list->head->next;
    free(list->head);
    d_node->next->prev = d_node;
    list->head = d_node;
    --list->size;
}

void dlist_popback(dlist* list){ //get rid of last node
    if(dlist_empty(list)){
        return;
    }
    dnode* d_node = list->tail->prev;
    free(list->tail);
    d_node->next = NULL;
    list->tail = d_node;
    --list->size;
}

void dlist_pushfront(dlist* list, int data){
    if(dlist_empty(list)){
        dnode* d_node = malloc(sizeof(d_node));
        d_node->data = data;
        d_node->next = NULL;
        d_node->prev = NULL;
        list->head = d_node;
        list->tail = d_node;
    } else {
        dnode* d_node = malloc(sizeof(d_node));
        d_node->data = data;
        d_node->next = list->head;
        d_node->prev = NULL;
        list->head->prev = d_node;
        list->head = d_node;
    }
    ++list->size;
}
void dlist_pushback(dlist* list, int data){
     if(dlist_empty(list)){
        dnode* d_node = malloc(sizeof(d_node));
        d_node->data = data;
        d_node->next = NULL;
        d_node->prev = NULL;
        list->head = d_node;
        list->tail = d_node;
    } else {
        dnode* d_node = malloc(sizeof(d_node));
        d_node->data = data;
        d_node->next = list->tail->next;
        d_node->prev = list->tail;
        list->tail->next = d_node;
        list->tail = d_node;
    }
    ++list->size;
}

void dlist_clear(dlist* list){
    dnode* d_node = malloc(sizeof(d_node));
    dnode* d_temp = malloc(sizeof(d_temp));
    d_node = list->head;
    while(d_node != NULL){
        d_temp = d_node->next;
        free(d_node);
        d_node = d_temp;
    }
    list->size = 0;
}

void dlist_print(dlist* list, const char* msg){
    printf("%s\n" , msg);
    dnode* d_node = malloc(sizeof(d_node));
    d_node = list->head;
    while(d_node != NULL){
        printf("%14p <-- %d (%p) --> %p\n", &(d_node->prev->data), d_node->data, &(d_node->data), &(d_node->next->data));
        d_node = d_node->next;
    }
}

int dlist_front(dlist* list){
    return list->head->data;
}

int dlist_back(dlist* list){
    return list->tail->data;
}

