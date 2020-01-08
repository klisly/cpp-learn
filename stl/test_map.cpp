#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class my_cmp
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

//打印函数 printfB
void printfB(multimap<string, int> vec_)
{
	for (multimap<string, int>::iterator it = vec_.begin(); it != vec_.end(); it++)
	{
		std::cout << it->first  << "  " << it->second << std::endl;
	}
	cout << "容积 = " << vec_.size() << endl;
}

using namespace std;
int main()
{
    map<int, int> c;
    c[1] = 10;
    c[2] = 20;
    c[3] = 30;
    c[4] = 40;
    c[5] = 50;
    for (auto i : c)
    {
        cout << "[" << i.first << "]=" << i.second << "\t";
    }
    cout << endl;
    map<int, int> c1;
    c1 = c;
    for (auto i : c1)
    {
        cout << "[" << i.first << "]=" << i.second << "\t";
    }
    cout << endl;

    map<int, int>::const_iterator ci;
    ci = c1.begin();
    cout << "begin():"
         << "[" << (*ci).first << "]" << (*ci).second << endl;

    // 自定义比较器
    map<int, int> c2;
    c2.insert({pair<int, int>(1, 10), pair<int, int>(2, 20),
              pair<int, int>(3, 30), pair<int, int>(4, 40), pair<int, int>(5, 50),
              pair<int, int>(6, 60)});

    for(auto i : c2)
    {
        cout<<"["<< i.first <<"] = " << i.second <<"  ";
    }
    cout << endl;

    multimap<string, int> vecE;
    vecE.insert(make_pair((string)"china", 1));
    vecE.insert(make_pair((string)"china", 1));//允许插入
    vecE.insert(make_pair((string)"china", 3));//允许插入
    vecE.insert(make_pair((string)"china", 4));//允许插入
    vecE.insert(make_pair((string)"china", 5));//允许插入
    vecE.insert(make_pair((string)"english", 1));
    vecE.insert(make_pair((string)"english", 2));//允许插入
    vecE.insert(make_pair((string)"america", 1));
    vecE.insert(make_pair((string)"america", 2));//允许插入
    vecE.insert(make_pair((string)"america", 3));//允许插入
    cout << "multimap 初始化" << endl;
    cout << "vecE所有元素"<<endl;
    printfB(vecE);
    return 0;
}