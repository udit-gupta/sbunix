#include <defs.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[], char* envp[]) {
    uint64_t *test = (uint64_t *)malloc(sizeof(uint64_t));
    *test = 1;
    printf("\nThis is hello1 file\n");
    printf("\nmalloced address is %p and Value at malloced address is %d\n",test,*test);
    printf("\nGoing to sleep for 2 sec\n");
    printf("\nI am going to  exit\n");
    printf("\nGoint to execvpe, I will never print rest of this file\n");

    char *a[]={"-a","-b","-c"};
    char *b[]={"dummy","value","pass"};
    execvpe("bin/hello3",a,b);


    printf("\n P2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    exit(-1);
    return 0;
}
