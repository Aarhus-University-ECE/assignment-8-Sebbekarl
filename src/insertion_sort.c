#include "insertion_sort.h"
#include "linked_list.h"
#include <windows.h>
#include <stdbool.h>

void sort(linked_list *llPtr)
{
    node_t *current_node = llPtr->head->next;
    node_t *previous_node = llPtr->head;
    node_t *old_rear_node, *old_front_node;
    

    while (current_node != NULL)
    {
        if (current_node->data < previous_node->data)
        {
            node_t *new_rear_node = llPtr->head;

            old_rear_node = previous_node;
            old_front_node = current_node->next;
            old_rear_node->next = old_front_node;

            while (new_rear_node->next->data < current_node->data)
            {
                new_rear_node = new_rear_node->next;
            }

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
        previous_node = current_node;
        current_node = current_node->next;
    }
}
