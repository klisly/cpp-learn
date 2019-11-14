/**
 * 一般情况下，两种类型的多任务处理：基于进程和基于线程。
 * 基于进程的多任务处理是程序的并发执行。
 * 基于线程的多任务处理是同一程序的片段的并发执行。
 **/
#include <iostream>
// 必须的头文件
#include <thread>
using namespace std;
std::thread::id main_thread_id = std::this_thread::get_id();

void hello()
{
    cout << "Hello Concurrent World" << endl;
    if (main_thread_id == std::this_thread::get_id())
    {
        cout << "This is the main thread." << endl;
    }
    else
    {
        cout << "This is not the main thread." << endl;
    }
}

void pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout << "pause of " << n << " seconds ends thread id:" << this_thread::get_id() << endl;
}
int main()
{
    thread t(hello);
    // (不准确)
    cout << "concurrency num:" << t.hardware_concurrency() << endl;
    //可以并发执行多少个(不准确)
    cout << "native_handle " << t.native_handle() << endl;
    t.join();
    thread a(hello);
    a.detach();
    thread threads[5];
    cout << "spawning 5 threads..." << endl;
    for (int i = 0; i < 5; i++)
    {
        threads[i] = thread(pause_thread, i + 1);
        cout << "Done spawning thread. Now waiting for them to join:" << endl;
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
    cout << "All threads joined" << endl;
}