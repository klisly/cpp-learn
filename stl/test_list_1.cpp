#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

typedef list<int> LISTINT;
typedef list<char> LISTCHAR;

int main()
{   
    LISTINT listOne;
    LISTINT::iterator i;
    listOne.push_front(2);
    listOne.push_front(1);
    listOne.push_back(3);
    listOne.push_back(4);
    for (i = listOne.begin(); i != listOne.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    LISTINT::reverse_iterator ri;
    cout << "listOne.rbegin()---listOne.rend()" << endl;
    for (ri = listOne.rbegin(); ri != listOne.rend(); ri++)
    {
        cout << *ri << " ";
    }
    cout << endl;
    int result = accumulate(listOne.begin(), listOne.end(), 0);
    cout << "Sum=" << result << endl;
    cout << "-------" << endl;

    //--------------------------
    //用list容器处理字符型数据
    //--------------------------

    //用LISTCHAR创建一个名为listOne的list对象
    LISTCHAR listTwo;
    //声明i为迭代器
    LISTCHAR::iterator j;

    //从前面向listTwo容器中添加数据
    listTwo.push_front('A');
    listTwo.push_front('B');

    //从后面向listTwo容器中添加数据
    listTwo.push_back('x');
    listTwo.push_back('y');

    //从前向后显示listTwo中的数据
    cout << "listTwo.begin()---listTwo.end():" << endl;
    for (j = listTwo.begin(); j != listTwo.end(); ++j)
        cout << char(*j) << " ";
    cout << endl;

    //使用STL的max_element算法求listTwo中的最大元素并显示
    j = max_element(listTwo.begin(), listTwo.end());
    cout << "The maximum element in listTwo is: " << char(*j) << endl;
    
    // advance distance swap
    int a[5] = { 1, 2, 3, 4, 5 };
    cout <<"a data:";
    for(int i = 0; i < 5; i++)
    {
        cout << a[i]<<"\t";
    }
    cout << endl;
    list <int> lst(a, a+5);
    list <int>::iterator p = lst.begin();
    advance(p, 2);  //p向后移动两个元素，指向3
    cout << "1)" << *p << endl;  //输出 1)3
    advance(p, -1);  //p向前移动一个元素，指向2
    cout << "2)" << *p << endl;  //输出 2)2
    list<int>::iterator q = lst.end();
    q--;  //q 指向 5
    cout << "3)" << distance(p, q) << endl;  //输出 3)3
    iter_swap(p, q); //交换 2 和 5
    cout << "4)";
    for (p = lst.begin(); p != lst.end(); ++p)
        cout << *p << " ";
    return 0;
}