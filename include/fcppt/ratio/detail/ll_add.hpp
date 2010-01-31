#ifndef FCPPT_RATIO_DETAIL_LL_ADD_HPP_INCLUDED
#define FCPPT_RATIO_DETAIL_LL_ADD_HPP_INCLUDED

#include <fcppt/ratio/detail/static_sign.hpp>
#include <fcppt/ratio/int_type.hpp>
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
	int_type Y,
	int_type = static_sign<Y>::value
>
struct ll_add;

template<
	int_type X,
	int_type Y
>
struct ll_add<X, Y, 1>
{
private:
	static int_type const
		min = (1LL << (sizeof(int_type) * CHAR_BIT - 1)) + 1,
		max = -min;

	BOOST_STATIC_ASSERT(
		X <= max - Y
	);
public:
	static int_type const value = X + Y;
};

template<
	int_type X,
	int_type Y
>
struct ll_add<X, Y, 0>
{
	static int_type const value = X;
};

template<
	int_type X,
	int_type Y
>
struct ll_add<X, Y, -1>
{
private:
	static int_type const
		min = (1LL << (sizeof(int_type) * CHAR_BIT - 1)) + 1,
		max = -min;

	BOOST_STATIC_ASSERT(
		min - Y <= X
	);
public:
	static int_type const value = X + Y;
};

}
}
}

#endif