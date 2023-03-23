//Producers and Consumers using Limited Buffer
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <random>
#include <unistd.h>

using namespace std;

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in_index = 0, out_index = 0;

sem_t full, empty_sem;
pthread_mutex_t mutex;

void* produce(void* arg) {
    while (1) {
        sleep(rand() % 2);
        sem_wait(&empty_sem);
        pthread_mutex_lock(&mutex);
        buffer[in_index] = 1;
        cout << "Produced at Index - " << in_index << endl;
        in_index = (in_index + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void* consume(void* arg) {
    while (1) {
        sleep(rand() % 3);
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        buffer[out_index] = 0;
        cout << "Consumed at Index - " << out_index << endl;
        out_index = (out_index + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
    }
}

int main() {
    pthread_t producer, consumer;
    sem_init(&empty_sem, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&producer, NULL, produce, NULL);
    pthread_create(&consumer, NULL, consume, NULL);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    sem_destroy(&empty_sem);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
