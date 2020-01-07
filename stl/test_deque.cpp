#include <iostream>
#include <deque>

using namespace std;
int main()
{
    deque<int> deq;
    for(int i = 0; i < 10; i++){
        deq.push_back(i);
    }
    cout << deq.size() << endl;
    cout << deq.max_size() << endl;
    deq.resize(0);
    cout << deq.size() << endl;
    if(deq.empty()){
        cout << "element is empty" << endl;
    }
    for(int i = 0; i < 10; i++){
        deq.push_back(i);
    }
    deq.push_back(22);
    deq.push_front(23);
    deq.push_front(21);
    deque<int>::iterator it = deq.begin();
    deq.insert(it,20);

    return 0;
}