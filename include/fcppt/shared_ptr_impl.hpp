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


#ifndef FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/shared_ptr_decl.hpp>
#include <algorithm>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter>::shared_ptr()
:
	impl()
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	Y *const p
)
:
	impl(
		p,
		deleter()
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y,
	typename D,
	typename A
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	Y *const p,
	A const &a
)
:
	impl(
		p,
		deleter(),
		a
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	weak_ptr<Y, Deleter> const &r
)
:
	impl(r)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &r
)
:
	impl(r.boost_ptr())
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const & r,
	boost::detail::static_cast_tag
)
:
	impl(
		r.boost_ptr(),
		boost::detail::static_cast_tag()
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &r,
	boost::detail::const_cast_tag
)
:
	impl(
		r.boost_ptr(),
		boost::detail::const_cast_tag()
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &r,
	boost::detail::dynamic_cast_tag
)
:
	impl(
		r.boost_ptr(),
		boost::detail::dynamic_cast_tag()
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &r,
	boost::detail::polymorphic_cast_tag
)
:
	impl(
		r.boost_ptr(),
		boost::detail::polymorphic_cast_tag()
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	auto_ptr<Y> r
)
:
	impl()
{
	impl = r;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter> &
fcppt::shared_ptr<T, Deleter>::operator=(
	shared_ptr<Y> const &r
)
{
	impl = r.impl;
	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter> &
fcppt::shared_ptr<T, Deleter>::operator=(
	auto_ptr<Y> r
)
{
	impl = r;
	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter>::~shared_ptr()
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::shared_ptr<T, Deleter>::reset()
{
	impl.reset();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
void
fcppt::shared_ptr<T, Deleter>::reset(
	Y *const p
)
{
       	impl.reset(
		p,
		deleter()
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y,
	typename A
>
void
fcppt::shared_ptr<T, Deleter>::reset(
	Y *const p,
	A const &a
)
{
	impl.reset(
		p,
		deleter(),
		a
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::reference
fcppt::shared_ptr<T, Deleter>::operator* () const
{
	return *impl;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::pointer
fcppt::shared_ptr<T, Deleter>::operator-> () const
{
	return impl.operator->();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::pointer
fcppt::shared_ptr<T, Deleter>::get() const
{
       	return impl.get();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter>::operator
typename fcppt::shared_ptr<T, Deleter>::unspecified_bool_type() const
{
	return impl;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::shared_ptr<T, Deleter>::operator! () const
{
	return !impl;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::shared_ptr<T, Deleter>::unique() const
{
	return impl.unique();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
long
fcppt::shared_ptr<T, Deleter>::use_count() const
{
	return impl.use_count();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::shared_ptr<T, Deleter>::swap(
	shared_ptr<T> &other
)
{
	std::swap(
		impl,
		other.impl
	);
 }

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::impl_type const
fcppt::shared_ptr<T, Deleter>::boost_ptr() const
{
	return impl;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
Deleter<T> const
fcppt::shared_ptr<T, Deleter>::deleter()
{
	return Deleter<T>();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename U
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	boost::shared_ptr<U> const &p
)
:
	impl(p)
{}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
fcppt::operator==(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b
)
{
	return a.boost_ptr() == b.boost_ptr();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
fcppt::operator!=(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b
)
{
	return !(a==b);
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
fcppt::operator<(
	shared_ptr<T, Deleter> const &a,
	shared_ptr<U, Deleter> const &b
)
{
	return a.boost_ptr() < b.boost_ptr();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
void
fcppt::swap(
	shared_ptr<T, Deleter> &a,
	shared_ptr<T, Deleter> &b)
{
	a.swap(b);
}

template<
	typename Ch,
	typename Traits,
	typename T,
	template<
		typename
	> class Deleter
>
std::basic_ostream<Ch, Traits> &
fcppt::operator<< (
	std::basic_ostream<Ch, Traits> &os,
	shared_ptr<T, Deleter> const & p
)
{
	os << p.get();
	return os;
}

#endif
