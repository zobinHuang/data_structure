#include <iostream>
#include "link_list.hpp"

using namespace std;

int main(){
    cout << "Test initialize link list:" << endl;
    link_list<int> link_list;
    cout << "Finished create link list" << endl;
    for(int i=0; i<10; i++){
        if(!link_list.insert_node(i, i)){
            cout << "Error occurs while inserting " << i << "th node to link list"<< endl;
        }
    }
    link_list.print_list();
    cout << "Finished insert 10 nodes to link list" << endl;

    cout << "Test deleting node:" << endl;
    while(1){
        int delete_position = 0;
        cout << "input the position of delete node (start from 0, type -1 to quit):";
        cin >> delete_position;
        if(delete_position == -1)break;
        link_list.delete_node(delete_position);
        link_list.print_list();
    }
    return 0;
}