//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_CPP
#define TAXO_CATEGORY_CPP

#include "../include/category.hpp"
#include <limits>

#if __cplusplus >= 201103L
#define nullptr NULL
#endif

namespace taxo {
/* ctor copy tag
  Create a category with no root.
*/
category::category(
)
: value (new tag())
, count (
    new std::size_t (
      std::numeric_limits<std::size_t>::min()
    )
  )
{
}

/* ctor */
category::category(
  char const * const _str
)
: value (new tag(_str))
, count (new std::size_t(std::numeric_limits<std::size_t>::min()))
{
}

/* ctor */
category::category(
  tag const & _tag
)
: value (new tag(_tag))
, count (
    new std::size_t (
      std::numeric_limits<std::size_t>::min()
    )
  )
{
}

/* ctor copy tag & link to root
  Create a category.
*/
category::category(
  category const & _cat
)
: value (_cat.value)
, count (_cat.count) {
++(*this->count);
}

category &
category::operator=(
  category const & _cat
){
  if (*this != _cat){
  this->value = _cat.value;
  this->count = _cat.count;
  ++(*this->count);
  }
return *this;
}

category::category(
  category && _cat
)
: value (_cat.value)
, count (_cat.count) {
}

category &
category::operator=(
  category && _cat
){
  if (*this != _cat){
  this->value = _cat.value;
  this->count = _cat.count;
  }
return *this;
}

/* dtor */
category::~category(
){
  if (
    std::numeric_limits<std::size_t>::min()
  ==
    --(*this->count)
  ){
  delete count;
  delete value;
  }
}

/* merge */
bool
category::merge(
  category & _cat
){
  if (*this->value != *_cat.value)
  return false;
delete value;
*_cat.count += *this->count;
delete count;
this->count = _cat.count;
this->value = _cat.value;
return true;
}

/* split */
category
category::split() const {
return category(*this->value);
}

/* operator == */
bool
category::operator==(
  category const & _rhs
){
return (this->value == _rhs.value);
}

/* operator != */
bool
category::operator!=(
  category const & _rhs
){
return !(*this == _rhs);
}

} /* taxo */
#if __cplusplus >= 201103L
#undef nullptr
#endif
#endif
