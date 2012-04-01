//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ENABLE_OPTIONAL_VALUE_CONV_HPP_INCLUDED
#define FCPPT_DETAIL_ENABLE_OPTIONAL_VALUE_CONV_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Own,
	typename Other,
	typename Result
>
struct enable_optional_value_conv
:
boost::enable_if<
	boost::mpl::and_<
		boost::is_reference<
			Other
		>,
		boost::is_same<
			Own,
			typename boost::remove_const<
				typename boost::remove_reference<
					Other
				>::type
			>::type
		>
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
