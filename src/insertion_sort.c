#include "insertion_sort.h"
#include "linked_list.h"
#include <windows.h>

void sort(linked_list *llPtr)
{

    // go through array
    // check if number smaller than last element
    // if smaller keep checking until i find one that is bigger or start of list
    // change pointer of the bigger/start element to current one
    // make current one point to the element after the biggest/start
    // connect the ones that were connected on both sides of the moved element
    // repeat through the entire array

    node_t *curr_node = llPtr->head->next;
    node_t *insert_front, *insert_back, *old_back, *old_front;
    node_t *previous_node = llPtr->head;

    while (curr_node != NULL)
    {
        if (curr_node->data < previous_node->data)
        {
            

        }

        Sleep(1);
        previous_node = curr_node;
        curr_node = curr_node->next;
    }
}
