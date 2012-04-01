//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_IS_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/container/array_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T
>
struct is_static_storage
:
boost::false_type
{};

template<
	typename T,
	std::size_t N
>
struct is_static_storage<
	fcppt::container::array<
		T,
		N
	>
>
:
boost::true_type
{};

FCPPT_PP_POP_WARNING

}
}
}

#endif
