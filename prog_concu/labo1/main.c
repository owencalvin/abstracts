#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

enum lockType {
    disabled,
    busyWaiting,
    yield,
    mutex
};

void *create_thread(void *args[2]) {
    int *value = (int *)args[0];
    int *number_of_iterations = (int *)args[1];

    for (int i = 0; i < *number_of_iterations; i++) {
        (*value)++;
    }

    pthread_exit(NULL);
}

void *create_thread_busy_waiting(void *args[2]) {
    int *value = (int *)args[0];
    int *number_of_iterations = (int *)args[1];
    int *locked = (int *)args[2];

    for (int i = 0; i < *number_of_iterations; i++) {
        while (*locked != 0) { }
        *locked = 1;
        (*value)++;
        *locked = 0;
    }

    pthread_exit(NULL);
}

void *create_thread_yield(void *args[2]) {
    int *value = (int *)args[0];
    int *number_of_iterations = (int *)args[1];
    int *locked = (int *)args[2];

    for (int i = 0; i < *number_of_iterations; i++) {
        while (*locked != 0) {
            sched_yield();
        }
        *locked = 1;
        (*value)++;
        *locked = 0;
    }

    pthread_exit(NULL);
}

void *create_thread_mutex(void *args[2]) {
    int *value = (int *)args[0];
    int *number_of_iterations = (int *)args[1];
    pthread_mutex_t *mutex = (pthread_mutex_t *)args[2];

    for (int i = 0; i < *number_of_iterations; i++) {
        pthread_mutex_lock(mutex);
        (*value)++;
        pthread_mutex_unlock(mutex);
    }

    pthread_exit(NULL);
}

int create_threads(const int number_of_threads, const int number_of_iterations, void *function(void *args[2]), void **args) {
    pthread_t threads[number_of_threads];

    // Create the threads
    for (int i = 0; i < number_of_threads; i++) {
        if (pthread_create(&threads[i], NULL, function, args)) {
            perror("thread creation error");
            return EXIT_FAILURE;
        }
    }

    // Join the threads
    for (int i = 0; i < number_of_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("thread join error");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int main() {
    int exit_code = EXIT_SUCCESS;
    int number_of_threads = 10000;
    int number_of_iterations = 10000;
    int mode = 1;

    printf("Number of threads:", number_of_threads);
    scanf("%d", &number_of_threads);

    printf("Number of iterations:", number_of_iterations);
    scanf("%d", &number_of_iterations);

    printf("Mode: ");
    printf("\n1) Without locking system");
    printf("\n2) With busy waiting");
    printf("\n3) With sched_yield(void)");
    printf("\n4) With pthread_mutex_t\n");
    scanf("%d", &mode);

    int value = 0;
    void* args[3] = {&value, (void *)&number_of_iterations};

    printf("With ");
    switch (mode - 1) {
        case disabled: {
            printf("no blocking system");
            exit_code = create_threads(number_of_threads, number_of_iterations, create_thread, args);
            break;
        }
        case busyWaiting: {
            printf("busy waiting");
            int locked = 0;
            args[2] = &locked;
            exit_code = create_threads(number_of_threads, number_of_iterations, create_thread_busy_waiting, args);
            break;
        }
        case yield: {
            printf("yield");
            int locked = 0;
            args[2] = &locked;
            exit_code = create_threads(number_of_threads, number_of_iterations, create_thread_yield, args);
            break;
        }
        case mutex: {
            printf("mutex");
            pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
            args[2] = &mutex;
            exit_code = create_threads(number_of_threads, number_of_iterations, create_thread_mutex, args);
            break;
        }
    }

    printf(":\n");
    printf("We got: %d\n", value);
    printf("We wanted: %d\n", number_of_iterations * number_of_threads);
    printf("Ratio: %f%%", (float)value / (number_of_iterations * number_of_threads) * 100);

    return exit_code;
}
