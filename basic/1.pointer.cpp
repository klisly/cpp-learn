#include <iostream>
using namespace std;

double *getAvg(int *arr, int size);
void swap(int &x, int &y);

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
double &setValues(int i)
{
    return vals[i];
}

int main()
{
    // 每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址
    int var1;
    cout << "var address:" << &var1 << endl;
    int var = 20; // 实际变量的声明
    int *ip;      // 指针变量的声明

    ip = &var; // 在指针变量中存储 var 的地址

    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    // 空指针
    // 如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。
    // NULL 指针是一个定义在标准库中的值为零的常量
    int *ptr = NULL;
    int *ptr1;
    if (ptr)
    {
        cout << "ptr值是：" << ptr << endl;
    }
    if (!ptr)
    {
        cout << "ptr1未默认设置空的值是：" << ptr1 << endl;
    }

    // 带有 5 个元素的整型数组
    int data[5] = {1000, 2, 3, 17, 50};
    // 一个指向整数的指针
    double *avg;
    // 传递一个指向数组的指针作为参数
    avg = getAvg(data, 5);
    // 输出返回值
    cout << "平均值是：" << avg[0] << endl;

    // 指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。
    // 通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，
    // 第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
    int var0;
    int *ptr2;
    int **pptr;

    var = 3000;

    // 获取 var 的地址
    ptr2 = &var0;

    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr2;

    // 使用 pptr 获取值
    cout << "var 值为 :" << var0 << endl;
    cout << "*ptr 值为:" << *ptr2 << endl;
    cout << "**pptr 值为:" << **pptr << endl;

    /**
     *  引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。
     *  一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量
     *  不存在空引用。引用必须连接到一块合法的内存。
     *  一旦引用被初始化为一个对象，就不能被指向到另一个对象。
     *  指针可以在任何时候指向到另一个对象。
     *  引用必须在创建时被初始化。指针可以在任何时间被初始化。
     **/
    int i;
    double d;

    // 声明引用变量
    int &r = i;
    double &s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;

    // 局部变量声明
    int a = 100;
    int b = 200;

    cout << "交换前，a 的值：" << a << endl;
    cout << "交换前，b 的值：" << b << endl;

    /* 调用函数来交换值 */
    swap(a, b);

    cout << "交换后，a 的值：" << a << endl;
    cout << "交换后，b 的值：" << b << endl;

    cout << "改变前的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }

    setValues(1) = 20.23; // 改变第 2 个元素
    setValues(3) = 70.8;  // 改变第 4 个元素

    cout << "改变后的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    return 0;
}

double *getAvg(int *arr, int size)
{
    int i, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double avg = double(sum) / size;
    static double a[1];
    a[0] = avg;
    return a;
}

void swap(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    return;
}