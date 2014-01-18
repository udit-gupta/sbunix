#include <stdio.h>
#include <defs.h>
#include <stdlib.h>
int j;
int main(int argc, char* argv[], char* envp[]) {
   j = fork();
    if(j==0) { 
        printf("I am a child of %d with id %d\n", getppid(), getpid());   
        
    }
    else {
            printf("I am a parent with id %d\n" , getpid());   
    }

    exit(1);
    return 0;
}
