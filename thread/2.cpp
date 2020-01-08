#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *)threadid);
    cout << "Hello thread id:" << tid << endl;
    pthread_exit(NULL);
}

int main()
{
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    int rc;
    int i;
    for(i = 0; i < NUM_THREADS; i++)
    {
        cout<<"main():创建线程，"<<i<<endl;
        indexes[i] = i;
        rc = pthread_create(&tids[i], NULL, PrintHello, (void*)&(indexes[i]));
        if(rc)
        {
            cout <<"Error:无法创建线程，"<<rc<<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}
