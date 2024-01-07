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
	${SRC_PATH}/mode/mode.c

	${SRC_PATH}/mode/fixed/fixed.c
	${SRC_PATH}/mode/fixed/config_fixed.c
	${SRC_PATH}/mode/fixed/edit_fixed.c

	${SRC_PATH}/mode/fixed_control/fixed_control.c
	${SRC_PATH}/mode/fixed_control/config_fixed_control.c
	${SRC_PATH}/mode/fixed_control/edit_fixed_control.c

	${SRC_PATH}/mode/bonus/bonus.c
	${SRC_PATH}/mode/bonus/config_bonus.c
	${SRC_PATH}/mode/bonus/edit_bonus.c

	${SRC_PATH}/mode/bonus_control/bonus_control.c
	${SRC_PATH}/mode/bonus_control/config_bonus_control.c
	${SRC_PATH}/mode/bonus_control/edit_bonus_control.c
)

set(TEST_NAME edit)

set(TEST_SRCS
	${TEST_NAME}_test_main.c
	${TEST_NAME}_test_runner.c
	${TEST_NAME}_fixed_test.c
	${TEST_NAME}_bonus_test.c
	${TEST_NAME}_bonus_control_test.c
	${TEST_NAME}_fixed_control_test.c

	display_mocks.c
)

set(GLOBAL_DEFINES

)

add_executable(unit_test_${TEST_NAME} ${SRCS} ${TEST_SRCS})
add_test(${TEST_NAME} unit_test_${TEST_NAME})

target_include_directories(unit_test_${TEST_NAME} PRIVATE ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
target_compile_definitions(unit_test_${TEST_NAME} PRIVATE ${GLOBAL_DEFINES})
target_link_libraries(unit_test_${TEST_NAME} PRIVATE unity)


