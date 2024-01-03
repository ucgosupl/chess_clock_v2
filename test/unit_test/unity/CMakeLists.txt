add_library(unity STATIC
	core/unity.c
	fixture/unity_fixture.c
) 

target_compile_options(unity PRIVATE "-Wall")
