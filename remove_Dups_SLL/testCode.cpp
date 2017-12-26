//check if 1 array is subset (non contiguous) of another array
#include <iostream>
#include "../linkedList/linkedList.h"

using namespace std;

int main() {

    linkedList sll;
    sll.insert_end(0);
    sll.insert_end(1);
    sll.insert_end(2);
    sll.insert_end(3);
    
//     sll.insert_pos(99,5);
//     sll.delete_end();
//     sll.delete_pos(1);
    
    sll.printNodes();
    return 0;
}