#include "cache.h"

using namespace LRU;

int main()
{ 
    LRU::cache *lru = new cache(4); 
    lru->put("key1", "val1");
    lru->print_cache();
    lru->put("key2", "val2");
    lru->print_cache();
    lru->put("key3", "val3");
    lru->print_cache();
    lru->put("key4", "val4");
    lru->print_cache();
    lru->put("key5", "val5");
    lru->print_cache();
    lru->put("key4", "different val4");
    lru->print_cache();
} 