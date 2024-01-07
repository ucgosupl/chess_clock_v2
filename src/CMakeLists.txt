set(CMAKE_TOOLCHAIN_FILE ../cmake/toolchain-arm-gcc.cmake)
include(../cmake/compiler_flags.cmake)

add_subdirectory(Drivers)

set(INCLUDE_DIRS

    Core/Inc
   
    .
)

set(C_SRCS
    #Cube Generated
    Core/Src/stm32f4xx_hal_msp.c
    Core/Src/stm32f4xx_it.c
    Core/Src/system_stm32f4xx.c
    Core/Src/syscalls.c
    Core/Src/sysmem.c

    Core/Src/main.c

    #User Code
    buttons/buttons.c

    display/display.c

    events/events.c

    hd44780/hd44780.c

    mode/fixed/fixed.c
    mode/fixed/config_fixed.c
    mode/fixed/edit_fixed.c

    mode/fixed_control/fixed_control.c
    mode/fixed_control/config_fixed_control.c
    mode/fixed_control/edit_fixed_control.c

    mode/bonus/bonus.c
    mode/bonus/config_bonus.c
    mode/bonus/edit_bonus.c

    mode/bonus_control/bonus_control.c
    mode/bonus_control/config_bonus_control.c
    mode/bonus_control/edit_bonus_control.c

    mode/mode.c

    periodic_tasks/periodic_tasks.c

    state_machine/state_config/state_config.c
    state_machine/state_edit/state_edit.c
    state_machine/state_game/state_game.c
    state_machine/state_mode/state_mode.c
    state_machine/state_machine.c

    turn/turn.c
)

set(ASM_SRCS
    Core/Startup/startup_stm32f411retx.s
)

set(GLOBAL_DEFINES
    -DSTM32F411xE
    -DUSE_HAL_DRIVER
)

set(LINKED_LIBS

)

link_directories(

)

include_directories(${INCLUDE_DIRS})
add_definitions(${GLOBAL_DEFINES})

# generate elf file
add_arm_executable(${CMAKE_PROJECT_NAME} ${C_SRCS} ${ASM_SRCS})
arm_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS} PUBLIC STM32_HAL)