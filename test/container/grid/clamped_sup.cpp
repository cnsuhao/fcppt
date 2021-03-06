//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/clamped_sup.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_grid_clamped_sup
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::grid::dim<
		unsigned,
		2
	>
	dim;

	typedef
	fcppt::container::grid::pos<
		unsigned,
		2
	>
	pos;

	BOOST_CHECK_EQUAL(
		fcppt::container::grid::clamped_sup(
			pos(
				4u,
				5u
			),
			dim(
				3u,
				3u
			)
		).get(),
		pos(
			3u,
			3u
		)
	);
}
