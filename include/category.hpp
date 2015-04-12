//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_HPP
#define TAXO_CATEGORY_HPP

#include <set>
#include "tag.hpp"

namespace taxo {
/**/
template <
  typename charT
, typename traits = std::char_traits<charT>
, typename allocator = std::allocator<charT>
>
class basic_category : public basic_tag<charT,traits,allocator> {
public:
  /* ctor */
  basic_category(
    basic_tag<charT,traits,allocator>
  , basic_category<charT,traits,allocator> const &
  );
  
  /* ctor */
  basic_category(
    charT const * const
  , basic_category<charT,traits,allocator> const &
  );
  
  /* ctor */
  basic_category(
    basic_tag<charT,traits,allocator> _tag
  );
  
  /* ctor */
  basic_category(
    charT const * const _tag
  );
  
  virtual
  ~basic_category(
  );

private:
  /* notify_detach */
  void
  notify_detach(
    basic_category<charT,traits,allocator> const * const _leaf
  );

  /* notify_detach */
  void
  notify_detach(
  );

  /* attach */
  void
  attach(
    basic_category<charT,traits,allocator> const & _root
  );

  /* detach */
  void
  detach(
  );

  basic_category<charT,traits,allocator> * const root;
  
  std::set<basic_category<charT,traits,allocator> const * const> leafs;
};

typedef basic_category<char> category;
typedef basic_category<wchar_t> wcategory;

namespace bits {
/* detach function */
template <typename charT, typename traits, typename allocator>
void
detach(
  basic_category<charT,traits,allocator> const * const _leaf
);

} /* bits */ } /* taxo */
#include "bits/category.tcc"
#endif
