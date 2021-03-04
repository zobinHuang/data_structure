#include <stdio.h>
#include <malloc.h>

/*数据类型*/
typedef int data_type;

/*结构体：结点*/
typedef struct node_type{
    data_type data;
    struct node_type* prior;
    struct node_type* next;
}node_type;

/*结构体：链表*/
typedef struct list_type{
    node_type* head;
    node_type* tail;
    int length;
}list_type;

node_type* get_node(list_type* list, int index);
node_type* create_node(data_type data);
int insert_node(list_type* list, node_type* new_node, int location_index);
int delete_node(list_type* list, int location_index);
void print_list(list_type* list);



