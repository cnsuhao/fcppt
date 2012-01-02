/**
\defgroup fcpptcasts Casts
\ingroup fcpptmain
\brief Cast helpers which provide more type information or do additional checks

\section fcpptcasts_dynamic_casting Dynamic casting

Let's say you have the following extremely simple class hierarchy:

\code
class base
{
	// Just to make the base class polymorphic
	virtual ~base() {}
};

class derived : public base
{
};

int main()
{
	derived most_derived;
	base &base_ref = most_derived;

	// More to come...
}
\endcode

In C++, when you have a base class and want to "get to" a derived class, you have three options:

<ol>
	<li>
	<strong><code>static_cast</code></strong>: This is the unsafest cast of
	them all. If it fails, you get undefined behaviour (meaning you
	application will crash at a random place):

	\code
	derived &d = static_cast<derived &>(base_ref);
	\endcode

	Because it does no error-checking, however, this cast will be the
	fastest. You can do it when you're sure the base class reference you
	have is really pointing to a derived class.
	</li>
	<li>
	<strong><code>dynamic_cast</code> with pointers</strong>: If you're not
	sure that the base class reference you have is really pointing to a
	derived class <code>derived</code>, you can do an error-checking test
	such as the dynamic cast with pointers:

	\code
	derived *d = dynamic_cast<derived *>(base_ref);

	if(d)
		std::cout << "Yeah, it worked!\n";
	else
		std::cout << "Ooops, wrong type\n";
	\endcode

	This is still pretty fast and it's safer. But you have to use pointers, which is pretty ugly.
	</li>
	<li>
	<strong><code>dynamic_cast</code> with references</strong>: If you
	replace the pointers in the above example by references, you get the
	third method of casting:

	\code
	derived &d = dynamic_cast<derived &>(base_ref);
	\endcode

	This is still safe. Why? Well, it'll throw an exception
	(<code>std::%bad_cast</code>) if the cast doesn't work. This, however,
	might not be what you want, for several reasons:

	For one, the exception gives you absolutely no information about what
	went wrong. But what you might want to know, for example, is which type
	failed to convert to which other type?

	Also, you cannot use this cast in an <code>if</code> statement. You
	have to use either pointers or a <code>catch</code> block to achieve
	that.
	</li>
</ol>

For these reasons, fcppt provides helpers for dynamic-casting. To work around
the ugly pointer cast, there is fcppt::optional_dynamic_cast which returns an
fcppt::optional.

To provie a little more information on the types for the reference
<code>dynamic_cast</code>, there is fcppt::dynamic_cast_ (mind the
underscore!).
*/