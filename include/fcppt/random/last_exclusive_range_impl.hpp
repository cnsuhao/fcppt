//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_IMPL_HPP_INCLUDED

#include <fcppt/random/last_exclusive_range_decl.hpp>
#include <fcppt/random/range_impl.hpp>
#include <fcppt/random/exclusive_range_error.hpp>
#include <fcppt/text.hpp>

template<
	typename T
>
fcppt::random::last_exclusive_range<T>::last_exclusive_range(
	T const &first,
	T const &last
)
:
	range<
		T
	>(
		first,
		last - static_cast<T>(1)
	)
{
	if(first == last)
		throw exclusive_range_error(
			FCPPT_TEXT("last_exclusive_range empty!")
		);
}

#endif