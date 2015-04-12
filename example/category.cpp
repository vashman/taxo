#include "../include/category.hpp"
using taxo::category;

int main (){
category cat1 ("tag");
category cat2 ("tag2", cat1);
return 0;
}
