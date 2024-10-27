#include <stdio.h>
#include <stdlib.h>

char global_a = 1;
char global_b = 2;
char global_c = 3;

void func(int level){
    if(level >= 4) return;
    char x = 42;
    printf("@x for func [level = %d] : %p\n",level,&x);
    func(level + 1);
}

int main(){
    char *a = malloc(sizeof(int));
    char *b = malloc(sizeof(int));
    char *c = malloc(sizeof(int));
    printf("heap | @a : %p\n",a);
    printf("heap | @b : %p\n",b);
    printf("heap | @c : %p\n",c);
    func(1);
    printf("@global_a : %p\n",global_a);
    printf("@global_b : %p\n",global_b);
    printf("@global_c : %p\n",global_c);
    return 0;
}