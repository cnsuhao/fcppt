//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FATAL_HPP_INCLUDED
#define FCPPT_LOG_FATAL_HPP_INCLUDED

#include <fcppt/log/detail/level_if_enabled.hpp>
#include <fcppt/log/level.hpp>

#define FCPPT_LOG_FATAL(stream, x)\
	FCPPT_LOG_DETAIL_LEVEL_IF_ENABLED(stream, fcppt::log::level::fatal, x)

#endif
