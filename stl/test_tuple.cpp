#include <iostream>
#include <tuple>
#include <array>
#include <utility>
#include <string>
using namespace std;
int main()
{
    // pair<int, float> tp;
    // tp.first = 1.0;
    // tp.second = 0.5;
    // cout << "The initial values of pair ar:";
    // cout << tp.first << " " << tp.second << endl;
    
    tuple<int, int, float> tp(1, 2, 3.1);
    cout << "first elem:" << get<0>(tp) << endl;
    cout << "second elem:" << get<1>(tp) << endl;
    cout << "third elem:" << get<2>(tp) << endl;
    return 0;
}