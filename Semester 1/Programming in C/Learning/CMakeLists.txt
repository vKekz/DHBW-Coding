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

# 700
add_executable(VariablesAndMemory K700/701-variables_and_memory.c)
add_executable(Pointers K700/702-pointers.c)
add_executable(Malloc K700/703-malloc_eratosthenes.c)
add_executable(FunctionPlotter K700/705-function-plotter.c)
add_executable(LinkedList K700/706-linked_list.c)

add_executable(Gedankenprotokoll gedankenProtokoll.c)