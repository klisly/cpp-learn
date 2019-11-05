#include <iostream>

using namespace std;

class Box
{
    // 类成员可以被定义为 public、private 或 protected。默认情况下是定义为 private。
public:
    double length;
    double breadth;
    double height;
    double getVolume(void)
    {
        return length * height * breadth;
    }
    // 先声明方法， 类的外部使用范围解析运算符 :: 定义该函数
    double getVolume2(void);

    // 类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
    // 构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。
    Box();
    Box(double h, double b, double l);
    /**
     * 类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
     * 析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，
     * 也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
     **/
    ~Box();
};

Box::~Box(void)
{
    cout << "Box is being delete" << endl;
}
Box::Box(void)
{
    cout << "Box is being created" << endl;
}

// 使用初始化列表来初始化字段
Box::Box(double h, double b, double l) : length(l), breadth(b), height(h)
{
    cout << "Box is being created with init memeber " << endl;
}
double Box::getVolume2(void)
{
    return length * height * breadth;
}

class Line
{
public:
    int getLength(void);
    Line(int len);         // 简单的构造函数
    /**
     * 拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：
     * 通过使用另一个同类型的对象来初始化新创建的对象。
     * 复制对象把它作为参数传递给函数。复制对象，并从函数返回这个对象。
     * 在类中没有定义拷贝构造函数，编译器会自行定义一个。
     * 如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。
     **/
    Line(const Line &obj); // 拷贝构造函数
    ~Line();               // 析构函数

private:
    int *ptr;
};

int main()
{
    Box Box1;
    Box Box2;
    double volume = 0.0;
    // box 1 详述
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    // box 2 详述
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    // box 1 的体积
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Box1 的体积：" << volume << endl;

    // box 2 的体积
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Box2 的体积：" << volume << endl;

    // box 2 的体积
    cout << "Box2 的体积：" << Box1.getVolume() << endl;
    // box 2 的体积
    cout << "Box2 的体积：" << Box1.getVolume2() << endl;

    Box Box3(1, 2, 3);
    cout << "Box3 的体积：" << Box3.getVolume2() << endl;
    return 0;
}