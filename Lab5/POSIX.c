#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

sem_t empty, full, mutex;
int buffer[BUFFER_SIZE], in, out;

void* producer(void* arg){
    int data=0;
    while(data<=10){
        data++;
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = data;
        printf("生产者 生产了%d，放在位置%d\n",data, in);
        in=(in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg){
    int data=0;
    while(data<=10){
        sem_wait(&full);
        sem_wait(&mutex);
        data=buffer[out];
        printf("消费者 消费了%d，从位置%d\n",data, out);
        out=(out+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(3);
    }
    return NULL;
}

int main() {
    sem_init(&empty, 0, BUFFER_SIZE);   
    sem_init(&full,  0, 0);             
    sem_init(&mutex, 0, 1);             

    pthread_t prod_thread, cons_thread;

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}