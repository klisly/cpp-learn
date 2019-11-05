#include <iostream>

using namespace std;

struct Box
{
    char title[50];
    double length;
    double breadth;
    double height;
} box;

void printBox(struct Box box, int volume);

int main()
{

    double volume = 0.0;
    // box 1 详述
    box.height = 5.0;
    box.length = 6.0;
    box.breadth = 7.0;
    volume = box.height * box.length * box.breadth;
    cout << "box 的体积：" << volume << endl;
    Box Box2;
    // box 2 详述
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;
    strcpy(Box2.title, "测试");

    // box 2 的体积
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << Box2.title << "Box2 的体积：" << volume << endl;
    printBox(Box2, volume);
    return 0;
}

void printBox(struct Box box, int volume)
{
    cout << box.title << "Box2 的体积：" << volume << endl;
}