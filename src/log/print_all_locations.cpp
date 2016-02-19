//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/io/ostream.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/print_all_locations.hpp>
#include <fcppt/log/impl/print_locations_function.hpp>


void
fcppt::log::print_all_locations(
	fcppt::io::ostream &_stream,
	fcppt::log::context &_context
)
{
	_context.apply_all(
		fcppt::log::impl::print_locations_function(
			_stream
		)
	);
}
