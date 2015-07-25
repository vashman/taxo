//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_TAG_CPP
#define TAXO_TAG_CPP

#include "../include/tag.hpp"

namespace taxo {
/* ctor */
tag::tag(
  char const * const _str
)
: value (_str) {
}
/* dtor */
tag::~tag(
){
}

/* operator compare equal */
bool
operator==(
  tag const & _rhs
, tag const & _lhs
){
return (_rhs.value == _lhs.value);
}

/* operator compare not equal */
bool
operator!=(
  tag const & _rhs
, tag const & _lhs
){
return !(_rhs == _lhs);
}

} /* taxo */
#endif
