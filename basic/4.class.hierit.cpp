#include <iostream>

using namespace std;
// 基类
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
    void print(int i)
    {
        cout << "整数为: " << i << endl;
    }

    void print(double f)
    {
        cout << "浮点数为: " << f << endl;
    }

    void print(char c[])
    {
        cout << "字符串为: " << c << endl;
    }

protected:
    int width;
    int height;
};

// 派生类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
    Rectangle operator+(const Rectangle &b)
    {
        Rectangle rect;
        rect.width = this->width + b.width;
        rect.height = this->height + b.height;
        return rect;
    }
};
/**
 * 公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，
 * 基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，
 * 但是可以通过调用基类的公有和保护成员来访问。
 * 保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
 * 私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
 **/
int main()
{
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;

    // 输出整数
    Rect.print(5);
    // 输出浮点数
    Rect.print(500.263);
    // 输出字符串
    char c[] = "Hello C++";
    Rect.print(c);
    Rectangle rect3 = Rect + Rect;
    cout << "rect3 Total area: " << rect3.getArea() << endl;
    return 0;
}