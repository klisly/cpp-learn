#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <set>

using namespace std;
template <class Tkey>
class InvIndex : public map<Tkey, list<int> >
{
public:
    vector<vector<Tkey> > docs; // 正排文章
    void add(const vector<Tkey> &doc)
    {
        docs.push_back(doc);
        int idx = docs.size();
        for (int w = 0; w < doc.size(); w++)
        {
            auto it = this->find(doc[w]);
            if (it == this->end())
            {
                // 没有发现倒排索引，新建
                list<int> newList;
                (*this)[doc[w]] = newList;
                it = this->find(doc[w]);
            }
            it->second.push_back(idx);
        }
    }

    void retrive(vector<Tkey> &query, set<int> &docIdx)
    {
        int termNum = query.size();
        docIdx.clear();
        for (int t = 0; t < termNum; t++)
        {

            //该term倒排链不存在则跳过
            if (this->find(query[t]) != this->end())
            {
                auto it = this->find(query[t]);
                docIdx.insert(it->second.begin(), it->second.end());
            }
        }
    }
};

int main()
{
    string D1_tmp[] = {"谷歌", "地图", "之父", "跳槽", "Facebook"};
    int D1_tmp_size = sizeof(D1_tmp) / sizeof(string);
    vector<string> D1(D1_tmp, D1_tmp + D1_tmp_size);

    string D2_tmp[] = {"谷歌", "地图", "之父", "加盟", "Facebook"};
    int D2_tmp_size = sizeof(D2_tmp) / sizeof(string);
    vector<string> D2(D2_tmp, D2_tmp + D2_tmp_size);

    string D3_tmp[] = {"谷歌", "地图", "创始人", "拉斯", "离开", "谷歌", "加盟", "Facebook"};
    int D3_tmp_size = sizeof(D3_tmp) / sizeof(string);
    vector<string> D3(D3_tmp, D3_tmp + D3_tmp_size);

    string D4_tmp[] = {"谷歌", "地图", "创始人", "跳槽", "Facebook", "与", "Wave", "项目", "取消", "有关"};
    int D4_tmp_size = sizeof(D4_tmp) / sizeof(string);
    vector<string> D4(D4_tmp, D4_tmp + D4_tmp_size);

    string D5_tmp[] = {"谷歌", "地图", "创始人", "拉斯", "加盟", "社交", "网站", "Facebook"};
    int D5_tmp_size = sizeof(D5_tmp) / sizeof(string);
    vector<string> D5(D5_tmp, D5_tmp + D5_tmp_size);

    InvIndex<string> *inverted_index = new InvIndex<string>;
    inverted_index->add(D1);
    inverted_index->add(D2);
    inverted_index->add(D3);
    inverted_index->add(D4);
    inverted_index->add(D5);

    string str_query[] = {"谷歌", "地图", "之父", "跳槽", "Facebook", "创始人", "加盟", "拉斯", "离开", "与", "Wave", "项目", "取消", "有关", "社交", "网站"};
    for (int i = 0; i < sizeof(str_query) / sizeof(string); i++)
    {
        vector<string> query;
        query.push_back(str_query[i]);

        cout << str_query[i] << " ";

        set<int> docSet;

        inverted_index->retrive(query, docSet);

        set<int>::iterator it;
        for (it = docSet.begin(); it != docSet.end(); it++)
        {
            cout << "D" << *it << " ";
        }
        cout << endl;
    }

    return 0;
}