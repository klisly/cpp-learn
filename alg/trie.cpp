#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int max_node = 1000000 + 10;
const int charset = 26;
int trie[max_node][charset] = {0};
int color[max_node] = {0};

int k = 1;
void insert(char *w)
{
    int len = strlen(w);
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int c = w[i] - 'a';
        if (!trie[p][c])
        {
            trie[p][c] = k;
            k++;
        }
        p = trie[p][c];
    }
    color[p] = 1;
}
int search(char *w)
{
    int len = strlen(w);
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        int c = w[i] - 'a';
        if (!trie[p][c])
            return 0;
        p = trie[p][c];
    }
    return color[p] == 1;
}
int main()
{
    int t, q;
    char s[20];
    scanf("%d%d", &t, &q);
    while (t--)
    {   
        printf("insert word to trie\n");
        scanf("%s", s);
        if (search(s))
        {
            printf("alread in trie \n");
        }
        else
        {
            insert(s);
        }
    }
}