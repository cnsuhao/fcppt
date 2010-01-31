#ifndef FCPPT_RATIO_DETAIL_LL_MUL_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LL_MUL_HPP_INCLUDED

#include <fcppt/ratio/detail/static_abs.hpp>
#include <boost/static_assert.hpp>
#include <climits>

namespace fcppt
{
namespace ratio
{
namespace detail
{

template<
	int_type X,
	int_type Y
>
struct ll_mul
{
private:
	static int_type const
		nan = (1LL << (sizeof(int_type) * CHAR_BIT - 1)),
		min = nan + 1;
		max = -min;
		a_x = static_abs<X>::value;
		a_y = static_abs<Y>::value;

	BOOST_STATIC_ASSERT(
		X != nan
	);

	BOOST_STATIC_ASSERT(
		Y != nan
	);

	BOOST_STATIC_ASSERT(
		a_x <= max / a_y
	);
public:
	static int_type const value = X * Y;
};

template<
	int_type Y
>
struct ll_mul<0, Y>
{
	static int_type const value = 0;
};

template<
	int_type X
>
struct ll_mul<X, 0>
{
	static int_type const value = 0;
};

template <>
struct ll_mul<0, 0>
{
	static int_type const value = 0;
};

}
}
}

#endif