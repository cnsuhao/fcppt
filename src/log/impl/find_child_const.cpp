//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/impl/find_child_const.hpp>
#include <fcppt/log/impl/const_optional_context_tree_ref.hpp>
#include <fcppt/optional/deref.hpp>


fcppt::log::impl::const_optional_context_tree_ref
fcppt::log::impl::find_child_const(
	fcppt::log::detail::context_tree const &_tree,
	fcppt::log::name const &_name
)
{
	// TODO: Combine this with find_child
	return
		fcppt::optional::deref(
			fcppt::algorithm::find_if_opt(
				_tree,
				[
					&_name
				](
					fcppt::log::detail::context_tree const &_child
				)
				{
					return
						_child.value().name()
						==
						_name;
				}
			)
		);
}
