#include "link_list.h"

using namespace std;

node* link_list::create_node(data_type data)
{
    node* new_node = new node(data);
    return new_node;
}

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

int link_list::insert_node(data_type data, int insert_position)
{
    node* new_node = create_node(data);
    if(new_node == 0) return 0;

    if(insert_position == 0){
        //head不是一个真实的节点！只是一个指针！指向第一个节点！
        new_node->set_next(head);
        head = new_node;
    }else{
        int counter = 0;
        node* temp = head;
        while(counter < insert_position - 1){
            temp = temp->get_next();
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

int link_list::delete_node(int delete_position)
{
    if(length == 0)
        return 0;

    node* old_node;

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

void link_list::print_list()
{
    for(int i=0; i<length; i++){
        cout << get_node(i)->get_value() << " ";
    }
    cout << endl;
}