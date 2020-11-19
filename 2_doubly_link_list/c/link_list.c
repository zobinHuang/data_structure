#include "link_list.h"

node_type* get_node(list_type* list, int index)
{
    int counter = 0;
    node_type* temp = list->head;
    while(counter < index){
        temp = temp->next;
        if(temp == NULL)
            return NULL;
        counter ++;
    }

    return temp;
}

node_type* create_node(data_type data)
{
    node_type* new_node = (node_type*)malloc(sizeof(node_type));
    if(new_node == NULL) return NULL;
    new_node->next = NULL;
    new_node->prior = NULL;
    new_node->data = data;
    return new_node;
}

int insert_node(list_type* list, node_type* new_node, int location_index)
{
    if(location_index == 0){
        new_node->next = list->head;
        if(list->head != NULL) //important!!!
            list->head->prior = new_node;
        list->head = new_node;
    }else{
        int counter = 0;
        node_type* temp = list->head;
        while(counter < location_index-1){
            temp = temp->next;
            if(temp == NULL)
                return 0;
            counter++;
        }
        new_node->next = temp->next;
        new_node->prior = temp;
        if(temp->next != NULL) //important!!!
            temp->next->prior = new_node;
        temp->next = new_node;
    }
    list->length++;
    return 1;
}

int delete_node(list_type* list, int location_index)
{
    if(list->length == 0)
        return 0;

    if(location_index == 0){
        node_type* temp = list->head;
        list->head = temp->next;
        if(list->head != NULL)//important!
            list->head->prior = NULL;
        free(temp);       
    }else{
        int counter = 0;
        node_type* temp = list->head;
        while(counter < location_index-1){
            temp = temp->next;
            if(temp == NULL)
                return 0;
            counter++;
        }
        node_type* s = temp->next;
        temp->next = s->next;
        if(s->next != NULL)//important!
            s->next->prior = temp;
        free(s);
    }
    list->length--;
    return 1;
}

void print_list(list_type* list)
{
    for(int i=0; i<list->length; i++){
        printf("%d ", get_node(list, i)->data);
    }
    printf("\n");
}