#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
    int thread_id;
    string message;
};

void *PrintHello(void *threadargs)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    thread_data *data;
    data = (thread_data *)threadargs;
    cout << "thread id:" << data->thread_id << endl;
    cout << "thread message:" << data->message << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t tids[NUM_THREADS];
    thread_data indexes[NUM_THREADS];
    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "main():创建线程，" << i << endl;
        indexes[i].thread_id = i;
        string msg = "This is message";
        msg.append(" ").append(std::to_string(i));
        indexes[i].message = msg;
        rc = pthread_create(&tids[i], NULL, PrintHello, (void *)&(indexes[i]));
        if (rc)
        {
            cout << "Error:无法创建线程，" << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
