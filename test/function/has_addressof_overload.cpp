//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/function/detail/has_addressof_overload.hpp>
#include <boost/test/unit_test.hpp>

namespace
{

struct test_struct_no
{
};

struct test_struct_yes1
{
	int operator&()
	{
		return 42;
	}
};

struct test_struct_yes2
{
	int operator&() const
	{
		return 42;
	}
};

}

BOOST_AUTO_TEST_CASE(
	function_has_addressof_overload
)
{
	BOOST_CHECK(
		!fcppt::function::detail::has_addressof_overload<
			void(*)()
		>::value
	);


	BOOST_CHECK(
		!fcppt::function::detail::has_addressof_overload<
			test_struct_no
		>::value
	);

	BOOST_CHECK(
		fcppt::function::detail::has_addressof_overload<
			test_struct_yes1
		>::value
	);

	BOOST_CHECK(
		fcppt::function::detail::has_addressof_overload<
			test_struct_yes2
		>::value
	);
}