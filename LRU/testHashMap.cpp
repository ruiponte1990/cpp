#include "hashMap.h"

using namespace LRU;

int main()
{ 
   hashMap *map = new hashMap(20);
   map->insert("one", NULL);
   map->insert("two", NULL);
   map->insert("three", NULL);
   map->insert("four", NULL);
   map->insert("five", NULL);
   map->print_map();
   map->delete_node("four");
   map->delete_node("five");
   map->delete_node("Derp");
   map->insert("six", NULL);
   map->insert("seven", NULL);
   map->insert("eight", NULL);
   map->insert("nine", NULL);
   map->insert("ten", NULL);
   map->insert("eleven", NULL);
   map->insert("twelve", NULL);
   map->insert("thirteen", NULL);
   map->insert("fourteen", NULL);
   map->insert("fifteen", NULL);
   map->insert("sixteen", NULL);
   map->insert("seventeen", NULL);
   map->insert("eighteen", NULL);
   map->insert("nineteen", NULL);
   map->insert("twenty", NULL);
   map->insert("random stash", NULL);
   map->insert("twenty truck", NULL);
   map->print_map();
} 