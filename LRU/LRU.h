#include <string> 
#include "hashMap.h"
#include "List.h"

using namespace std;

namespace LRU
{
    class LRU {
        public:
            int size;
            int capacity;
            hashMap *map;
            List *list;
            LRU(int capacity) {
                this->size = 0;
                this->capacity = capacity;
                this->map = new hashMap(capacity);
            }

            string get(string key) {
                int idx = this->map->lookup(key);
                if (idx) {
                    Node *node = this->map->getTable[idx]->value;
                    this->list->move_to_front(node);
                    return node->data;
                } else {
                    return NULL;
                }
            }

            void put(string key, string value){
                if (this->map->lookup(key)) {
                    string data = this->get(key);
                    if (data != value){
                        this->map->delete_node(key);
                        this->list->delete_head();
                        this->list->add_first(value);
                        this->map->insert(key, this->list->head);
                    }
                }else{
                    if (capacity >= size) {
                        size++;
                        this->list->add_first(value);
                        this->map->insert(key, this->list->head);
                    } else {
                        string key = this->list->get_last_key();
                        this->list->delete_tail();
                        this->map->delete_node(key);
                        this->list->add_first(value);
                        this->map->insert(key, this->list->head); 
                    }
                }
            }
    };
}