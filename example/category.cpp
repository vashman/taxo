#include <iostream>
#include "../include/category.hpp"

#include "../src/tag.cpp"
#include "../src/category.cpp"

using taxo::category;
using taxo::tag;

int main (){
category cat1 ("tag");
category cat2 (cat1);
category cat3 = cat2;
tag t1 ("BOOM");
category cat4(t1);
category cat5;
category cat6(cat1.split());
  if (cat1.merge(cat6)){
  std::cout << "merge complete"
  << std::endl;
  }
return 0;
}
