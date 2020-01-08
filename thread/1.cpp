#include <iostream>
#include <pthread.h>

using namespace std;
#define THREAD_NUM 5
void* say_hello(void* args)
{
    cout<<"Hello World"<<endl;
    return 0;
}

int main()
{
    pthread_t tids[THREAD_NUM];
    for(int i = 0; i < THREAD_NUM; i++)
    {
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
    
}