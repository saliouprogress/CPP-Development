#include <iostream>
#include <pthread.h>


class Counter {
private:
    int count;
public:
    Counter() : count(0) {}
    void increment() {
        count += 1;
    }
    int getCount() {
        return count;
    }
};
Counter count;
struct ThreadArgs
{
    int threadID;
    int limit;
};

pthread_mutex_t mutex;

void* myFunction(void* arg) {
    pthread_mutex_lock(&mutex);
    ThreadArgs * args = static_cast<ThreadArgs*>(arg);
    int threadID = args->threadID;
    // Add your code here
    for (int i = 0; i < args->limit; i++) {
        count.increment();
    }
    std::cout << "Thread " << threadID << " count: " << count.getCount() << std::endl;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}



int main() {
    ThreadArgs arg1, arg2, arg3;
    int threadID1 = 1, threadID2 = 2, threadID3 = 3;
    arg1 = {threadID1, 200000};
    arg2 = {threadID2, 400000};
    arg3 = {threadID3, 500000};
    pthread_t t1, t2, t3;
    pthread_mutex_init(&mutex, NULL);
    // Create threads
    pthread_create(&t1, NULL, myFunction, (void*)&arg1);
    pthread_create(&t2, NULL, myFunction, (void*)&arg2);
    pthread_create(&t3, NULL, myFunction, (void*)&arg3);
    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_mutex_destroy(&mutex);

    std::cout << count.getCount() << std::endl;

    return 0;
}
