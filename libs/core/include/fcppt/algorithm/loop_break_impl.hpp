//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_LOOP_BREAK_IMPL_HPP_INCLUDED
#define FCPPT_ALGORITHM_LOOP_BREAK_IMPL_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/algorithm/loop_break_impl_fwd.hpp>
#include <fcppt/algorithm/range_element_type.hpp>


namespace fcppt
{
namespace algorithm
{

template<
	typename Range,
	typename Enable
>
struct loop_break_impl
{
	template<
		typename Body
	>
	inline
	static
	void
	execute(
		Range &&_range,
		Body const &_body
	)
	{
		for(
			fcppt::algorithm::range_element_type<
				Range
			> element
			:
			_range
		)
			switch(
				_body(
					element
				)
			)
			{
			case fcppt::loop::break_:
				return;
			case fcppt::loop::continue_:
				break;
			}
	}
};

}
}

#endif
