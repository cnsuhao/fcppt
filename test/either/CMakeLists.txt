function(
	add_fcppt_either_test
	TEST_NAME
)
	add_fcppt_test(
		either/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_either_test(
	apply
)

add_fcppt_either_test(
	bind
)

add_fcppt_either_test(
	failure_opt
)

add_fcppt_either_test(
	first_success
)

add_fcppt_either_test(
	from_optional
)

add_fcppt_either_test(
	make_failure
)

add_fcppt_either_test(
	make_success
)

add_fcppt_either_test(
	map
)

add_fcppt_either_test(
	match
)

add_fcppt_either_test(
	object
)

add_fcppt_either_test(
	sequence
)

add_fcppt_either_test(
	success_opt
)

add_fcppt_either_test(
	to_exception
)

add_fcppt_either_test(
	try_call
)
