cmake_minimum_required(VERSION 3.29)
project(Learning C)

set(CMAKE_C_STANDARD 11)

# 500
add_executable(GameOfLife K500/501-game-of-life.c)
add_executable(Ackermann K500/506-ackermann.c)
add_executable(Hanoi K500/507-hanoi.c)
add_executable(Preprocessor K500/508-preprocessor.c)

# 600
add_executable(AddressList K600/601-address-list.c)
