//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/filesystem/extension_without_dot.hpp>
#include <fcppt/filesystem/extension.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>

fcppt::string const
fcppt::filesystem::extension_without_dot(
	path const &path_
)
{
	fcppt::string ret(
		filesystem::extension(
			path_
		)
	);

	if(
		!ret.empty()
		&& ret[0] == FCPPT_TEXT('.')
	)
		ret.erase(
			ret.begin()
		);
	
	return ret;
}