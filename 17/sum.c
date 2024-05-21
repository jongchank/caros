/*
 * Generated by ChatGPT and edited by a human
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 806400000
#define NUM_THREADS 1
#define CHUNK_SIZE (ARRAY_SIZE / NUM_THREADS)

unsigned char array1[ARRAY_SIZE];
unsigned char array2[ARRAY_SIZE];
unsigned char result[ARRAY_SIZE];

typedef struct {
    int start_index;
    int end_index;
} ThreadData;

void* add_arrays(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int start = data->start_index;
    int end = data->end_index;

    for (int i = start; i < end; ++i) {
        result[i] = array1[i] + array2[i];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    struct timespec start, end;

    // Initialize the arrays with some values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array1[i] = i;
        array2[i] = i;
    }

    // Get the start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Create threads to add array chunks
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].start_index = i * CHUNK_SIZE;
        thread_data[i].end_index = (i + 1) * CHUNK_SIZE;
        pthread_create(&threads[i], NULL, add_arrays, (void*)&thread_data[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the elapsed time
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;

    // Print the execution time
    printf("Execution time: %f seconds\n", elapsed_time);

    return 0;
}
