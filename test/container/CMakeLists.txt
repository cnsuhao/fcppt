function(
	add_fcppt_container_test
	TEST_NAME
)
	add_fcppt_test(
		container/${TEST_NAME}
		${ARGN}
	)
endfunction()

add_fcppt_container_test(
	at_optional
)

add_subdirectory(
	bitfield
)

add_fcppt_container_test(
	data
)

add_fcppt_container_test(
	enum_array
)

add_fcppt_container_test(
	find_opt
)

add_fcppt_container_test(
	find_opt_mapped
)

add_fcppt_container_test(
	get_or_insert
)

add_subdirectory(
	grid
)

add_fcppt_container_test(
	index_map
)

add_fcppt_container_test(
	make_array
)

add_fcppt_container_test(
	maybe_back
)

add_fcppt_container_test(
	maybe_front
)

add_fcppt_container_test(
	raw_vector
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_subdirectory(
	tree
)

add_fcppt_container_test(
	untuple
)
