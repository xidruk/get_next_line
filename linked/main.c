#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct mystruct{
    void *content;
    struct mystruct *next;
    
} mals;


int main()
{
    mals *node1;
    mals *node2;


    node1->content = "khalid barkan";
    node2->content = "khalid barkan";


    printf("%s", (char *)node1->content);

    return (0);
}