namespace fcppt
{
namespace container
{
/**
\defgroup fcpptcontainerptr fcppt::container::ptr
\ingroup fcpptcontainer
\brief Helper functions and classes for <a href="http://www.boost.org/doc/libs/1_48_0/libs/ptr_container/doc/ptr_container.html">boost.ptr_container</a>.

The standard library requires that a type that should be stored inside a
container must fulfill the CopyConstructible and Assignable concepts. This
means that a copy constructor must be accessible, <code>&value</code> must
yield the address of <code>value</code>, and an assignment operator must also
be accessible.

This obviously limits the use of types that can be used with stdlib containers,
and <a href="http://www.boost.org/doc/libs/1_48_0/libs/ptr_container/doc/ptr_container.html">boost.ptr_container</a>
comes in handy. It provides containers like the standard library (stdlib) does
but they instead hold <em>pointers</em> to elements and take ownership over the
objects pointed to.

fcppt::container::ptr has some helper functions that make working especially
with fcppt::unique_ptr and boost.ptr_container easier. One problem is that the
ptr_container's insertion functions take either a raw pointer or a
<code>std::%auto_ptr</code>. As a memory-leak-aware C++ programmer, however,
you want to properly insert unique_ptrs into your ptr_containers, which is a
bit more work. fcppt provides all necessary functions to do that. Here's an
example using a ptr_map:

\snippet container/ptr.cpp main
*/
namespace ptr
{
}
}
}
