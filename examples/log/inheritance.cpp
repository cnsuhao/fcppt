/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


//[loginheritance
#include <fcppt/log/object.hpp>
#include <fcppt/log/headers.hpp>
#include <fcppt/log/parameters/root.hpp>
#include <fcppt/log/parameters/inherited.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/text.hpp>

int main()
{
	fcppt::log::object parent_(
		fcppt::log::parameters::root(
			fcppt::io::cout
		)
		.prefix(
			FCPPT_TEXT("parent")
		)
		.enabled(
			true
		)
		.level(
			fcppt::log::level::debug
		)
		.create()
	);

	fcppt::log::object child_(
		fcppt::log::parameters::inherited(
			parent_,
			FCPPT_TEXT("child")
		)
	);

	FCPPT_LOG_DEBUG(
		child_,
		fcppt::log::_
			<< FCPPT_TEXT("Print from child.")
	);
}
//]