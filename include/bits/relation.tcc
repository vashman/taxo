//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_REALTION_TCC
#define TAXO_REALTION_TCC

namespace taxo {
/* ctor */
template <typename T>
template <typename... Ts>
relation<T>::relation(
  Ts... _vs
)
: value ()
, degree (_vs...) {
}

/* ctor */
template <typename T>
template <typename... Ts>
relation<T>::relation(
  tag const & _tag
, Ts... _vs
)
: value (_tag)
, degree (_vs...) {
}

} /* taxo */
#endif
