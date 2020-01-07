#include <iostream>
#include <random>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        if (line.size() == 0)
        {
            cout << "exit program" << endl;
            break;
        }
        cout << "out data: " << line << " size:" << line.size() << endl;
    }
    return 0;
}