//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_FILTER_HPP_INCLUDED
#define FCPPT_OPTIONAL_FILTER_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Filters an optional

\ingroup fcpptoptional

If \a _source is set to <code>x</code> and <code>_function(x)</code> returns
true, \a _source is returned. Otherwise, the empty optional is returned.

\tparam Function A function callable as <code>bool (Optional::value_type)</code>.
*/
template<
	typename Optional,
	typename Function
>
typename
std::decay<
	Optional
>::type
filter(
	Optional &&_source,
	Function const &_function
)
{
	return
		_source.has_value()
		&&
		_function(
			_source.get_unsafe()
		)
		?
			std::forward<
				Optional
			>(
				_source
			)
		:
			typename
			std::decay<
				Optional
			>::type{}
		;
}

}
}

#endif
