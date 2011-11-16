//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_GET_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_GET_HPP_INCLUDED

#include <fcppt/variant/object_impl.hpp>


namespace fcppt
{
namespace variant
{

template<
	typename Type,
	typename Elements
>
Type &
get(
	variant::object<
		Elements
	> &_object
)
{
	return
		_object.get<
			Type
		>();
}

template<
	typename Type,
	typename Elements
>
Type const &
get(
	variant::object<
		Elements
	> const &_object
)
{
	return
		_object.get<
			Type
		>();
}

}
}

#endif