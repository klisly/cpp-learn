#include <iostream>
#include "../struct/hashtable.h"
int main()
{
    string hashIndex;
    Hashtable ht;
    ht.add_hash_("1", "Tom");
    ht.add_hash_("2", "Mary");
    ht.add_hash_("3", "Jimes");
    ht.add_hash_("4", "Fantex");
    ht.add_hash_("5", "Beyond");
    ht.list_hash();
    hashIndex = ht.search_("Fantex");
    ht.print_hash(hashIndex);
    cout << "delete element " << endl;
    ht.delete_hash("Jimes");
    ht.list_hash();
    return 0;
}