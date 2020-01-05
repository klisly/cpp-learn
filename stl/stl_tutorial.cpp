#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <functional>
#include <numeric>

using namespace std;
#define SIZE 100
int iarray[SIZE];
void Display(vector<double> &v, const char *s);

#define VSIZE 24
vector<long> v(VSIZE);
void initialize(long &ri);
void show(const long &ri);
bool isMinus(const long &ri);
#define MAX 10
vector<long> iv(MAX);

unsigned int RandInt(const unsigned int n);
int main()
{
    srandom(time(NULL));

    // accumulate
    for (int i = 0; i < MAX; i++)
    {
        iv[i] = i + 1;
    }
    long sum = accumulate(iv.begin(), iv.end(), 0);
    cout << "Sum of values==" << sum << endl;
    
    long product = accumulate(iv.begin(), iv.end(), 1, multiplies<long>());

    for_each(v.begin(), v.end(), initialize);
    cout << "Vector of signed long integers" << endl;
    for_each(v.begin(), v.end(), show);
    cout << endl;
    int count = 0;
    vector<long>::iterator p;
    p = find_if(v.begin(), v.end(), isMinus);
    while (p != v.end())
    {
        count++;
        p = find_if(p + 1, v.end(), isMinus);
    }

    cout << "Number of values:" << VSIZE << endl;
    cout << "Negative values:" << count << endl;

    iarray[20] = 50;
    int *ip = find(iarray, iarray + SIZE, 50);
    if (ip == iarray + SIZE)
    {
        cout << "50 not found in array" << endl;
    }
    else
    {
        cout << *ip << " found in array" << endl;
    }
    bool a = true;
    cout << "a is " << a << endl;
    const volatile int c = 10;
    cout << "c is " << c << endl;

    vector<int> vec(200);
    vec[10] = 50;
    vec[30] = 50;
    vector<int>::iterator iter = find(vec.begin(), vec.end(), 30);
    if (iter != vec.end())
    {
        cout << "Vec contains value" << *iter << endl;
    }
    else
    {
        cout << "Vec does not contain 30" << endl;
    }
    while (iter != vec.end())
    {
        cout << "Vec contains value" << *iter << endl;
        iter++;
    }

    double darray[10] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
    vector<double> vdouble(10);
    vector<double>::iterator diter = vdouble.begin();
    copy(darray, darray + 5, diter);
    int size = 0;
    while (diter != vdouble.end() && size < 5)
    {
        cout << "vec iter:" << *diter << endl;
        diter += 1;
    }

    for (int i = 0; i < 10; i++)
    {
        vdouble.push_back(random() * 1.0 / 100.0);
    }

    // Display, sort, and redisplay
    Display(vdouble, "Before sorting");
    sort(vdouble.begin(), vdouble.end());
    Display(vdouble, "After sorting");
    // pointer_to_unary_function<unsigned int, unsigned int>
    // ptr_RandInt = ptr_fun(RandInt);  // Pointer to RandInt()//注意这行
    // random_shuffle(v.begin(), v.end(), ptr_RandInt);
    return 0;
}

unsigned int RandInt(const unsigned int n)
{
    return random() % n;
}

void initialize(long &ri)
{
    ri = (random() - (RAND_MAX / 2));
}

void show(const long &ri)
{
    cout << ri << " ";
}

// return true if ri is less than 0
bool isMinus(const long &ri)
{
    return (ri < 0);
}

void Display(vector<double> &v, const char *s)
{
    cout << endl
         << s << endl;
    copy(v.begin(), v.end(),
         ostream_iterator<int>(cout, "\t"));
    cout << endl;
}