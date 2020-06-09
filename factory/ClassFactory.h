#pragma once
#include "Singleton.h"
#include <map>
#include <string>

using namespace std;

class Item;
typedef void *(*ItemObject)();

struct ItemObjectClass
{
    explicit ItemObjectClass(ItemObject item) : itemObject(item) {}
    ItemObject itemObject;
};

class ClassFactory : public Singleton<ClassFactory>
{
public:
    ClassFactory();
    ~ClassFactory();
    void *CreateItem(string className);
    void RegisterItem(const string &className, ItemObject item);

private:
    map<string, ItemObjectClass *> objectItems;
};
