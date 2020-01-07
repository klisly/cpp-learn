#include <iostream>
#include <vector>
#include <istream>
using namespace std;

size_t count_calls()
{
    static size_t ctr = 0;
    ++ctr;
    return ctr * ctr;
}
int main()
{
    vector<int> vec;
    int i;
    cout << "vector size=" << vec.size() << endl;
    for (i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    cout << "extend vector size=" << vec.size() << endl;
    for (i = 0; i < 10; i++)
    {
        cout << "value of vec[" << i << "]=" << vec[i] << endl;
    }

    vector<int>::iterator v = vec.begin();
    while (v != vec.end())
    {
        cout << "value of v = " << *v << endl;
        v++;
    }
    for (int i = 0; i < 100; ++i)
    {
        cout << "iter " << count_calls() << endl;
    }
    return 0;
}