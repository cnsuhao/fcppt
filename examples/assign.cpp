//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr_fcppt.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <vector>
#include <fcppt/config/external_end.hpp>


int
main()
{
// ![assign]
	typedef
	std::vector<
		fcppt::unique_ptr<
			int
		>
	>
	int_unique_ptr_vector;

	int_unique_ptr_vector const int_ptrs(
		fcppt::assign::make_container<
			int_unique_ptr_vector
		>(
			fcppt::make_unique_ptr_fcppt<
				int
			>(
				1
			)
		)(
			fcppt::make_unique_ptr_fcppt<
				int
			>(
				2
			)
		)
	);

	// Prints 1 2
	for(
		auto const &elem
		:
		int_ptrs
	)
		std::cout << *elem << '\n';
// ![assign]
}