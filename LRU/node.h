#include <string> 
using namespace std;

#ifndef NODE
#define NODE
namespace LRU

{
    struct Node
    {
        public:
            Node *next;
            Node *prev;
            string key;
            string data;

            Node (string key, string data) {
                this->key = key;
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
    };
}
#endif