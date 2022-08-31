#include "stdio.h"
#include "../typedefs/type_def.h"
#include "stdlib.h"

void ADD_FL(u32_t x)
{ 
    if(head_ptr==NULL)
    {
        head_ptr = (node_t*)calloc(1,sizeof(node_t)) ;
        head_ptr->Data = x ;
        head_ptr->next_node = NULL ;
        last_ptr= &(head_ptr->next_node) ;
    }
    else
    {
        (*last_ptr)=(node_t*)calloc(1,sizeof(node_t));
        (*last_ptr)->Data=x;
        (*last_ptr)->next_node=NULL;
        last_ptr=&((*last_ptr)->next_node);
    }
    
    return;
    
}