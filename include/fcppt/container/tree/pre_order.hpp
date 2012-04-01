//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_PRE_ORDER_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/container/tree/is_object.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/next_prior.hpp>
#include <boost/static_assert.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <stack>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace tree
{

/**
\brief Wraps a tree to make it iterable in a pre-order fashion.
\ingroup fcpptcontainertree

Internally, this class manages a stack, losely imitating the runtime stack in a
recursive implementation.

<strong>Example:</strong>

\snippet container/tree_traversal.cpp main
*/
template<
	typename Tree
>
class pre_order
{
	BOOST_STATIC_ASSERT(
		is_object<
			typename boost::remove_const<
				Tree
			>::type
		>::value
	);

	FCPPT_NONCOPYABLE(
		pre_order
	);
public:
	/**
	\brief Construct a pre-order traversal from a tree (which can be const or nonconst)
	*/
	explicit pre_order(
		Tree &_tree
	)
	:
		tree_(_tree)
	{}

	class iterator;
private:
	typedef typename boost::mpl::if_<
		boost::is_const<
			Tree
		>,
		typename Tree::const_reverse_iterator,
		typename Tree::reverse_iterator
	>::type tree_iterator;

	typedef typename tree_iterator::pointer tree_pointer;

	typedef std::stack<
		tree_pointer
	> stack_type;

	typedef typename Tree::child_list child_list;

	typedef boost::iterator_facade<
		iterator,
		typename tree_iterator::value_type,
		boost::forward_traversal_tag,
		typename tree_iterator::reference
	> iterator_base;
public:

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

	class iterator
	:
		public iterator_base
	{
	public:

FCPPT_PP_POP_WARNING

		iterator()
		:
			current_(
				fcppt::null_ptr()
			),
			positions_()
		{
		}

		explicit
		iterator(
			tree_pointer const _current
		)
		:
			current_(
				_current
			),
			positions_()
		{
		}

		iterator(
			iterator const &_other
		)
		:
			current_(
				_other.current_
			),
			positions_(
				_other.positions_
			)
		{
		}

		iterator &
		operator=(
			iterator const &_other
		)
		{
			current_ = _other.current_;

			positions_ = _other.positions_;

			return *this;
		}

		~iterator()
		{
		}

		typedef typename iterator_base::value_type value_type;

		typedef typename iterator_base::reference reference;

		typedef typename iterator_base::pointer pointer;

		typedef typename iterator_base::difference_type difference_type;

		typedef typename iterator_base::iterator_category iterator_category;

		friend class boost::iterator_core_access;
	private:
		void
		increment()
		{
			if(
				!current_->empty()
			)
			{
				for(
					tree_iterator
						it(
							current_->rbegin()
						),
						end(
							boost::prior(
								current_->rend()
							)
						);
					it != end;
					++it
				)
					positions_.push(
						&*it
					);

				current_ = &current_->front();
			}
			else if(
				positions_.empty()
			)
				current_ = fcppt::null_ptr();
			else
			{

				current_ = positions_.top();

				positions_.pop();
			}
		}

		reference
		dereference() const
		{
			return *current_;
		}

		bool
		equal(
			iterator const &_other
		) const
		{
			return current_ == _other.current_;
		}

		tree_pointer current_;

		stack_type positions_;
	};

	/**
	\brief Return an iterator to the first tree in the traversal
	*/
	iterator const
	begin() const
	{
		return
			iterator(
				&tree_
			);
	}

	/**
	\brief Return a dummy iterator to stop the traversal
	*/
	iterator const
	end() const
	{
		return
			iterator(
				fcppt::null_ptr()
			);
	}
private:
	Tree &tree_;
};

}
}
}

#endif
