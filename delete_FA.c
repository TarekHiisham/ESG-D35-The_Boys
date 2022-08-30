#include <stdio.h>
#include <stdlib.h>
#include "../typedefs/type_def.h"

void Delete_FA(u8_t location);
void Delete_FA(u8_t location)
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
        location--;
        while (temp -> next_node != NULL && location != 0)
        {
            location--;
            previous = temp;
            temp = temp -> next_node;
        }
    
        previous -> next_node = NULL;
        printf ("The data is deleted: %d",temp -> Data);
    }

    free(temp);
    
    return;
}