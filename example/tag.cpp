#include <iostream>
#include "../include/tag.hpp"
#include "../src/tag.cpp"

using taxo::tag;

int main (){
tag name ("MY Name");
/* Tags constructed with the same data
  should have the same value.
*/
tag name2 ("MY Name");
tag att1 ("Origin");
tag att2 (name2);

att2 = att1;

  /* Compare tags */
  if (name == name2){
  std::cout
  << "Tags are the same."
  << std::endl;
  }

  if (name2 != att1){
  std::cout
  << "Tags are differnt."
  << std::endl;
  }

  if (att1 == att2){
  std::cout
  << "Tags are the same."
  << std::endl;
  }

return 0;
}
