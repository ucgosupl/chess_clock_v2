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
	${SRC_PATH}/mode/fixed_control/fixed_control.c
	${SRC_PATH}/mode/bonus/bonus.c
	${SRC_PATH}/mode/bonus_control/bonus_control.c
)

set(TEST_SRCS
	game_modes_test_main.c
	game_modes_test_runner.c
	game_mode_fixed_test.c
	game_mode_bonus_test.c
	game_mode_fixed_control_test.c
	game_mode_bonus_control_test.c
	
	mocks.c
)

set(GLOBAL_DEFINES

)

set(TEST_NAME game_modes)

add_executable(unit_test_${TEST_NAME} ${SRCS} ${TEST_SRCS})
add_test(${TEST_NAME} unit_test_${TEST_NAME})

target_include_directories(unit_test_${TEST_NAME} PRIVATE ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
target_compile_definitions(unit_test_${TEST_NAME} PRIVATE ${GLOBAL_DEFINES})
target_link_libraries(unit_test_${TEST_NAME} PRIVATE unity)


