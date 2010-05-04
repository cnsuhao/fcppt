//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/matrix/determinant.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(delete_row_and_column_test)
{
	typedef 
	fcppt::math::matrix::static_<
		int,
		3,
		3
	>::type 
	large_matrix_type;

	typedef 
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>::type 
	small_matrix_type;

	BOOST_CHECK((
		fcppt::math::matrix::determinant(
			large_matrix_type(
				1,2,3,
				4,5,6,
				7,8,9)) == 0));

	BOOST_CHECK((
		fcppt::math::matrix::determinant(
			small_matrix_type(
				-3,-5,
				-1,-2)) == 1));
}