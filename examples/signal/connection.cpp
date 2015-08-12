//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//! [signal_connection]
#include <fcppt/assign/make_container.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

void
function1()
{
}

void
function2()
{
}

void
function3()
{
}

void
function4()
{
}

}

namespace
{

void
take_connection(
	fcppt::signal::auto_connection
)
{
	// do something with connection
}

}

int
main()
{
	typedef fcppt::signal::object<
		void ()
	> void_signal;

	void_signal signal;

	// use fcppt::assign::make_container to pass a container of connections
	fcppt::signal::auto_connection_container const connections(
		fcppt::assign::make_container<
			fcppt::signal::auto_connection_container
		>(
			signal.connect(
				void_signal::function{
					::function1
				}
			)
		)
		(
			signal.connect(
				void_signal::function{
					::function2
				}
			)
		)
	);

	// scoped_connection can also be used
	fcppt::signal::scoped_connection const connection3(
		signal.connect(
			void_signal::function{
				::function3
			}
		)
	);

	// or you can take the auto_connection and process it somehow
	fcppt::signal::auto_connection connection4(
		signal.connect(
			void_signal::function{
				::function4
			}
		)
	);

	::take_connection(
		std::move(
			connection4
		)
	);
}
//! [signal_connection]
