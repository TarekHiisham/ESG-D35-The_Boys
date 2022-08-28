#ifndef Typedef
#define Typedef

typedef unsigned char u8_t ;
typedef unsigned short u16_t ;
typedef unsigned long u32_t ;

typedef signed char s8_t ;
typedef signed short s16_t ;
typedef signed long s32_t ;

typedef float f32_t ;
typedef double f64_t ; 

/* Structure for Node*/
typedef struct linked_node
{
        u32_t Data ;
        struct linked_node * next_node ;
}node_t;

/*Global Variable for all files*/
    
    extern node_t *head_ptr ;
    extern node_t **last_ptr   ;

#endif