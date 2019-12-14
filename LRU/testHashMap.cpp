#include "hashMap.h"

using namespace LRU;

int main()
{ 
   hashMap *map = new hashMap(10);
   map->insert("hello", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("hello", NULL);
//    map->print_map();
//    cout << "About to delete.\n";
//    map->delete_node("goodbye");
//    map->delete_node("hello");
   map->delete_node("Derp");
   map->insert("hello", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("hello", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->insert("goodbye", NULL);
   map->print_map();
} 