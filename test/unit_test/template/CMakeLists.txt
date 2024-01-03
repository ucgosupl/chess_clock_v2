set(CMAKE_C_COMPILER gcc)
set(CMAKE_AR ar)
set(CMAKE_RANLIB ranlib)

add_subdirectory(../unity unity)

set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(INCLUDE_DIRS
	../../src
)

set(TEST_INCLUDE_DIRS
	..
	.
)

set(SRCS

)

set(TEST_SRCS
	template_test_main.c
	template_test_runner.c
	template_test.c
)

set(GLOBAL_DEFINES

)

add_executable(unit_test_template ${SRCS} ${TEST_SRCS})
add_test(template unit_test_template)

target_include_directories(unit_test_template PRIVATE ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
target_compile_definitions(unit_test_template PRIVATE ${GLOBAL_DEFINES})
target_link_libraries(unit_test_template PRIVATE unity)


