//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_SIZE_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_SIZE_HPP_INCLUDED

#include <fcppt/container/detail/array_size.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Gets the size of an array.

\ingroup fcpptcontainer

Derives from an integral constant that contains the size of \a Array.

\tparam Array Must be a <code>std::array</code>
*/
template<
	typename Array
>
using array_size
=
fcppt::container::detail::array_size<
	Array
>;

}
}

#endif
