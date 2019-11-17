#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;
int Hashtable::hashfunc(string s)
{
    int i, sum = 0;
    for (i = 0; i < s.size(); i++)
    {
        sum = sum + s[i];
    }
    int result;
    result = (sum - 1) % 20;
    return result;
}

string Hashtable::HashFunc(string value)
{
    string x;
    char CCH[] = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    char str[6];
    char ss[21];
    int i = 0;
    static int count = 0;
    count++;
    srand((char)(sizeof(value.c_str()) + count));
    for (i = 0; i < 15; i++)
    {
        ss[i] = (char)(rand() % 27 + 'a');
    }
    ss[i] = '\0';
    srand((char)(time((time_t *)NULL)));
    for (i = 0; i < 5; i++)
    {
        int y = rand() / (RAND_MAX / (sizeof(CCH) - 1 + count));
        str[i] = CCH[y];
    }
    str[i] = '\0';
    printf("str= %s\n", str);
    strcat(ss, str);
    x = ss;
    return ss;
}

void Hashtable::add_hash_(string key, string s)
{
    std::pair<string, TStrStrPair> Temp;
    string hashIndex_;
    hashIndex_ = HashFunc(s);
    Temp.first = hashIndex_;
    Temp.second.first = key;
    Temp.second.second = s;
    Table.push_back(Temp);
}

string Hashtable::search_(string value)
{
    string hashIndex;
    for (int x = 0; x < Table.size(); x++)
    {
        if (Table.at(x).second.second == value)
        {
            hashIndex = Table.at(x).first;
            cout << "Match " << value << " in the list" << endl;
            return hashIndex;
        }
        if (x == Table.size())
        {
            cout << "Not match " << value << " in th list" << endl;
        }
    }
    return hashIndex;
}

void Hashtable::print_hash(string hasIndex)
{
    if (hasIndex.size() == 0)
    {
        cout << "Not found in the list" << endl;
        return;
    }
    cout << "Hash num:" << hasIndex << endl;
    for (int i = 0; i < Table.size(); i++)
    {
        if (Table.at(i).first == hasIndex)
        {
            cout << "Key = " << Table.at(i).second.first << endl;
            cout << "Value = " << Table.at(i).second.second << endl;
        }
    }
}

bool Hashtable::delete_hash(string value)
{
    for (int x = 0; x < Table.size(); x++)
    {
        if (Table.at(x).second.second == value)
        {
            Table.erase(Table.begin() + x);
            return true;
        }
    }
    return false;
}

void Hashtable::list_hash()
{
    if (Table.empty())
    {
        cout << "There is no element in the list" << endl;
        return;
    }
    for (int x = 0; x < Table.size(); x++)
    {
        cout << "Hash Num: " << Table.at(x).first << endl;
        cout << "Key: " << Table.at(x).second.first << endl;
        cout << "Value: " << Table.at(x).second.second << endl;
    }
}