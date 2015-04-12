//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TAXO_CATEGORY_HPP
#define TAXO_CATEGORY_HPP

namespace taxo {
/**/
template <
  typename charT
, typename traits = std::char_traits<charT>
, typename allocator = std::allocator<charT>
>
class basic_cetagory : public basic_tag<charT,traits,allocator> {
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

private:
  /* notify_detach */
  notify_detach(
    basic_category<charT,traits,allocator> const * const _leaf
  );

  /* notify_detach */
  notify_detach(
  );

  /* attach */
  attach(
    basic_category<charT,traits,allocator> const & _root
  );

  /* detach */
  detach(
  );

  basic_category<charT,traits,allocator> * const root;
};

namespace bits {
/* detach function */
template <typename charT, typename traits, typename allocator>
void
dettatch(
  basic_category<charT,traits,allocator> const * const _leaf
);

} /* bits */ } /* taxo */
#endif
