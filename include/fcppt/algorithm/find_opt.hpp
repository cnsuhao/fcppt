//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_FIND_OPT_HPP_INCLUDED
#define FCPPT_ALGORITHM_FIND_OPT_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/container/to_iterator_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Like std::find but returns an empty optional on failure

\ingroup fcpptalgorithm
*/
template<
	typename Range,
	typename T
>
fcppt::optional<
	fcppt::container::to_iterator_type<
		typename
		std::remove_reference<
			Range
		>::type
	>
>
find_opt(
	Range &&_range,
	T const &_value
)
{
	typedef
	fcppt::container::to_iterator_type<
		typename
		std::remove_reference<
			Range
		>::type
	>
	iterator_type;

	typedef
	fcppt::optional<
		iterator_type
	>
	result_type;

	iterator_type const end{
		_range.end()
	};

	iterator_type const ret(
		::std::find(
			_range.begin(),
			end,
			_value
		)
	);

	return
		ret
		==
		end
		?
			result_type()
		:
			result_type(
				ret
			)
		;
}

}
}

#endif
