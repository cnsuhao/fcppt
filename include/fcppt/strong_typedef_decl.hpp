//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_DECL_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/detail/strong_typedef/friend_operators.hpp>


namespace fcppt
{

/**
\brief Used to create strong typedefs
\ingroup fcpptstrongtypedef
\tparam T The underlying type to be wrapped.
\tparam Tag A unique tag type

strong_typedef has an explicit construct and explicit get member functions.
Almost all operators are overloaded and found in their respective header.
*/
template<
	typename T,
	typename Tag
>
class strong_typedef
{
public:
	/**
	\brief A type that represents the data stored in the strong typedef
	*/
	typedef T value_type;

	/**
	\brief typedef for the <code>Tag</code> template parameter
	*/
	typedef Tag tag_type;

	/**
	\brief Constructs the strong typedef from a given value using fcppt::safe_cast.
	*/
	template<
		typename U
	>
	explicit
	strong_typedef(
		U const &
	);

	/**
	\brief Assigns a new value to the strong typedef using fcppt::safe_cast.
	*/
	template<
		typename U
	>
	strong_typedef &
	operator=(
		U const &
	);

	/**
	\brief Return the strong typedef's value.
	*/
	T const &
	get() const;

	/**
	\brief Swap the contents of another strong typedef
	*/
	void
	swap(
		strong_typedef &
	);
private:
	FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_OPERATORS

	T value_;
};

template<
	typename T,
	typename Tag
>
class strong_typedef<
	T &,
	Tag
>
{
	FCPPT_NONASSIGNABLE(
		strong_typedef
	);
public:
	typedef T value_type;

	typedef T &reference;

	typedef Tag tag_type;

	explicit
	strong_typedef(
		reference
	);

	reference
	get() const;
private:
	FCPPT_DETAIL_STRONG_TYPEDEF_FRIEND_OPERATORS

	reference value_;
};


/**
\brief Swap the contents of two strong typedefs
\tparam T The underlying type to be wrapped.
\tparam Tag A unique tag type
*/
template<
	typename T,
	typename Tag
>
void
swap(
	fcppt::strong_typedef<T, Tag> &,
	fcppt::strong_typedef<T, Tag> &
);

}

#endif
