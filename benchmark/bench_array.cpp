#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;
int main()
{
    multimap<string, string> authors;
    authors.insert(pair<string, string>("2", "2"));
    authors.insert(pair<string, string>("2", "3"));
    multimap<string, string>::iterator data = authors.find("2");
    while (data != authors.end())
    {
        cout << data->first << "'s data is " << data->second << endl;
        data++;
    }
    auto ptr = authors.equal_range("2");
    if (ptr.first != end(authors))
    {
        cout << "find data"<< endl;
    }
}