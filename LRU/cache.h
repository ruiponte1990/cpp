#include <string> 
#include "hashMap.h"
#include "List.h"

using namespace std;

namespace LRU
{
    class cache {
        public:
            int size;
            int capacity;
            hashMap *map;
            List *list;
            cache (int capacity) {
                this->size = 0;
                this->capacity = capacity;
                this->list = new List();
                this->map = new hashMap(capacity);
            }

            string get(string key) {
                int idx = this->map->lookup(key);
                if (idx >= 0) {
                    Node *node = this->map->getTable()[idx]->value;
                    this->list->move_to_front(node);
                    return node->data;
                } else {
                    return NULL;
                }
            }

            void put(string key, string value){
                if (this->map->lookup(key) >= 0) {
                    string data = this->get(key);
                    if (data != value){
                        this->map->delete_node(key);
                        this->list->delete_head();
                        this->list->add_first(key, value);
                        this->map->insert(key, this->list->head);
                    }
                }else{
                    if (capacity > size) {
                        size++;
                        this->list->add_first(key, value);
                        this->map->insert(key, this->list->head);
                    } else {
                        string lastKey = this->list->get_last_key();
                        this->map->delete_node(lastKey);
                        this->list->delete_tail();
                        this->list->add_first(key, value);
                        this->map->insert(key, this->list->head); 
                    }
                }
            }

            void print_cache() {
                int i = 0;
                cout << "MRU: key: " << this->list->head->key << ". data: " << this->list->head->data << ".\n";
                cout << "LRU: key: " << this->list->tail->key << ". data: " << this->list->tail->data << ".\n";
                while (i < this->capacity) {
                    hashNode *node = this->map->getTable()[i];
                    if (node) {
                        string tableKey = node->key;
                        string listKey = node->value->key;
                        string listData = node->value->data;
                        cout << "idx " << i << ": ";
                        cout << "Key in table: " << tableKey << ". ";
                        cout << "Key in list: " << listKey << ". ";
                        cout << "Data in list: " << listData << ".\n";
                    } else {
                        cout << "idx " << i << ": ";
                        cout << "empty.\n";
                    }
                    i++;
                }
                cout << "\n";
            }
    };
}