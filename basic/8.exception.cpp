#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition";
    }
    return a / b;
}

struct MyException : public exception
{
    const char *what() const throw()
    {
        return "C++ Exception";
    }
};

int main()
{
    int x = 500;
    int y = 0;
    double z = 0;
    try
    {
        z = division(x, y);
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    try
    {
        throw MyException();
    }
    catch (MyException e)
    {
        cout << "MyException caught\n"
             << e.what() << endl;
    }
    catch (std::exception &e)
    {
        // other exception;
    }
    return 0;
}