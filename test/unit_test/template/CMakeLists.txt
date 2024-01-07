set(CMAKE_C_COMPILER gcc)
set(CMAKE_AR ar)
set(CMAKE_RANLIB ranlib)

set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SRC_PATH ../../../src)

set(INCLUDE_DIRS
	${SRC_PATH}
)

set(TEST_INCLUDE_DIRS
	..
	.
)

set(SRCS

)

set(TEST_NAME template)

set(TEST_SRCS
	${TEST_NAME}_test_main.c
	${TEST_NAME}_test_runner.c
	${TEST_NAME}_test.c
)

set(GLOBAL_DEFINES

)

add_executable(unit_test_${TEST_NAME} ${SRCS} ${TEST_SRCS})
add_test(${TEST_NAME} unit_test_${TEST_NAME})

target_include_directories(unit_test_${TEST_NAME} PRIVATE ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
target_compile_definitions(unit_test_${TEST_NAME} PRIVATE ${GLOBAL_DEFINES})
target_link_libraries(unit_test_${TEST_NAME} PRIVATE unity)


