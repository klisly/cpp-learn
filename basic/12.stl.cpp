#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <time.h>

using namespace std;

template<class T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    vector<int> vec;
    int i;
    cout << "vector size:" << vec.size() << endl;
    for (i = 0; i < 5; i++)
    {
        vec.push_back(rand() % 100);
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
    vector<int>::const_reverse_iterator cri = vec.crbegin();
    while (cri != vec.crend())
    {
        cout << "value of cri = " << *cri << endl;
        cri++;
    }

    cout << "data" << endl;
    string a("123");

    array<int, 10> ars = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (int i = 0; i < ars.size(); i++)
    {
        cout << "ars ele:" << ars.at(i) * ars.at(i)  << "\t";
    }
    cout << endl;


    array<int, 10>::iterator ai = ars.begin();
    while (ai != ars.end())
    {
        cout << "ars iter:" << *ai  << "\t";
        ai++;
    }
    
    int ii = 5, j = 6, k;
    double f = 2.0, g = 0.8, h;
    k = sum<int>(ii, j);
    h = sum<double>(f, g);
    cout << k << "\t"<<h<<endl;
    return 0;
}