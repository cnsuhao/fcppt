/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/container/tree/object_fwd.hpp>
#include <fcppt/auto_ptr.hpp>
#include <boost/ptr_container/ptr_list.hpp>

namespace fcppt
{
namespace container
{
namespace tree
{

template<
	typename T
>
class object
{
public:
	typedef boost::ptr_list<
		object	
	> child_list;

	typedef fcppt::auto_ptr<
		object	
	> auto_ptr;

	typedef typename child_list::value_type value_type;
	typedef typename child_list::size_type size_type;
	typedef typename child_list::difference_type difference_type;
	typedef typename child_list::reference reference;
	typedef typename child_list::const_reference const_reference;
	typedef typename child_list::iterator iterator;
	typedef typename child_list::const_iterator const_iterator;
	typedef typename child_list::reverse_iterator reverse_iterator;
	typedef typename child_list::const_reverse_iterator const_reverse_iterator;

	object();

	explicit object(
		T const &
	);

	~object();

	child_list &
	children();

	child_list const &
	children() const;

	object &
	parent();

	object const &
	parent() const;

	object *
	parent_ptr();

	object const *
	parent_ptr() const;

	bool
	has_parent() const;

	void
	parent(
		object &
	);

	void
	orphan();

	auto_ptr
	release(
		iterator
	);

	iterator
	child_position();

	const_iterator
	child_position() const;

	void
	value(
		T const &
	);

	T &
	value();

	T const &
	value() const;

	void
	push_back(
		auto_ptr
	);

	void
	push_back(
		T const &
	);

	void
	pop_back();

	void
	push_front(
		auto_ptr
	);

	void
	push_front(
		T const &
	);

	void
	pop_front();

	void
	clear();

	reference
	back();

	const_reference
	back() const;

	reference
	front();

	const_reference
	front() const;

	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	reverse_iterator
	rbegin();

	reverse_iterator
	rend();

	const_reverse_iterator
	rbegin() const;

	const_reverse_iterator
	rend() const;

	void
	insert(
		iterator,
		auto_ptr
	);

	void
	insert(
		iterator,
		T const &
	);

	void
	erase(
		iterator
	);

	void
	erase(
		iterator,
		iterator
	);

	size_type
	size() const;

	size_type
	max_size() const;

	bool
	empty() const;
private:
	T value_;
	object *parent_;
	child_list children_;
};

template<
	typename T
>
bool
operator==(
	object<T> const &,
	object<T> const &
);

template<
	typename T
>
bool
operator!=(
	object<T> const &,
	object<T> const &
);

}
}
}

#endif