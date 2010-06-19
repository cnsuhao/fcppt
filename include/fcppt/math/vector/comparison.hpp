//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_COMPARISON_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_COMPARISON_HPP_INCLUDED

#include <fcppt/math/detail/array_compare.hpp>
#include <fcppt/math/vector/basic_impl.hpp>

namespace fcppt
{
namespace math
{
namespace vector
{

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator==(
	basic<T, N, S1> const &v1,
	basic<T, N, S2> const &v2
)
{
	return
		fcppt::math::detail::array_compare(
			v1,
			v2
		);
}

template<
	typename T,
	typename N,
	typename S1,
	typename S2
>
bool
operator!=(
	basic<T, N, S1> const &v1,
	basic<T, N, S2> const &v2
)
{
	return
		!(v1 == v2);
}

}
}
}

#endif