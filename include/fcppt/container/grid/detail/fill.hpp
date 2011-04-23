#ifndef FCPPT_CONTAINER_GRID_DETAIL_FILL_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_FILL_HPP_INCLUDED

#include <fcppt/container/grid/size_type.hpp>
#include <fcppt/container/grid/object_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <boost/utility/enable_if.hpp>

namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{
template
<
	fcppt::container::grid::size_type Current,
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename Fn
>
typename
boost::disable_if_c
<
	Current != N,
	void
>::type
fill(
	object<T,N,A> &g,
	Fn const &f,
	typename object<T,N,A>::dim position)
{
	g[position] = 
		f(
			position);
}

template
<
	fcppt::container::grid::size_type Current,
	typename T,
	fcppt::container::grid::size_type N,
	typename A,
	typename Fn
>
typename
boost::enable_if_c
<
	Current != N,
	void
>::type
fill(
	object<T,N,A> &g,
	Fn const &f,
	typename object<T,N,A>::dim position)
{
	for(typename object<T,N,A>::size_type i = 0; i < g.size()[Current]; ++i)
	{
		position[Current] = i;
		fcppt::container::grid::detail::fill<static_cast<fcppt::container::grid::size_type>(Current+1)>(
			g,
			f,
			position);
	}
}
}
}
}
}

#endif