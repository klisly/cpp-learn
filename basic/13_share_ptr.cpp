#include <iostream>
#include <memory>
#include <list>
using namespace std;

void useShared_ptr(int *p)
{
    cout << *p << endl;
}

void delPointer(int *p)
{
    delete p;
}

shared_ptr<string> factory(const char *p)
{
    return make_shared<string>(p);
}
void use_factory()
{
    shared_ptr<string> p = factory("hell world");
    cout << *p << endl; //!离开作用域时，p引用的对象被销毁。
}

shared_ptr<string> return_share_ptr()
{
    shared_ptr<string> p = factory("hell world");
    //!返回p时，引用计数进行了递增操作。
    //p离开了作用域，但他指向的内存不会被释放掉。
    cout << *p << endl;
    return p;
}

void copyCase()
{
    list<string> v1({"1", "b", "d"});
    list<string> v2 = v1; // v1、v2各占用一段内存
    v1.push_back("cc");
    cout << "v1"
         << "\t";
    for (auto &p : v1)
    {
        cout << p << "\t";
    }
    cout << endl;
    cout << "v2"
         << "\t";
    for (auto &p : v2)
    {
        cout << p << "\t";
    }
    cout << endl;
}

void shareCase()
{
    shared_ptr<list<string>> v1 = make_shared<list<string>>(3, "bb");
    shared_ptr<list<string>> v2 = v1;
    (*v1).push_back("c2c");
    cout << "v1"
         << "\t";
    for (auto &p : *v1)
    {
        cout << p << "\t";
    }
    cout << endl;
    cout << "v2"<< "\t";
    for (auto &p : *v2)
    {
        cout << p << "\t";
    }
    cout << endl;
}

int main()
{
    shared_ptr<string> p1;
    if (!p1)
    {
        cout << "p1 == NULL" << endl;
    }
    shared_ptr<string> p2(new string);
    if (p2 && p2->empty())
    {
        *p2 = "hello world";
        cout << *p2 << endl;
    }
    // 一般的初始化方式
    shared_ptr<string> pint(new string("normal usage"));
    cout << *pint << endl;
    //推荐的安全的初始化方式
    shared_ptr<string> pint1 = make_shared<string>("safe usage");
    cout << *pint1 << endl;

    shared_ptr<int> pt1 = make_shared<int>(32);
    useShared_ptr(pt1.get());
    // delPointer(p1.get()) // !error
    // 使用make_shared用其参数来构造给定类型的对象；传递的参数必须能够与该类型的某个构造函数相匹配。
    // 通常我们用auto来定义一个对象来保存make_shared的结果，这种方式更为简单
    auto pt2 = make_shared<int>(23);
    useShared_ptr(pt2.get());

    cout << "pt2 指向对象的使用次数：" << pt2.use_count() << endl;
    auto pt3(pt2); // copy ptr
    cout << "pt2\\pt3 指向对象的使用次数：" << pt2.use_count() << "," << pt3.use_count() << endl;

    use_factory();
    auto p = return_share_ptr();
    cout << p.use_count() << endl;
    p.reset(new string("hello world2"));
    cout << *p << endl;

    /**
     * 对于一块内存，shared_ptr类保证只要有任何shared_ptr对象引用它，
     * 他就不会被释放掉。由于这个特性，保证shared_ptr在不用之后不再保留
     * 就非常重要了，通常这个过程能够自动执行而不需要人工干预，有一种例外
     * 就是我们将shared_ptr放在了容器中。所以永远不要忘记
     * erease不用的shared_ptr。
     **/
    list<shared_ptr<string>> pstrList;
    pstrList.push_back(make_shared<string>("1111"));
    pstrList.push_back(make_shared<string>("1112"));
    pstrList.push_back(make_shared<string>("1113"));
    pstrList.push_back(make_shared<string>("1114"));
    for (auto p : pstrList)
    {
        if (*p == "1113")
        {
            cout << "find 1113" << endl;
        }
        cout << *p << endl;
    }
    list<shared_ptr<string>>::iterator iter = pstrList.begin();
    for (; iter != pstrList.end(); iter++)
    {
        if (**iter == "1113")
        {
            cout << **iter << endl;
            pstrList.erase(iter);
        }
    }
    cout << "----- after remove -----" << endl;
    for (auto p : pstrList)
    {
        cout << *p << endl;
    }

    //使用shared_ptr在一个常见的原因是允许多个对象共享相同的状态，而非多个对象独立的拷贝！
    copyCase();
    cout<<"++++++++++++++++"<<endl;
    shareCase();
}