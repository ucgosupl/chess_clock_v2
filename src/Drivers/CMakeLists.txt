set(INCLUDE_DIRS
    STM32F4xx_HAL_Driver/Inc
    STM32F4xx_HAL_Driver/Legacy
    CMSIS/Device/ST/STM32F4xx/Include
    CMSIS/Include
    
    .
)

set(C_SRCS
    #HAL Library
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
)

set(GLOBAL_DEFINES
    -DSTM32F411xE
    -DUSE_HAL_DRIVER
)

add_library(STM32_HAL STATIC ${C_SRCS}) 

target_compile_options(STM32_HAL PRIVATE "-Wall")
target_include_directories(STM32_HAL PUBLIC ${INCLUDE_DIRS})
target_compile_definitions(STM32_HAL PUBLIC ${GLOBAL_DEFINES})
