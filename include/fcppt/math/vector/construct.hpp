//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_VECTOR_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_VECTOR_CONSTRUCT_HPP_INCLUDED

#include <fcppt/math/is_static_size.hpp>
#include <fcppt/math/detail/construct.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/math/vector/static.hpp>


namespace fcppt
{
namespace math
{
namespace vector
{

/**
\brief Constructs a vector with dimension \p N+1 from a vector with dimension \p N
\ingroup fcpptmathvector
\tparam N Must be a static dimension
\tparam T The vector's <code>value_type</code>
\tparam S The vector's storage type
\param _base The "narrow" vector
\param _t The element to insert to "widen" \p _base

The inverse operation is fcppt::math::vector::narrow_cast.

\see fcppt::math::vector::narrow_cast

Example:

\code{.cpp}
typedef
fcppt::math::vector::static_<int,2>::type
int2;

typedef
fcppt::math::vector::static_<int,3>::type
int3;

int2 narrow_vector(1,2);
int3 wide_vector =
	fcppt::math::vector::construct(
		narrow_vector,
		3);

// Outputs: 1,2,3
std::cout << wide_vector;
\endcode
*/
template<
	typename T,
	typename N,
	typename S
>
typename boost::enable_if<
	math::is_static_size<
		N
	>,
	typename static_<
		T,
		N::value + 1
	>::type
>::type const
construct(
	basic<T, N, S> const &_base,
	T const &_t
)
{
	return
		math::detail::construct<
			typename static_<
				T,
				N::value + 1
			>::type
		>(
			_base,
			_t
		);
}

}
}
}

#endif
