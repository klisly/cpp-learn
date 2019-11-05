#include <iostream>
#include <random>
#include <iomanip>

using namespace std;
using std::default_random_engine;
using std::setw;
int g = 20;

double * getAvg(int arr[], int size);

int main()
{ /**
        int	0
        char	'\0'
        float	0
        double	0
        pointer	NULL
    **/
    int a, b;
    int c;
    a = 10;
    b = 20;
    c = a + b;
    cout << "局部变量" << c << endl;
    cout << "全局变量" << g << endl;

    // 字符串
    // char greeting[6] = {'H', 'E', 'L', 'L', 'O'};
    // 支持如下协作
    char greeting[] = "Hello";
    cout << "greeting " << greeting << endl;

    string a_str = "1.2";
    string b_str = "1.2";
    cout << "is a equals b:" << a_str.compare(b_str) << endl;
    cout << "a_str len:" << strlen(greeting) << endl;
    cout << "greeting len:" << strlen(greeting) << endl;
    cout << "a_str len:" << a_str.length() << endl;

    // 数组
    int n[10];
    default_random_engine e;
    for (int i = 0; i < 10; i++)
    {
        n[i] = e();
    }
    cout << "Element" << setw(12) << "Value" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << setw(7) << i << setw(12) << n[i] << endl;
    }
    // 多维数组
    int a_mul[3][4] = {
        {0, 1, 2, 3},  /*  初始化索引号为 0 的行 */
        {4, 5, 6, 7},  /*  初始化索引号为 1 的行 */
        {8, 9, 10, 11} /*  初始化索引号为 2 的行 */
    };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "a[" << i << "][" << j << "]=" << a_mul[i][j] << endl;
        }
    }

    // 执行数组的指针
    // balance 是一个指向 &balance[0] 的指针，即数组 balance 的第一个元素的地址
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;

    p = balance;

    // 输出数组中每个元素的值
    cout << "使用指针的数组值 " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }

    // 带有 5 个元素的整型数组
    int data[5] = {1000, 2, 3, 17, 50};
    // 一个指向整数的指针
    double* avg;
    // 传递一个指向数组的指针作为参数
    avg = getAvg(data, 5);
    // 输出返回值
    cout << "平均值是：" << avg[0] << endl;
    
    return 0;
}

// C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
double * getAvg(int arr[], int size)
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