#include <iostream>
using namespace std;
 
//测试如果引用进入函数后进行修改，跳出函数后变量是否修改；
void ChangeRef(int& ref){
    ref++;
    cout << "引用内修改后的值为:" << ref << endl;
}
 
//测试以传值方式进入函数进行修改，跳出函数后变量是否修改
void ChangeNotRef(int ref){
    ref++;
    cout << "通过传值方式在函数内修改后的值为:" << ref << endl;
}
 
//测试以指针为参数传入函数，修改指针指向，是否影响外部指针指向
void ChangePtr(int* ptr){
    ptr++;
    cout << "函数内修改后的指针指向：" << ptr << endl;
}
 
//测试在函数中修改指针指向的内容，是否影响外部指针指向内容
void ChangePtrVal(int* ptr){
    (*ptr)++;
    cout << "函数内修改后指针指向的值：" << *ptr << endl;
}
 
int main(){
    int Ref = 0;
    cout << "传入引用之前的值为:" << Ref << endl;
    ChangeRef(Ref);
    cout << "在函数内修改引用后，跳出函数的值为:" << Ref << endl<<endl;
    
    ChangeNotRef(Ref);
    cout << "通过传值方式在函数内修改后，跳出函数的值为:" << Ref << endl<<endl;
    
    int* ptr = &Ref;
    cout << "传入函数前的指针指向：" << ptr << endl;
    ChangePtr(ptr);
    cout << "传值方式传入函数跳出后的指针指向：" << ptr << endl<<endl;
    
    cout << "传入前指针指向的值为：" << *ptr << endl;
    ChangePtrVal(ptr);
    cout << "从函数中出来后指针指向的值为：" << *ptr << endl<<endl;
 
}
 