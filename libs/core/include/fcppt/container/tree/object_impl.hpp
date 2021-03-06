//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_decl.hpp>
#include <fcppt/container/tree/optional_ref_impl.hpp>
#include <fcppt/container/tree/detail/copy_children.hpp>
#include <fcppt/container/tree/detail/move_children.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename T
>
fcppt::container::tree::object<
	T
>::object(
	T const &_value
)
:
	value_(
		_value
	),
	parent_(),
	children_()
{
}

template<
	typename T
>
fcppt::container::tree::object<
	T
>::object(
	T &&_value
)
:
	value_(
		std::move(
			_value
		)
	),
	parent_(),
	children_()
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

template<
	typename T
>
fcppt::container::tree::object<
	T
>::object(
	T &&_value,
	child_list &&_children
)
:
	value_(
		std::move(
			_value
		)
	),
	parent_(),
	children_(
		fcppt::container::tree::detail::move_children(
			*this,
			std::move(
				_children
			)
		)
	)
{
}

template<
	typename T
>
fcppt::container::tree::object<
	T
>::object(
	object const &_other
)
:
	value_(
		_other.value()
	),
	parent_(),
	children_(
		fcppt::container::tree::detail::copy_children(
			*this,
			_other.children()
		)
	)
{
}

template<
	typename T
>
fcppt::container::tree::object<
	T
>::object(
	object &&_other
)
noexcept(
	std::is_nothrow_move_constructible<
		T
	>::value
)
:
	value_(
		std::move(
			_other.value()
		)
	),
	parent_(),
	children_(
		fcppt::container::tree::detail::move_children(
			*this,
			std::move(
				_other.children()
			)
		)
	)
{
}

FCPPT_PP_POP_WARNING

template<
	typename T
>
fcppt::container::tree::object<
	T
> &
fcppt::container::tree::object<
	T
>::operator=(
	object const &_other
)
{
	value_ =
		_other.value_;

	parent_
		= optional_ref();

	children_ =
		fcppt::container::tree::detail::copy_children(
			*this,
			_other.children()
		);

	return *this;
}

template<
	typename T
>
fcppt::container::tree::object<
	T
> &
fcppt::container::tree::object<
	T
>::operator=(
	object &&_other
)
noexcept(
	std::is_nothrow_move_assignable<
		T
	>::value
)
{
	value_ =
		std::move(
			_other.value_
		);

	children_ =
		fcppt::container::tree::detail::move_children(
			*this,
			std::move(
				_other.children_
			)
		);

	std::swap(
		parent_,
		_other.parent_
	);

	return
		*this;
}

template<
	typename T
>
fcppt::container::tree::object<
	T
>::~object()
{
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::child_list &
fcppt::container::tree::object<
	T
>::children()
{
	return
		children_;
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::child_list const &
fcppt::container::tree::object<
	T
>::children() const
{
	return
		children_;
}

template<
	typename T
>
typename
fcppt::container::tree::object<
	T
>::optional_ref
fcppt::container::tree::object<
	T
>::parent()
{
	return
		parent_;
}

template<
	typename T
>
typename
fcppt::container::tree::object<
	T
>::const_optional_ref
fcppt::container::tree::object<
	T
>::parent() const
{
	return
		fcppt::optional::map(
			parent_,
			[](
				fcppt::reference<
					object
				> const _val
			)
			{
				return
					fcppt::make_cref(
						_val.get()
					);
			}
		);
}

template<
	typename T
>
bool
fcppt::container::tree::object<
	T
>::has_parent() const
{
	return
		this->parent().has_value();
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::parent(
	optional_ref const &_other
)
{
	parent_ =
		_other;
}

template<
	typename T
>
fcppt::container::tree::object<
	T
>
fcppt::container::tree::object<
	T
>::release(
	iterator const _it
)
{
	object ret(
		std::move(
			*_it
		)
	);

	children_.erase(
		_it
	);

	return
		ret;
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::value(
	T const &_value
)
{
	value_ =
		_value;
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::value(
	T &&_value
)
{
	value_ =
		std::move(
			_value
		);
}

template<
	typename T
>
T &
fcppt::container::tree::object<
	T
>::value()
{
	return
		value_;
}

template<
	typename T
>
T const &
fcppt::container::tree::object<
	T
>::value() const
{
	return
		value_;
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::push_back(
	object &&_tree
)
{
	this->insert(
		this->end(),
		std::move(
			_tree
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::push_back(
	T const &_value
)
{
	this->insert(
		this->end(),
		_value
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::push_back(
	T &&_value
)
{
	this->insert(
		this->end(),
		std::move(
			_value
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::pop_back()
{
	this->children().pop_back();
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::push_front(
	object &&_tree
)
{
	this->insert(
		this->begin(),
		std::move(
			_tree
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::push_front(
	T const &_value
)
{
	this->insert(
		this->begin(),
		_value
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::push_front(
	T &&_value
)
{
	this->insert(
		this->begin(),
		std::move(
			_value
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::pop_front()
{
	this->children().pop_front();
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::clear()
{
	children_.clear();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::reference
fcppt::container::tree::object<
	T
>::back()
{
	return
		*std::prev(
			this->end()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_reference
fcppt::container::tree::object<
	T
>::back() const
{
	return
		*std::prev(
			this->end()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::reference
fcppt::container::tree::object<
	T
>::front()
{
	return
		*this->begin();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_reference
fcppt::container::tree::object<
	T
>::front() const
{
	return
		*this->begin();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::iterator
fcppt::container::tree::object<
	T
>::begin()
{
	return
		iterator(
			this->children().begin()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::iterator
fcppt::container::tree::object<
	T
>::end()
{
	return
		iterator(
			this->children().end()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_iterator
fcppt::container::tree::object<
	T
>::begin() const
{
	return
		const_iterator(
			this->children().begin()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_iterator
fcppt::container::tree::object<
	T
>::end() const
{
	return
		const_iterator(
			this->children().end()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::reverse_iterator
fcppt::container::tree::object<
	T
>::rbegin()
{
	return
		reverse_iterator(
			this->children().rbegin()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::reverse_iterator
fcppt::container::tree::object<
	T
>::rend()
{
	return
		reverse_iterator(
			this->children().rend()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_reverse_iterator
fcppt::container::tree::object<
	T
>::rbegin() const
{
	return
		const_reverse_iterator(
			this->children().rbegin()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_reverse_iterator
fcppt::container::tree::object<
	T
>::rend() const
{
	return
		const_reverse_iterator(
			this->children().rend()
		);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_iterator
fcppt::container::tree::object<
	T
>::cbegin() const
{
	return
		this->begin();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_iterator
fcppt::container::tree::object<
	T
>::cend() const
{
	return
		this->end();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_reverse_iterator
fcppt::container::tree::object<
	T
>::crbegin() const
{
	return
		this->rbegin();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::const_reverse_iterator
fcppt::container::tree::object<
	T
>::crend() const
{
	return
		this->rend();
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::insert(
	iterator const _it,
	object &&_tree
)
{
	children_.insert(
		_it,
		std::move(
			_tree
		)
	)->parent(
		optional_ref(
			fcppt::make_ref(
				*this
			)
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::insert(
	iterator const _it,
	T const &_value
)
{
	this->insert(
		_it,
		object(
			_value
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::insert(
	iterator const _it,
	T &&_value
)
{
	this->insert(
		_it,
		object(
			std::move(
				_value
			)
		)
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::erase(
	iterator const _it
)
{
	this->children().erase(
		_it
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::erase(
	iterator const _begin,
	iterator const _end
)
{
	this->children().erase(
		_begin,
		_end
	);
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::size_type
fcppt::container::tree::object<
	T
>::size() const
{
	return
		this->children().size();
}

template<
	typename T
>
typename fcppt::container::tree::object<
	T
>::size_type
fcppt::container::tree::object<
	T
>::max_size() const
{
	return
		this->children().max_size();
}

template<
	typename T
>
bool
fcppt::container::tree::object<
	T
>::empty() const
{
	return
		this->children().empty();
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::swap(
	object &_other
)
{
	using std::swap;

	swap(
		value_,
		_other.value_
	);

	std::swap(
		parent_,
		_other.parent_
	);

	children_.swap(
		_other.children_
	);
}

template<
	typename T
>
void
fcppt::container::tree::object<
	T
>::sort()
{
	children_.sort(
		[](
			object const &_left,
			object const &_right
		)
		{
			return
				_left.value()
				<
				_right.value();
		}
	);
}

template<
	typename T
>
template<
	typename Predicate
>
void
fcppt::container::tree::object<
	T
>::sort(
	Predicate const &_predicate
)
{
	children_.sort(
		[
			_predicate
		](
			object const &_left,
			object const &_right
		)
		{
			return
				_predicate(
					_left.value(),
					_right.value()
				);
		}
	);
}

template<
	typename T
>
void
fcppt::container::tree::swap(
	fcppt::container::tree::object<
		T
	> &_a,
	fcppt::container::tree::object<
		T
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
