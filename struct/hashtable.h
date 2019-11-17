#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Hashtable
{
    protected:
        typedef pair<int, string> TIntStrParir;
        typedef pair<int, TIntStrParir> TIIntStrPair;
        typedef pair<string, string> TStrStrPair;
        typedef pair<string, TStrStrPair> TSStrStrPair;
    private:
        vector<TSStrStrPair> Table;
    public:
        int hashfunc(string s);
        string HashFunc(string value);
        void add_hash_(string, string);
        string search_(string value);
        void list_hash();
        void print_hash(string hashIndex);
        bool delete_hash(string value);
};