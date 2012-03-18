//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_STATIC_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_STATIC_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage.hpp>
#include <fcppt/math/vector/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Typedef helper for static vectors
\ingroup fcpptmathvector
\tparam The vector's <code>value_type</code>
See the introduction to fcppt::math::vector::object for more information on
static vectors (and on this class).
*/
template<
	typename T,
	size_type N
>
struct static_
{
	typedef object<
		T,
		boost::mpl::integral_c<
			size_type,
			N
		>,
		typename math::detail::static_storage<
			T,
			N
		>::type
	> type;
};

}
}
}

#endif
