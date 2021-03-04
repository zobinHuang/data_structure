#include "link_list.h"

/*假设结点数据类型是int, data_type 定义在 link_list.h 中*/
int main()
{
    list_type list = {.length = 0, .head = NULL, .tail = NULL};

    /*创建一个链表*/
    printf("init link list:\n");
    for(int i=0; i< 10; i++){
        data_type data = i;
        node_type* new_node;
        new_node = create_node(data);
        if(new_node == NULL){
            printf("error: create new node at %d\n", i);
            return -1;
        }
        insert_node(&list, new_node, list.length);
    }
    print_list(&list);

    /*测试插入*/
    printf("insert test: \n");
    while(1){
        int insert_position = 0;
        data_type data;
        node_type* new_node;
        
        printf("insert position: (input -1 to exit)");
        scanf("%d", &insert_position);
        if(insert_position != -1){
            printf("insert data: ");
            scanf("%d", &data);
        }
        
        if(insert_position < 0) break;

        new_node = create_node(data);
        if(insert_node(&list, new_node, insert_position))
            print_list(&list);
        else
            printf("error!\n");
    }

    /*测试删除*/
    printf("delete test: \n");
    while(1){
        int delete_position = 0;
        printf("delete position: (input -1 to exit)");
        scanf("%d", &delete_position);

        if(delete_position < 0) break;

        if(delete_node(&list, delete_position))
            print_list(&list);
        else
            printf("error!\n");
    }

    return 0;
}

