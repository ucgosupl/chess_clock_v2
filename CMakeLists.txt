cmake_minimum_required(VERSION 3.17)

enable_language(ASM)

project(clock)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

add_subdirectory(test/unit_test/unity unity)
add_subdirectory(test/unit_test/fff fff)

add_subdirectory(test/unit_test/events)
add_subdirectory(test/unit_test/game_modes)
add_subdirectory(test/unit_test/config)
add_subdirectory(test/unit_test/preset_modes)
add_subdirectory(test/unit_test/edit)

add_subdirectory(src)
