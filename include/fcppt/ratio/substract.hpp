#ifndef FCPPT_RATIO_SUBSTRACT_HPP_INCLUDED
#define FCPPT_RATIO_SUBSTRACT_HPP_INCLUDED

#include <fcppt/ratio/substract_fwd.hpp>
#include <fcppt/ratio/detail/static_gcd.hpp>
#include <fcppt/ratio/detail/ll_sub.hpp>
#include <fcppt/ratio/detail/ll_mul.hpp>
#include <fcppt/ratio/object.hpp>
#include <fcppt/ratio/multiply.hpp>

namespace fcppt
{
namespace ratio
{

template <
	typename R1,
	typename R2
>
struct subtract
{
private:
	static int_type const
		gcd_n1_n2 = detail::static_gcd<R1::num, R2::num>::value,
		gcd_d1_d2 = detail::static_gcd<R1::den, R2::den>::value;
public:
	typedef typename multiply<
		object<
			gcd_n1_n2,
			R1::den / gcd_d1_d2
		>,
		object
		<
			detail::ll_sub
			<
				detail::ll_mul<
					R1::num / gcd_n1_n2,
					R2::den / gcd_d1_d2
				>::value,
				detail::ll_mul<
					R2::num / gcd_n1_n2,
					R1::den / gcd_d1_d2
				>::value
			>::value,
			R2::den
		>
	>::type type;
};

}
}

#endif