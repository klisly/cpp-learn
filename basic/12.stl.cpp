#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    int i;
    cout << "vector size:" << vec.size() << endl;
    for (i = 0; i < 5; i++)
    {
        vec.push_back(rand());
    }
    cout << "extend vector size:" << vec.size() << endl;
    for (i = 0; i < 5; i++)
    {
        cout << "value of vec[" << i << "]=" << vec.at(i) << '\t';
    }
    cout << endl;
    // 使用迭代器访问
    vector<int>::iterator v = vec.begin();
    while (v != vec.end())
    {
        cout << "value of v = " << *v << endl;
        v++;
    }

    cout << "data" << endl;
}