//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ENUM_ARRAY_FOLD_STATIC_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ENUM_ARRAY_FOLD_STATIC_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/cast/int_to_enum.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Array,
	typename Function
>
class enum_array_fold_static_function
{
	FCPPT_NONASSIGNABLE(
		enum_array_fold_static_function
	);
public:
	explicit
	enum_array_fold_static_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	typedef
	typename
	Array::value_type
	result_type;

	template<
		std::size_t Index
	>
	result_type
	operator()() const
	{
		return
			function_. template operator()<
				fcppt::cast::int_to_enum<
					typename Array::enum_type
				>(
					Index
				)
			>();
	}
private:
	Function const function_;
};

}
}
}

#endif