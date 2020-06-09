#pragma once

template <class T>
class Singleton
{
public:
    using object_type = T;
    struct object_creator
    {
        object_creator()
        {
            Singleton<T>::instance();
        }
    };
    static object_creator creator_object;
    static object_type *instance()
    {
        static object_type _instance;
        return &_instance;
    }
};
template <typename T>
typename Singleton<T>::object_creator Singleton<T>::creator_object;