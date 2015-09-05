//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IN_RANGE_DIM_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IN_RANGE_DIM_HPP_INCLUDED

#include <fcppt/make_int_range_count.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/container/grid/dim.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/size_type.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Checks if the given position \p _pos is out of bounds.

\ingroup fcpptcontainergrid

\returns <code>true</code> if is not out of bounds, <code>false</code> otherwise.
*/
template<
	typename T,
	fcppt::container::grid::size_type N
>
inline
bool
in_range_dim(
	fcppt::container::grid::dim<
		T,
		N
	> const _dim,
	fcppt::container::grid::pos<
		T,
		N
	> const _pos
)
{
	return
		fcppt::algorithm::all_of(
			fcppt::make_int_range_count(
				N
			),
			[
				&_dim,
				&_pos
			](
				fcppt::container::grid::size_type const _index
			)
			{
				return
					_pos[
						_index
					]
					<
					_dim[
						_index
					];
			}
		);
}

}
}
}

#endif
