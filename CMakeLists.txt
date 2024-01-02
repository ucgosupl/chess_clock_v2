cmake_minimum_required(VERSION 3.17)

set(CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-gcc.cmake)

enable_language(ASM)

project(clock)

include(cmake/compiler_flags.cmake)

set(INCLUDE_DIRS

    Core/Inc
    Drivers/STM32F4xx_HAL_Driver/Inc
    Drivers/STM32F4xx_HAL_Driver/Legacy
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/CMSIS/Include

    .
)

set(C_SRCS
    #HAL Library
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c

    #Cube Generated
    Core/Src/stm32f4xx_hal_msp.c
    Core/Src/stm32f4xx_it.c
    Core/Src/system_stm32f4xx.c
    Core/Src/syscalls.c
    Core/Src/sysmem.c

    Core/Src/main.c

    #User Code
    buttons/buttons.c

    config/config_bonus_control.c
    config/config_bonus.c
    config/config_fixed.c

    display/display.c

    events/events.c

    hd44780/hd44780.c

    mode/bonus_control.c
    mode/bonus.c
    mode/fixed_control.c
    mode/fixed.c
    mode/mode.c

    periodic_tasks/periodic_tasks.c

    state_machine/state_config/state_config.c
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
arm_link_libraries(${CMAKE_PROJECT_NAME} ${LINKED_LIBS})
