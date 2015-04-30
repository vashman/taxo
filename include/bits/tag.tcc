//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_TAG_TCC
#define TAXO_TAG_TCC

namespace taxo {
/* ctor */
template <typename allocator>
template <typename Iter>
tag<allocator>::tag(
  Iter _begin
, Iter _end
)
  : tag (_begin, _end) {
}

/* ctor */
template <typename allocator>
template <typename charT>
tag<allocator>::tag(
  charT const * const _str
)
  : tag (_str) {
}

/* dtor */
template <typename allocator>
tag<allocator>::~tag(
){
}

/* operator compare equal */
template <typename allocator>
bool
operator==(
  tag<allocator> const & _rhs
, tag<allocator> const & _lhs
){
return (_rhs.tag == _lhs.tag);
}

/* operator compare not equal */
template <typename allocator>
bool
operator!=(
  tag<allocator> const & _rhs
, tag<allocator> const & _lhs
){
return !(_rhs == _lhs);
}

/* assignment operator */
template <typename allocator>
template <typename charT>
void
tag<allocator>::operator=(
  charT const * const _str
){
this->tag = _str;
}

} /* taxo */
#endif
