#include "insertion_sort.h"
#include "linked_list.h"
#include <windows.h>
#include <stdbool.h>

void sort(linked_list *llPtr)
{
    node_t *curr_node = llPtr->head->next;
    node_t *previous_node = llPtr->head;
    node_t *old_back, *old_front;
    

    while (curr_node != NULL)
    {
        if (curr_node->data < previous_node->data)
        {
            node_t *node_temp = llPtr->head;

            old_back = previous_node;
            old_front = curr_node->next;
            old_back->next = old_front;

            while (node_temp->next->data < curr_node->data)
            {
                node_temp = node_temp->next;
            }

            if (node_temp == llPtr->head)
            {
                curr_node->next = llPtr->head;
                llPtr->head = curr_node;
            }
            else
            {
                curr_node->next = node_temp->next;
                node_temp->next = curr_node;
            }
        }
        previous_node = curr_node;
        curr_node = curr_node->next;
    }
}
