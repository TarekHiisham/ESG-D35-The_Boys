#include <stdio.h>
#include <stdlib.h>
#include "../typedefs/type_def.h"

void Delete_FA(node_t** head, u8_t location);
void Delete_FA(node_t** head, u8_t location)
{
    node_t* temp = *head;
    node_t* previous = (node_t*) malloc(sizeof(node_t));

    if (*head == NULL)
    {
        printf("The linked list is empty");
        return;
    }

    else if (temp -> next_node == NULL)
    {
        printf("The data is deleted: %d",(*head) -> Data);
        *head = NULL;
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
    
        previous -> next_node = temp -> next_node;
        printf ("The data is deleted: %d",temp -> Data);
    }

    free(temp);
    
    return;
}