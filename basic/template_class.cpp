#include <iostream>
using namespace std;
template <class T1, class T2>
class Point
{
public:
    Point(T1 x, T2 y) : m_x(x), m_y(y) {}

public:
    T1 getX() const;
    void setX(T1 x);
    T2 getY() const;
    void setY(T2 y);

private:
    T1 m_x;
    T2 m_y;
};

template <class T1, class T2>  //模板头
T1 Point<T1, T2>::getX() const /*函数头*/
{
    return m_x;
}
template <class T1, class T2>
void Point<T1, T2>::setX(T1 x)
{
    m_x = x;
}
template <class T1, class T2>
T2 Point<T1, T2>::getY() const
{
    return m_y;
}
template <class T1, class T2>
void Point<T1, T2>::setY(T2 y)
{
    m_y = y;
}
int main()
{
    Point<int, int> p1(10, 20);
    cout << "x=" << p1.getX() << ", y=" << p1.getY() << endl;
    Point<int, string> p2(10, "东经180度");
    cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;
    Point<string, string> *p3 = new Point<string, string>("东经180度", "北纬210度");
    cout << "x=" << p3->getX() << ", y=" << p3->getY() << endl;
    return 0;
}