// Copyright (c) 2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAOCPP_JSON_INCLUDE_INTERNAL_JSON5_CONTROL_HPP
#define TAOCPP_JSON_INCLUDE_INTERNAL_JSON5_CONTROL_HPP

#include "../../external/pegtl/contrib/changes.hpp"

#include "errors.hpp"

#include "unescape_action.hpp"

#include "../key_state.hpp"
#include "../number_state.hpp"
#include "../string_state.hpp"

namespace tao
{
   namespace json
   {
      namespace internal
      {
         namespace json5
         {
            template< typename Rule >
            struct control
               : errors< Rule >
            {
            };

            template< bool NEG >
            struct control< rules::number< NEG > >
               : json_pegtl::change_state< rules::number< NEG >, number_state< NEG >, errors >
            {
            };

            template<>
            struct control< rules::string< '"' >::content >
               : json_pegtl::change_state_and_action< rules::string< '"' >::content, string_state, unescape_action, errors >
            {
            };

            template<>
            struct control< rules::string< '\'' >::content >
               : json_pegtl::change_state_and_action< rules::string< '\'' >::content, string_state, unescape_action, errors >
            {
            };

            template<>
            struct control< rules::key< '"' >::content >
               : json_pegtl::change_state_and_action< rules::key< '"' >::content, key_state, unescape_action, errors >
            {
            };

            template<>
            struct control< rules::key< '\'' >::content >
               : json_pegtl::change_state_and_action< rules::key< '\'' >::content, key_state, unescape_action, errors >
            {
            };

         }  // namespace json5

      }  // namespace internal

   }  // namespace json

}  // namespace tao

#endif
