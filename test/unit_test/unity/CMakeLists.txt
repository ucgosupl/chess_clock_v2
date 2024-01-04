set(CMAKE_C_COMPILER gcc)
set(CMAKE_AR ar)
set(CMAKE_RANLIB ranlib)

add_library(unity STATIC
	core/unity.c
	fixture/unity_fixture.c
) 

target_compile_options(unity PRIVATE "-Wall")
