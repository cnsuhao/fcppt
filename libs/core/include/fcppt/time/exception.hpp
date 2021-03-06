//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TIME_EXCEPTION_HPP_INCLUDED
#define FCPPT_TIME_EXCEPTION_HPP_INCLUDED

#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>


namespace fcppt
{
namespace time
{

/**
\brief The exception base class for time exceptions

\ingroup fcppttime
*/
class exception
:
	public fcppt::exception
{
public:
	/**
	\brief Constructs the exception given an error message

	Constructs the exception give \a message

	\param message The message of the exception
	*/
	explicit
	exception(
		fcppt::string const &message
	);
};

}
}

#include <fcppt/time/impl/exception.hpp>

#endif
