#include <stdio.h>
#include <stdlib.h>
#include "type_def.h"

extern node_t *head_ptr ;

void del_any_node(node_t *head_ptr , u32_t nth);
void del_any_node(node_t *head_ptr , u32_t nth)
{
    node_t* temp = head_ptr;
    node_t* previous = (node_t*) malloc(sizeof(node_t));

    if (head_ptr == NULL)
    {
        printf("The linked list is empty");
        return;
    }

    else if (temp -> next_node == NULL)
    {
        printf("The data is deleted: %d",(head_ptr) -> Data);
        head_ptr = NULL;
    }
    
    else
    {
        nth--;
        while (temp -> next_node != NULL && nth != 0)
        {
            nth--;
            previous = temp;
            temp = temp -> next_node;
        }
    
        previous -> next_node = NULL;
        printf ("The data is deleted: %d",temp -> Data);
    }

    free(temp);
    
    return;
}