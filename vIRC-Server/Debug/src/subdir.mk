################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Client.c \
../src/Connection.c \
../src/Query.c \
../src/Room.c \
../src/Server.c \
../src/User.c \
../src/Utilities.c \
../src/main.c 

OBJS += \
./src/Client.o \
./src/Connection.o \
./src/Query.o \
./src/Room.o \
./src/Server.o \
./src/User.o \
./src/Utilities.o \
./src/main.o 

C_DEPS += \
./src/Client.d \
./src/Connection.d \
./src/Query.d \
./src/Room.d \
./src/Server.d \
./src/User.d \
./src/Utilities.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/huy/git/vIRC-Server/vIRC-Server/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


