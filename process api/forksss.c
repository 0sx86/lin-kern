#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 

int main(int argc, char * argv[]){

    int x = 100;
    int p[2][2],pid1, pid2, nbytes;
    char inbuf[64]; 

    FILE *fptr;
    fptr = fopen("f4k3_f1l3", "w");

    pipe(p); 

    if ((pid1 = fork()) == 0){
        sleep(1);

        printf("[C] before x=%d\n",x);
        x = 50;
        printf("[C] after x=%d\n", x);
        fprintf(fptr, "[C] Some text");
        
        printf("\n\n[C] Hello !\n");

        read(p[1][0], inbuf, 15); 
        printf("% s\n", inbuf); 

    } else {
        if ((pid2 = fork()) == 0){
            printf("\n\n[C] Hello !\n");
            read(p[1][0], inbuf, 15); 
            printf("% s\n", inbuf); 
        } else {
            printf("[F] before x=%d\n", x);
            x = 150;
            printf("[F] after x=%d\n", x);
            fprintf(fptr, "[F] Some text");

            write(p[0][1], msg1, 15); 
            write(p[1][1], msg2, 15);

            wait(NULL); 
            printf("[F] Goodbye !\n");
        }
    }

    return 0;
}