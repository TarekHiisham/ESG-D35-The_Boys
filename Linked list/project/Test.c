#include "stdio.h"
#include "../typedefs/type_def.h"

void ADD_FL(u32_t data) ;
void Delete_FL(void) ;
void ADD_FA(u32_t data , u8_t location);
void Delete_FA(node_t** head, u8_t location);
void printList(node_t *node);

node_t *head_ptr=NULL ;
node_t **last_ptr=NULL ;

int main(void){

    return 0 ;
}

