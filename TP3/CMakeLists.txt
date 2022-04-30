cmake_minimum_required(VERSION 3.21)
project(TP3_NF16 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP3_NF16 main.c election_presidentielle.c election_presidentielle.h interface_presidentielle.c interface_presidentielle.h)
