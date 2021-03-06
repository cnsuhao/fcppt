//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/endianness/format.hpp>
#include <fcppt/io/read.hpp>
#include <fcppt/io/write.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
test_read_write(
	fcppt::endianness::format const _endianness
)
{
	int const foo{
		42
	};

	std::stringstream stream;

	fcppt::io::write(
		stream,
		foo,
		_endianness
	);

	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	optional_int const result(
		fcppt::io::read<
			int
		>(
			stream,
			_endianness
		)
	);

	BOOST_CHECK_EQUAL(
		result,
		optional_int(
			42
		)
	);
}

}


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	io_read_write
)
{
FCPPT_PP_POP_WARNING

	test_read_write(
		fcppt::endianness::format::big
	);

	test_read_write(
		fcppt::endianness::format::little
	);

	{
		std::stringstream stream;

		BOOST_CHECK(
			!fcppt::io::read<
				int
			>(
				stream,
				fcppt::endianness::format::little
			).has_value()
		);
	}
}
