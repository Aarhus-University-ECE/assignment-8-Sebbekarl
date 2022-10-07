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
    node_t *insert_front, *insert_back, *old_back, *old_front, *test_back, *test_front;
    node_t *previous_node = llPtr->head;

    while (curr_node != NULL)
    {
        if (curr_node->data < previous_node->data)
        {
            node_t *node_temp = llPtr->head;
            //printf("%d",curr_node->data);
            
            
            old_back = previous_node;
            old_front = curr_node->next;
            old_back->next = old_front;
            while (node_temp != curr_node)
            {
                
                if(node_temp->data > curr_node->data)
                {
                    
                    insert_front = node_temp;
                    insert_back = node_temp->next;
                    break;
                    //test_back = insert_back;
                    //test_front = insert_front;
                }
                node_temp = node_temp->next; 
            }
            

            printf("%d, %d\n",insert_front->data, insert_back->data,llPtr->head);
            insert_front->next = curr_node;
            curr_node->next = insert_back;
            /*
            if(previous_node == llPtr->head)
            {
                curr_node->next = llPtr->head->next;
                llPtr->head = curr_node;
            }
            */

        }
        
        Sleep(1);
        previous_node = curr_node;
        curr_node = curr_node->next;
    }
}
