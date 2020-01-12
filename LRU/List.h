#include "node.h"
#include <string> 
#include <iostream>  
using namespace std;

namespace LRU

{
    class List {
        public:
            Node *head = NULL;
            Node *tail = NULL;
            int size = 0;

            List(){};

            void add_first(string key, string data){
                Node *new_node = new Node(key, data);
                if ( this->head == NULL) {
                    this->head = new_node;
                    this->tail = new_node;
                } else{
                    new_node->next = head;
                    head->prev = new_node;
                    head = new_node;
                }
                this->size++;
            }

            void move_to_front(Node *node){
                node->next = head;
                head->prev = node;
                head = node;
            }

            void add_last(string key, string data) {
                Node *new_node = new Node(key, data);
                if (this->head == NULL) {
                    this->head = new_node;
                    this->tail = new_node;
                } else {
                    new_node->prev= tail;
                    tail->next = new_node;
                    tail = new_node;
                }
                this->size++;
            }

            void delete_data(string data) {
                Node *curr = this->head;
                if ( curr->data == data) {
                    this->head = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                    this->size--;
                    return;
                }
                while (curr->next && curr->data != data) {
                     curr = curr->next;
                }
                if (curr->data == data) {
                    curr->prev->next = curr->next;
                    if (curr->next) {
                       curr->next->prev = curr->prev; 
                    } else{
                        this->tail = curr->prev;
                    }
                    delete curr;
                    this->size--;
                }
            }

            void delete_key(string key) {
                Node *curr = this->head;
                if ( curr->key == key) {
                    this->head = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                    this->size--;
                    return;
                }
                while (curr->next && curr->key != key) {
                     curr = curr->next;
                }
                if (curr->key == key) {
                    curr->prev->next = curr->next;
                    if (curr->next) {
                       curr->next->prev = curr->prev; 
                    } else{
                        this->tail = curr->prev;
                    }
                    delete curr;
                    this->size--;
                }
            }

            void delete_at(int index) {
                int i = 0;
                Node *curr = this->head;
                while (curr->next && i < index) {
                    curr = curr->next;
                }
                if (i == index) {
                    if (curr->prev) {
                    curr->prev->next = curr->next;
                    }    
                    if (curr->next) {
                        curr->next->prev = curr->prev;
                    }
                    delete curr;
                    this->size--;         
                }
            }

            void delete_head() {
                Node *curr = this->head;
                this->head = curr->next;
                curr->next->prev = NULL;
                delete curr;
                this->size--;
            }

            string get_last_key() {
                return this->tail->key;
            }

            void delete_tail() {
                Node *curr = this->tail;
                this->tail = curr->prev;
                this->tail->next = NULL;
                delete curr;
                this->size--;
            }

            bool contains_data(string data) {
                Node *curr = this->head;
                while (curr->next && curr->data != data) {
                    curr = curr->next;
                }
                if (curr->data == data) {
                    return true;
                }
                return false;
            }

            bool contains_key(string key) {
                Node *curr = this->head;
                while (curr->next && curr->key != key) {
                    curr = curr->next;
                }
                if (curr->key == key) {
                    return true;
                }
                return false;
            }

            void print_list() {
                cout << "head: " << this->head->data << ".\n";
                Node *curr = this->head;
                while (curr->next) {
                    print_node(curr);
                    curr = curr->next;
                }
                print_node(curr);
                cout << "tail: " << this->tail->data << ".\n";
            }

            void print_node(Node *node) {
                if (node->prev) {
                    cout << "prev key: " << node->prev->key << ". ";
                    cout << "prev data: " << node->prev->data << ". ";
                } else{
                    cout << "prev: Null. ";
                }
                cout << "curr key: " << node->key << ". ";
                cout << "curr data: " << node->data << ". ";
                if (node->next) {
                    cout << "next key: " << node->next->key << ".\n";
                    cout << "next data: " << node->next->data << ".\n";
                } else{
                    cout << "next: Null.\n";
                }
            }
    };
}