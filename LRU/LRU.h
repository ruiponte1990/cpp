#include <string> 
#include "hashMap.h"
#include "List.h"

using namespace std;

namespace LRU
{
    class LRU {
        public:
            int size;
            hashMap *map;
            LRU(int size) {
                this->size = size;
                this->map = new hashMap(size);
            }

            void refer () {

            }

    };
}