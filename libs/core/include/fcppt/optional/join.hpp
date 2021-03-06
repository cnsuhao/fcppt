//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_JOIN_HPP_INCLUDED
#define FCPPT_OPTIONAL_JOIN_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/detail/check.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Removes one layer of optionals

\ingroup fcpptoptional

Extracts the optional in \a _source or returns an empty optional.

\tparam Optional Must be an optional of optional
*/
template<
	typename Optional
>
inline
typename
std::remove_cv<
	typename
	std::remove_reference<
		Optional
	>::type
>::type::value_type
join(
	Optional &&_source
)
{
	typedef
	typename
	std::remove_cv<
		typename
		std::remove_reference<
			Optional
		>::type
	>::type::value_type
	result_type;

	static_assert(
		fcppt::optional::detail::check<
			Optional
		>::value
		&&
		fcppt::optional::detail::check<
			result_type
		>::value,
		"optional_join can only be called on optionals of optionals"
	);

	return
		_source.has_value()
		?
			fcppt::move_if_rvalue<
				Optional
			>(
				_source.get_unsafe()
			)
		:
			result_type()
		;
}

}
}

#endif
