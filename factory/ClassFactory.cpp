#include "stdafx.h"
#include "ClassFactory.h"
ClassFactory:: : ClassFactory()
{
}

ClassFactory::~ClassFactory()
{
    for (auto it : objectItems)
    {
        if (it.second != nullptr)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
    objectItems.clear();
}

void *ClassFactory::CreateItem(string className)
{
    ItemObject construct = nullptr;
    if (objectItems.find(className) != objectItems.end())
        construct = objectItems.find(className)->second->itemObject;

    if (construct == nullptr)
        return nullptr;

    return (*construct)();
}

void ClassFactory::RegisterItem(const string &className, ItemObject item)
{
    map<string, ItemObjectClass *>::iterator it = objectItems.find(className);
    if (it != objectItems.end())
    {
        objectItems[className]->itemObject = item;
    }
    else
    {
        objectItems.insert(make_pair(className, new ItemObjectClass(item)))
    }
}