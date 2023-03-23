//Dining Philosophy Problem (Monitor)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forks[N];
pthread_cond_t cond_vars[N];

void pickup_forks(int phil_num) {
    pthread_mutex_lock(&forks[phil_num]);
    pthread_mutex_lock(&forks[(phil_num + 1) % N]);
}

void return_forks(int phil_num) {
    pthread_mutex_unlock(&forks[phil_num]);
    pthread_mutex_unlock(&forks[(phil_num + 1) % N]);
}

void *philosopher(void *arg) {
    int phil_num = *((int*)arg);
    printf("Philosopher %d is thinking\n", phil_num + 1);

    while(1) {
        pthread_mutex_lock(&forks[phil_num]);
        while(pthread_mutex_trylock(&forks[(phil_num + 1) % N]) != 0) {
            pthread_cond_wait(&cond_vars[phil_num], &forks[phil_num]);
        }
        printf("Philosopher %d is eating\n", phil_num + 1);
        sleep(2);

        return_forks(phil_num);

        pthread_cond_signal(&cond_vars[(phil_num + 1) % N]);
        pthread_mutex_unlock(&forks[phil_num]);

        printf("Philosopher %d is thinking\n", phil_num + 1);
        sleep(2);
    }
}

int main() {
    pthread_t threads[N];
    int phil_num[N];
    int i;

    for(i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&cond_vars[i], NULL);
    }

    for(i = 0; i < N; i++) {
        phil_num[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &phil_num[i]);
    }

    for(i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}