//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed_fun.hpp>
#include <fcppt/math/matrix/comparison.hpp>
#include <fcppt/math/matrix/output.hpp>
#include <fcppt/math/matrix/row.hpp>
#include <fcppt/math/matrix/static.hpp>
#include <fcppt/math/matrix/structure_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	math_matrix_structure_cast
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::math::matrix::static_<
		unsigned,
		2,
		2
	>
	ui2_matrix;

	typedef
	fcppt::math::matrix::static_<
		int,
		2,
		2
	>
	i2_matrix;

	i2_matrix const result(
		fcppt::math::matrix::row(
			1, 2
		),
		fcppt::math::matrix::row(
			3, 4
		)
	);

	i2_matrix const converted(
		fcppt::math::matrix::structure_cast<
			i2_matrix,
			fcppt::cast::to_signed_fun
		>(
			ui2_matrix(
				fcppt::math::matrix::row(
					1u, 2u
				),
				fcppt::math::matrix::row(
					3u, 4u
				)
			)
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		converted
	);
}
