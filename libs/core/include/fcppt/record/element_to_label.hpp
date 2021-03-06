//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_TO_LABEL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TO_LABEL_HPP_INCLUDED

#include <fcppt/record/element_to_label_tpl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Extracts the type of an element

\ingroup fcpptrecord

\tparam Element Must be an \link fcppt::record::element\endlink.
*/
template<
	typename Element
>
using
element_to_label
=
typename
fcppt::record::element_to_label_tpl<
	typename
	std::decay<
		Element
	>::type
>::type;

}
}

#endif
