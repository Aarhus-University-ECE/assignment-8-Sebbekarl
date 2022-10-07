extern "C"
{
#include "insertion_sort.h"
#include "linked_list.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    int testlist[] ={4,3,10,1,6};
    linked_list* test = createLinkedList();
    for (int i = 0; i < 5; ++i)
    {
        insertFront(createNode(testlist[5-i-1]), test);
    }
    
    printLL(test);
    sort(test);
    printLL(test);


    return 0;
}