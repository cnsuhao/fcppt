//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/init.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/object.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_RECORD_MAKE_LABEL(
	int_label
);

template<
	typename Record
>
struct init_function
{
	template<
		typename Type
	>
	fcppt::record::label_value_type<
		Record,
		int_label
	>
	operator()(
		fcppt::record::element<
			int_label,
			Type
		>
	) const
	{
		return
			42;
	}
};

template<
	typename Record
>
void
init_test()
{
	Record const record(
		fcppt::record::init<
			Record
		>(
			init_function<
				Record
			>{}
		)
	);

	BOOST_CHECK_EQUAL(
		fcppt::record::get<
			int_label
		>(
			record
		),
		42
	);

	BOOST_CHECK_EQUAL(
		Record{
			int_label{} =
				42
		},
		record
	);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	init_fusion
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::record::object<
		boost::mpl::vector1<
			fcppt::record::element<
				int_label,
				int
			>
		>
	>
	my_record;

	init_test<
		my_record
	>();
}
