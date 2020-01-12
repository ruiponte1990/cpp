#include <string> 
using namespace std;
#include "hashNode.h"
#include <math.h>
#include <iostream>
#include <vector>

namespace LRU
{
    class hashMap {
        hashNode** table;
        int size;
        int population;
        public:
            hashMap(int size) {
                this->table = new hashNode*[size];
                this->size = size;
                this->population = 0;
            }

            hashNode** getTable(){
                return this->table;
            }

            int hash_func(string data) {
                int hash = 13;
                int len = data.size();
                for (int i =0; i < len; i++) {
                    hash = hash*31 + data.at(i);
                }
                return abs(hash);
            }

            int collision_func(int collisions) {
                // return (pow(collisions,2)/2);
                return collisions;
            }

            void insert(string data, Node *addr) {
                if (this->population < this->size) {
                    int hash = hash_func(data);
                    int len = this->size;
                    int idx = hash % len;
                    int collisions = 0;
                    while (this->table[idx] != NULL && this->table[idx]->key != data) {
                        collisions++;
                        idx = (hash + collision_func(collisions)) % len; 
                    }
                    if (this->table[idx] == NULL) {
                        hashNode *node = new hashNode(data, addr);
                        this->table[idx] = node;
                        this->population++;
                    } else{
                        hashNode *node = new hashNode(data, addr);
                        this->table[idx] = node;
                    }
                }
            }

            void delete_node(string data) {
                if (this->population > 0) {
                    int lookup = this->lookup(data);
                    if (lookup != -1) {
                        delete this->table[lookup];
                        this->table[lookup] = NULL;
                        this->population--;
                    }
                }
            }

            int lookup (string data) {
                if (this->population > 0) {
                    int hash = hash_func(data);
                    int len = this->size;
                    int idx = hash % len;
                    int collisions = 0;
                    while (this->table[idx] != NULL && this->table[idx]->key != data && collisions < this->size) {
                        collisions++;
                        idx = (hash + collision_func(collisions)) % len;
                    }
                    if (this->table[idx] && this->table[idx]->key == data) {
                        return idx;
                    } else {
                        return -1;
                    }
                }else {
                    return -1;
                }
            }

            void print_map() {
                for (int i = 0; i < this->size; i++) {
                    if (this->table[i]) {
                        cout << "idx: " << i << "\n";
                        cout <<"key: " << this->table[i]->key << ", " << "value: " << this->table[i]->value << ".\n";
                    } else {
                        cout << "idx: " << i << "\n";
                        cout << "empty.\n";
                    }
                }
            }
    };
}