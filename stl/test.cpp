#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
int main()
{
    vector<char>a(10), b(10);
	cout << a.empty() << ","<< sizeof(a) << "\n";
	for (char i = 'a', j = 0; j < 10; j++)
		a[j] = i + j;
	cout << a.max_size() << "," << a.capacity() << "," << a.size() << endl;
	a.push_back('k');
	cout << a.max_size() << "," << a.capacity() << "," << a.size() << endl;
	a.pop_back(); a.pop_back(); a.pop_back(); a.pop_back(); a.pop_back(); a.pop_back();
	cout << a.max_size() << "," << a.capacity() << "," << a.size() << endl;
}