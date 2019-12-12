#include "List.h"

using namespace LRU;

int main() 
{ 
   LRU::List *list = new List();
   list->add_last("first");
   list->add_last("second");
   list->add_last("third");
   list->print_list();
   list->add_first("fourth");
   list->add_first("fifth");
   list->add_first("sixth");
   list->print_list();
   cout << list->contains("fourth") << "\n";
   cout << list->contains("seventh") << "\n";
   list->delete_node("third");
   list->delete_node("sixth");
   list->delete_node("seventh");
   list->print_list();
   list->delete_head();
   list->delete_tail();
   list->print_list();
} 