//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_TAG_TCC
#define TAXO_TAG_TCC

namespace taxo {
/* ctor */
template <typename Iter>
tag::tag(
  Iter _begin
, Iter _end
)
: tag (_begin, _end) {
}

} /* taxo */
#endif
