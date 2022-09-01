 #include <stdio.h>
#include "stdlib.h"
#include "../typedefs/type_def.h"
         
                /* print List*/        
void PRINT(node_t *node)
{
  if(node==NULL){
        printf("Empty List!");
  }            
  else{
  while (node != NULL)
  {
     printf(" %d ", node->Data);
     node = node->next_node ;
  }
  }
  printf("\n");
  return ;
}