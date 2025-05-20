#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile unsigned int counter = 0;

void *mythread(void *arg) {
    printf("%s\n", (char *) arg);
    for (int i = 0; i < 5; i++) {
        counter += 1;
    }
    printf("thread %s counter = %d\n", (char *) arg, counter);
    return NULL;
}

int main(void)
{                    
    pthread_t p1, p2;
    printf("main: begin\n");
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
    printf("main: end counter = %d\n", counter);
    return 0;
}
