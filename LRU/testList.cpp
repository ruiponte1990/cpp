#include "List.h"

using namespace LRU;

int main() 
{ 
   LRU::List *list = new List();
   list->add_last("first", "first data");
   list->add_last("second", "second data");
   list->add_last("third", "third data");
   list->print_list();
   list->add_first("fourth", "fourth data");
   list->add_first("fifth", "fifth data");
   list->add_first("sixth", "sixth data");
   list->print_list();
   cout << list->contains_key("fourth") << "\n";
   cout << list->contains_data("seventh data") << "\n";
   list->delete_key("third");
   list->delete_data("sixth data");
   list->delete_key("seventh");
   list->print_list();
   list->delete_head();
   list->delete_tail();
   list->print_list();
} 