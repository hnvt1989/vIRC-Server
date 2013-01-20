################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/All_UTests.c \
../src/Client.c \
../src/Connection.c \
../src/CuTest.c \
../src/Message.c \
../src/Message_Test.c \
../src/Query.c \
../src/Room.c \
../src/Server.c \
../src/User.c \
../src/Utilities.c \
../src/main.c 

OBJS += \
./src/All_UTests.o \
./src/Client.o \
./src/Connection.o \
./src/CuTest.o \
./src/Message.o \
./src/Message_Test.o \
./src/Query.o \
./src/Room.o \
./src/Server.o \
./src/User.o \
./src/Utilities.o \
./src/main.o 

C_DEPS += \
./src/All_UTests.d \
./src/Client.d \
./src/Connection.d \
./src/CuTest.d \
./src/Message.d \
./src/Message_Test.d \
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
	gcc -I/home/huy/git/vIRC-Server/vIRC-Server/include -I/usr/include -I/usr/include/x86_64-linux-gnu -I/usr/lib/gcc/x86_64-linux-gnu/4.7/include -I/usr/lib/gcc/x86_64-linux-gnu/4.7/include-fixed -I/usr/local/include -O0 -g3 -Wall -c -fmessage-length=0 -pthread -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


