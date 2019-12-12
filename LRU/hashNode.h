#include <string> 
using namespace std;
#include "node.h"

namespace LRU

{
    struct hashNode
    {
        public:
            string key;
            Node *value;

            hashNode (string data) {
                this->key = data;
            }
    };
}
