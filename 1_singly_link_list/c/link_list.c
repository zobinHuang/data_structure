#include "link_list.h"

/*
 * 函数：get_node
 * 描述：获取指定序号的结点指针
 * 传入列表：[list：链表结构指针，index：结点位置]
 * 返回值：返回指定序号的结点指针
 */
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

/*
 * 函数：create_node
 * 描述：创建一个结点
 * 传入列表：[data：要创建的结点的值]
 * 返回值：返回指向新结点的结点指针
 */
node_type* create_node(data_type data)
{
    node_type* new_node = (node_type*)malloc(sizeof(node_type));
    if(new_node == NULL) return NULL;
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}

/*
 * 函数：insert_node
 * 描述：在链表指定位置插入一个结点
 * 传入列表：[list：链表结构指针，new_node：要插入的结点，location_index：要插入的位置]
 * 返回值：插入成功返回1，插入失败返回0
 */
int insert_node(list_type* list, node_type* new_node, int location_index)
{
    /*注意链表头节点要单独处理！*/
    if(location_index == 0){
        /*head不是一个真实的节点！只是一个指针！指向第一个节点！*/
        new_node->next = list->head;
        list->head = new_node;
    }else{
        int counter = 0;
        node_type* temp = list->head;
        
        while(counter < location_index-1){
            temp = temp->next;
            /*记得在此处判断条件 “temp != NULL”，防止遍历溢出链表*/
            if(temp == NULL)
                return 0;
            counter++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    list->length++;
    return 1;
}

/*
 * 函数：delete_node
 * 描述：删除链表中指定位置的结点
 * 传入列表：[list：链表结构指针，location_index：要删除的结点位置]
 * 返回值：删除成功返回1，删除失败返回0
 */
int delete_node(list_type* list, int location_index)
{
    if(list->length == 0)
        return 0;

    /*注意链表头节点要单独处理！*/
    if(location_index == 0){
        node_type* temp = list->head;
        list->head = temp->next;
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
        free(s);
    }
    list->length--;
    return 1;
}

/*
 * 函数：print_list
 * 描述：按序打印出链表中各个结点的值
 * 传入列表：[list：链表结构指针]
 * 返回值：无
 */
void print_list(list_type* list)
{
    for(int i=0; i<list->length; i++){
        printf("%d ", get_node(list, i)->data);
    }
    printf("\n");
}