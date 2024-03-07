#include <stdio.h>
#include <pthread.h>
void *thread_function(void *arg) {
    printf("This is a thread\n");
    pthread_exit(NULL);
}
int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    printf("Main thread\n");
    pthread_join(thread, NULL);
    return 0;
}

