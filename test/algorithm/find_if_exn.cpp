//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_if_exn.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
check_function(
	std::runtime_error const &
)
{
	return
		true;
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	algorithm_find_if_exn
)
{
FCPPT_PP_POP_WARNING

	typedef
	std::vector<
		int
	>
	int_vector;

	int_vector const vec{
		1,
		2,
		3
	};

	auto const make_exception(
		[]{
			return
				std::runtime_error("");
		}
	);

	BOOST_CHECK(
		fcppt::algorithm::find_if_exn(
			vec.begin(),
			vec.end(),
			[](
				int const _i
			)
			{
				return
					_i == 3;
			},
			make_exception
		)
		==
		std::next(
			vec.begin(),
			2
		)
	);

	BOOST_CHECK_EXCEPTION(
		fcppt::algorithm::find_if_exn(
			vec,
			[](
				int const _i
			)
			{
				return
					_i == 4;
			},
			make_exception
		),
		std::runtime_error,
		check_function
	);
}
