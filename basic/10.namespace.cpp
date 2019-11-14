/**
 * 引入了命名空间这个概念，专门用于解决上面的问题，
 * 它可作为附加信息来区分不同库中相同名称的函数、类、变量等。
 * 使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。
 **/
#include <iostream>
using namespace std;
namespace first_space
{
void func()
{
    cout << "Inside first space" << endl;
}
} // namespace first_space

namespace second_space
{
void func()
{
    cout << "Inside second space" << endl;
}
} // namespace second_space
using namespace second_space;
int main()
{
    func();
    return 0;
}