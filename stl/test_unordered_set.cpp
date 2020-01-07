#include <iostream>
#include <unordered_set>

using namespace std;

namespace moguifeng
{
void coutUnorderedSet(unordered_set<int> &m, string funcName)
{
    unordered_set<int>::iterator it;
    cout << funcName << ":";
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void initUnorderSet(unordered_set<int> &m)
{
    for (int i = 0; i < 10; i++)
    {
        m.insert(i);
    }
}
string turnBoolToString(bool tmp)
{
    return tmp ? "true" : "false";
}
void basicOperationUnorderedSet()
{
    unordered_set<int> c;
    // 普通插入,返回pair<迭代器,插入是否成功>
    pair<unordered_set<int>::iterator, bool> c_insert = c.insert(1);
    cout << "c_insert1指向key的迭代器:" << *c_insert.first << " 插入是否成功" << turnBoolToString(c_insert.second) << endl;
    pair<unordered_set<int>::iterator, bool> c_inser2 = c.insert(2);
    cout << "c_insert2指向key的迭代器:" << *c_inser2.first << " 插入是否成功" << turnBoolToString(c_inser2.second) << endl;
    pair<unordered_set<int>::iterator, bool> c_inser3 = c.insert(1);
    cout << "c_insert3指向key的迭代器:" << *c_inser2.first << " 插入是否成功" << turnBoolToString(c_inser2.second) << endl;

    // 指定区域接入
    unordered_set<int> c_inset_region;
    c_inset_region.insert(c.begin(), c.end());
    coutUnorderedSet(c_inset_region, "按照指定区域插入");

    // 构造插入
    unordered_set<int> c_emplace;
    c_emplace.emplace(1);
    c_emplace.emplace(2);
    c_emplace.emplace(3);

    // 迭代器插入
    unordered_set<int> c_emplace_hint;
    c_emplace_hint.emplace_hint(c_emplace_hint.begin(), 1);
    c_emplace_hint.emplace_hint(c_emplace_hint.begin(), 2);
    c_emplace_hint.emplace_hint(c_emplace_hint.begin(), 3);
    coutUnorderedSet(c_emplace_hint, "迭代器插入");

    // 删除
    unordered_set<int> c_erase;
    initUnorderSet(c_erase);
    coutUnorderedSet(c_erase, "初始化c_erase");
    // 指定位置删除
    c_erase.erase(c_erase.begin());
    coutUnorderedSet(c_erase, "指定位置删除");

    c_erase.erase(8);
    coutUnorderedSet(c_erase, "指定key删除");

    c_erase.erase(c_erase.begin(), c_erase.end());
    coutUnorderedSet(c_erase, "指定区域删除");

    c.swap(c_emplace);
    coutUnorderedSet(c, "交换");
}

void unorderSetElementLookup()
{
    unordered_set<int> c_find;
    initUnorderSet(c_find);
    unordered_set<int>::iterator find_iter = c_find.find(10);
    if (find_iter != c_find.end())
    {
        cout << "找到元素：" << *find_iter << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    cout << "value 出现次数：" << c_find.count(1) << endl; // set key 不重复
    pair<unordered_set<int>::iterator, unordered_set<int>::iterator> tmp = c_find.equal_range(5);
    if (tmp.first != c_find.end() && tmp.second != c_find.end())
    {
        cout << "该值所在区间为[" << *tmp.first << "," << *tmp.second << "]" << endl;
    }
}
void unorderSetBuckets()
{
    unordered_set<int> c_buckets;
    initUnorderSet(c_buckets);
    cout << "篮子个数：" << c_buckets.bucket_count() << endl;
    cout << "篮子大小：" << c_buckets.bucket_size(1) << endl;
    cout << "最大篮子个数：" << c_buckets.max_bucket_count() << endl;
    cout << "该值所在篮子序号：" << c_buckets.bucket(3) << endl;
}
void unorderSetHashPolicy()
{
    unordered_set<int> c;
    cout << "负载：" << c.load_factor() << endl;
    initUnorderSet(c);
    cout << "负载：" << c.load_factor() << " 最大负载：" << c.max_load_factor() << endl;
    c.reserve(100); // 预设篮子数目，但是没有设定
    c.rehash(3);
    cout << "负载：" << c.load_factor() << " 最大负载：" << c.max_load_factor() << endl;
}
void unorderSetObservers()
{
    unordered_set<int> c;
    initUnorderSet(c);
    unordered_set<int>::hasher hser = c.hash_function();
    unordered_set<int>::key_equal ke = c.key_eq();
    cout << "hash_func:" << hser(1111) << endl;
    cout << "key_eq:" << turnBoolToString(ke(1111, 1111)) << endl;
}
} // namespace moguifeng

int main()
{
    moguifeng::basicOperationUnorderedSet();
    moguifeng::unorderSetElementLookup();
    moguifeng::unorderSetBuckets();
    moguifeng::unorderSetHashPolicy();
    moguifeng::unorderSetObservers();
}