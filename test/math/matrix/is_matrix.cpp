//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


BOOST_AUTO_TEST_CASE(is_matrix_test)
{
	typedef
	fcppt::math::matrix::static_<
		double,
		3,
		3
	>::type
	large_matrix_type;

	BOOST_CHECK(
		fcppt::math::matrix::is_matrix<large_matrix_type>::value);

	BOOST_CHECK(
		!fcppt::math::matrix::is_matrix<int>::value);
}
