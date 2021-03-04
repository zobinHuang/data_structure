#include "link_list.h"

using namespace std;

/*
 * 函数：create_node
 * 描述：创建一个结点
 * 传入列表：[data：要创建的结点的值]
 * 返回值：返回指向新结点的结点指针
 */
node* link_list::create_node(data_type data)
{
    node* new_node = new node(data);
    return new_node;
}

/*
 * 函数：get_node
 * 描述：获取指定序号的结点指针
 * 传入列表：[position：结点位置]
 * 返回值：返回指定序号的结点指针
 */
node* link_list::get_node(int position)
{
    int counter = 0;
    node* temp = head;
    while(counter < position){
        temp = temp->get_next();
        if(temp == NULL)
            return NULL;
        counter++;
    }
    return temp;
}

/*
 * 函数：insert_node
 * 描述：在链表指定位置插入一个结点
 * 传入列表：[data：要插入的结点的值，insert_position：要插入的位置]
 * 返回值：插入成功返回1，插入失败返回0
 */
int link_list::insert_node(data_type data, int insert_position)
{
    node* new_node = create_node(data);
    if(new_node == 0) return 0;

    /*注意链表头节点要单独处理！*/
    if(insert_position == 0){
        /*head不是一个真实的节点！只是一个指针！指向第一个节点！*/
        new_node->set_next(head);
        head = new_node;
    }else{
        int counter = 0;
        node* temp = head;
        while(counter < insert_position - 1){
            temp = temp->get_next();
            /*记得在此处判断条件 “temp != NULL”，防止遍历溢出链表*/
            if(temp == NULL)
                return 0;
            counter++;
        }
        new_node->set_next(temp->get_next());
        temp->set_next(new_node);
    }
    length++;
    return 1;
}

/*
 * 函数：delete_node
 * 描述：删除链表中指定位置的结点
 * 传入列表：[delete_position：要删除的结点位置]
 * 返回值：删除成功返回1，删除失败返回0
 */
int link_list::delete_node(int delete_position)
{
    if(length == 0)
        return 0;

    node* old_node;

    /*注意链表头节点要单独处理！*/
    if(delete_position == 0){
        old_node = head;
        head = old_node->get_next();
        delete old_node;
    }else{
        int counter = 0;
        node* temp = head;
        while(counter < delete_position - 1){
            temp = temp->get_next();
            if(temp == NULL)
                return 0;
            counter++;
        }
        old_node = temp->get_next();
        temp->set_next(old_node->get_next());
        delete(old_node);
    }
    length--;
    return 1;
}

/*
 * 函数：print_list
 * 描述：按序打印出链表中各个结点的值
 * 传入列表：[无]
 * 返回值：无
 */
void link_list::print_list()
{
    for(int i=0; i<length; i++){
        cout << get_node(i)->get_value() << " ";
    }
    cout << endl;
}