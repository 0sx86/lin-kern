#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid){
    printf("[%d] Hello, threading world !\n", tid);
    pthread_exit(NULL);
}

int main(int argc, char * argv[]){
    pthread_t thread[NUMBER_OF_THREADS];
    int status, i;
    for(i=0;i<NUMBER_OF_THREADS;++i){
        printf("[*] Creating thread %d\n", i);
        status = pthread_create(&thread[i], NULL, print_hello_world, (void *)i);

        if(status != 0){
            printf("[!] Thread returned error code : %d\n", status);
            exit(-1);
        }
    }

    exit(0);
}