//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_CERR_HPP_INCLUDED
#define FCPPT_IO_CERR_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Returns either std::cerr or std::wcerr, depending on fcppt::char_type
\ingroup fcpptstring


See the \link fcpptstring string module documentation \endlink for a motivation
for this.
*/
FCPPT_DETAIL_SYMBOL
fcppt::io::ostream &
cerr();

}
}

#endif
