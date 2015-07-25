//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_TCC
#define TAXO_CATEGORY_TCC

#if __cplusplus >= 201103L
#define nullptr NULL
#endif

#include <iterator>
#include <algorithm>

namespace taxo {
/* create_category
  Create a category, copying if it is
  all ready in a range.
*/
template <typename Iter>
category
create_category(
  Iter _first
, Iter _last
, tag & _tag
){
Iter
iter = std::find(_first, _last, _tag);
  if ( iter != _last){
  return *iter;
  }
return category(_tag);
}

} /* taxo */
#if __cplusplus >= 201103L
#undef nullptr
#endif
#endif
