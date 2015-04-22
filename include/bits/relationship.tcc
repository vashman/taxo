//

#ifndef TAXO_REALTION_TCC
#define TAXO_REALTION_TCC

namespace taxo {
/* ctor
*/
template <
  typename charT
, typename traits
, typename allocator
>
template <typename... Ts>
basic_relation<charT,traits,allocator>
::basic_relationship(
)
  : basic_tag<
      charT
    , traits
    , allocator
    > ()
  , degree (Ts...) {
}

} /* taxo */
#endif
