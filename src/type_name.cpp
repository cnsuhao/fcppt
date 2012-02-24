//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/type_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>
#include <fcppt/config.hpp>
#if defined(FCPPT_HAVE_GCC_DEMANGLE)
#include <fcppt/c_deleter.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cxxabi.h>
#include <fcppt/config/external_end.hpp>
#endif

fcppt::string const
fcppt::type_name(
	std::type_info const &_info
)
{
#if defined(FCPPT_HAVE_GCC_DEMANGLE)
	int status;

	fcppt::scoped_ptr<
		char,
		fcppt::c_deleter
	> name(
		abi::__cxa_demangle(
			_info.name(),
			fcppt::null_ptr(),
			fcppt::null_ptr(),
			&status
		)
	);

	// demangling failed?
	return
		status
		?
			fcppt::from_std_string(
				_info.name()
			)
		:
			fcppt::from_std_string(
				name.get()
			);
#else
	return
		fcppt::from_std_string(
			_info.name()
		);
#endif
}
