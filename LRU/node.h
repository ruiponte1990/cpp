#include <string> 
using namespace std;

namespace LRU

{
    struct Node
    {
        public:
            Node *next;
            Node *prev;
            string data;

            Node (string data) {
                this->data = data;
                this->next = nullptr;
                this->prev = nullptr;
            }
    };
}
