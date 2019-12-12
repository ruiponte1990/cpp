#include "node.h"
#include <string> 
using namespace std;

namespace LRU

{
    class List {
        public:
            Node *head = nullptr;

            // need an add first for LRU, this is add last

            void add(Node *head, string data) {
                if ( head == nullptr) {
                    head = new Node(data);
                } else {
                    Node *curr = head;
                    while (curr->next) {
                        curr = curr->next;
                    }
                    Node *next = new Node(data);
                    curr->next = next;
                    next->prev = curr;
                }
            }

            void delete_node(string data) {
                Node *curr = this->head;
                while (curr->next && curr->data != data) {
                     curr = curr->next;
                }
                if (curr->data == data) {
                    //  how to handle leaks...
                    Node *prev = curr->prev;
                    prev->next = curr->next;
                }
            }

            bool contains(string data) {
                Node *curr = this->head;
                while (curr->next && curr->data != data) {
                     curr = curr->next;
                }
                if (curr->data == data) {
                    return true;
                }
                return false;
            }
    };
}