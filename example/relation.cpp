#include <iostream>
#include "../include/relation.hpp"
#include "../src/tag.cpp"

using taxo::relation;
using taxo::tag;

int main (){
/* create a tag */
relation<bool> A(false);
relation<int> B();
relation<bool> C(tag("BOOM"), true);

return 0;
}
