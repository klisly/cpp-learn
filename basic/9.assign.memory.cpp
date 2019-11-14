#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

int main()
{
    /**
     *栈：在函数内部声明的所有变量都将占用栈内存。
     *堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。 
     *使用特殊的运算符为给定类型的变量在运行时分配堆内的内存，这会返回所分配的空间地址。这种运算符即 new 运算符。
     *如果您不再需要动态分配的内存空间，可以使用 delete 运算符，删除之前由 new 运算符分配的内存。 
     **/
    double *pvalue = NULL;
    if (!(pvalue = new double))
    {
        cout << "Eror:out of memory" << endl;
        exit(1);
    }
    *pvalue = 124.59;
    cout << "pvalue:" << *pvalue << endl;
    int **p;
    int i, j;
    p = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        p[i] = new int[8];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            p[i][j] = j * i;
        }
    }

    // 打印数据
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 0)
            {
                cout << endl;
            }
            cout << p[i][j] << "\t";
        }
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}