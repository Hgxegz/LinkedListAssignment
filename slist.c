#include <stdio.h>
#include <stdlib.h>
#include "slist.h"


snode* snode_create(int data, snode* next){
    snode *s_node = malloc(sizeof(s_node));
    s_node->data = data;
    s_node->next = next;
    return s_node;
}
slist* slist_create(void){
    slist *s_list = malloc(sizeof(slist));
    s_list->head = NULL;
    s_list->tail = NULL;
    s_list->size = 0;
    return s_list;
}

bool slist_empty(slist* list){
    return list->size == 0;
}

size_t slist_size(slist* list){
    return list->size;
}

void slist_popfront(slist* list){ //get rid of the head node
    if(slist_empty(list)){ //if list is empty
        printf("List is empty\n");
        return;
    }
    snode* s_node = list->head;
    list->head = list->head->next;
    free(s_node);
    --list->size;
}

void slist_popback(slist* list){ //get rid of the last node
    if(slist_empty(list)){
        printf("List is empty\n");
        return;
    }
    snode* s_node = list->head;
    while(s_node->next != list->tail){
        s_node = s_node->next;
    }
    s_node->next = NULL;
    free(list->tail);
    list->tail = s_node;
    --list->size;

}

void slist_pushfront(slist* list, int data){ //add node to the front of the list 
    snode *s_node = malloc(sizeof(s_node));
    s_node->data = data;
    if(slist_empty(list)){ //if the list is empty
        s_node->next = NULL;
        list->head = s_node;
        list->tail = s_node;
    } else { //if list is not empty
        s_node->next = list->head;
        list->head = s_node;
    }
    ++list->size;
}

void slist_pushback(slist* list, int data){ //add node to the end of the list
    snode *s_node = malloc(sizeof(s_node));
    s_node->data = data;
    if(slist_empty(list)){ //if list is empty
        s_node->next = NULL;
        list->head = s_node;
        list->tail = s_node;
    } else { //if list is not empty
        list->tail->next = s_node;
        s_node->next = NULL;
        list->tail = s_node;
    }
    ++list->size;
}

void slist_clear(slist* list){
    snode* s_node = malloc(sizeof(s_node));
    snode* temp   = malloc(sizeof(temp));
    if(slist_empty(list)){ //if list is empty already
        printf("nothing to clear out(list empty already\n");
        return;
    } else { //if list is not empty 
        s_node = list->head;
        while(s_node != NULL){
            temp = s_node->next;
            free(s_node);
            s_node = temp;
        }
    }
    list->size = 0;
}

void slist_print(slist* list, const char* msg){
    printf("%s\n" , msg);
    snode* s_node = malloc(sizeof(s_node));
    s_node = list->head;
    while(s_node != NULL){
        printf("%d --> %p\n" , s_node->data , &(s_node->data));
        s_node = s_node->next;
    }
}

int slist_front(slist* list){ //gets data from the first node
    return list->head->data;
}

int slist_back(slist* list){ //gets the data from the last node
    return list->tail->data;
}
