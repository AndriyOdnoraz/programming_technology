-include ../makefile.init
MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_DIR := $(dir $(MAKEFILE_PATH))

ifeq ($(OS),Windows_NT)
    DETECTED_OS := Windows
    PATH_SEP := \\
    RM := del /Q
    MKDIR := mkdir
    LINKER_SCRIPT_PATH := D:\\programming_technology\\stm32l475\\stm32_test\\STM32L475VGTX_FLASH.ld
else
    DETECTED_OS := $(shell uname -s)
    PATH_SEP := /
    RM := rm -rf
    MKDIR := mkdir -p
    # Use relative path for Linux/Unix systems
    LINKER_SCRIPT_PATH := $(MAKEFILE_DIR)../STM32L475VGTX_FLASH.ld
endif

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := stm32_test
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stm32_test.elf \

MAP_FILES += \
stm32_test.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm32_test.list \


# All Target
all: main-build

# Main-build Target
main-build: stm32_test.elf secondary-outputs

# Tool invocations
stm32_test.elf stm32_test.map: $(OBJS) $(USER_OBJS) $(LINKER_SCRIPT_PATH) $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "stm32_test.elf" @"$(MAKEFILE_DIR)/objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"$(LINKER_SCRIPT_PATH)" --specs=nosys.specs -Wl,-Map="stm32_test.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm32_test.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm32_test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) default.size.stdout stm32_test.elf stm32_test.list stm32_test.map
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
