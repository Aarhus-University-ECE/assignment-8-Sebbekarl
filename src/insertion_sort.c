#include "insertion_sort.h"
#include "linked_list.h"
#include <windows.h>
#include <stdbool.h>

void sort(linked_list *llPtr)
{
    node_t *current_node = llPtr->head->next;
    node_t *previous_node = llPtr->head;
    node_t *old_rear_node, *old_front_node;

    /* loops through the entire list sorting each element */
    while (current_node != NULL)
    {
        /* checks if element needs to be sorted*/
        if (current_node->data < previous_node->data)
        {
            /* removes the node from the list to sort it */
            old_rear_node = previous_node;
            old_front_node = current_node->next;
            old_rear_node->next = old_front_node;

            /* finds the new position for the node so that it is sorted */
            node_t *new_rear_node = llPtr->head;
            while (new_rear_node->next->data < current_node->data)
            {
                new_rear_node = new_rear_node->next;
            }

            /* places the node at the sorted position */
            if (new_rear_node == llPtr->head)
            {
                current_node->next = llPtr->head;
                llPtr->head = current_node;
            }
            else
            {
                current_node->next = new_rear_node->next;
                new_rear_node->next = current_node;
            }
        }
        /* moves on to the next element in the list */
        previous_node = current_node;
        current_node = current_node->next;
    }
}
