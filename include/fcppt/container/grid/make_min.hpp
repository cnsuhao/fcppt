//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_MAKE_MIN_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_MAKE_MIN_HPP_INCLUDED

#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Creates min from a pos value

\ingroup fcpptcontainergrid
*/
template<
	typename SizeType,
	fcppt::container::grid::size_type N
>
inline
fcppt::container::grid::min_from_pos<
	fcppt::container::grid::pos<
		SizeType,
		N
	>
>
make_min(
	fcppt::container::grid::pos<
		SizeType,
		N
	> const _pos
)
{
	return
		fcppt::container::grid::min_from_pos<
			fcppt::container::grid::pos<
				SizeType,
				N
			>
		>{
			_pos
		};
}

}
}
}

#endif
