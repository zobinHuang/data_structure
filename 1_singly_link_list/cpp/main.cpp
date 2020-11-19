#include "link_list.h"

using namespace std;

/*assume data_type is int, data_type is defined in link_list.h*/
int main()
{
    link_list list;
    
    /*create a init link list*/
    for(int i=0; i<10; i++){
        if(!list.insert_node(i, list.get_length())){
            cout << "failed to create node at " << i << endl;
            return -1;
        }
    }
    list.print_list();

    /*insert test*/
    cout << "insert test" << endl;
    while(1){
        int insert_position = 0;
        int insert_data = 0;
        cout << "insert position + insert data: (input -1 for insert position to exit)";
        cin >> insert_position;
        if(insert_position != -1) cin >> insert_data;
        else break;
        if(list.insert_node(insert_data, insert_position)) list.print_list();
        else cout << "error!" << endl;
    }

    /*delete test*/
    cout << "delete test" << endl;
    while(1){
        int delete_position = 0;
        cout << "delete position: (input -1 for delete position to exit)";
        cin >> delete_position;
        if(delete_position == -1) break;
        if(list.delete_node(delete_position)) list.print_list();
        else cout << "error!" << endl;
    }

    return 1;
}