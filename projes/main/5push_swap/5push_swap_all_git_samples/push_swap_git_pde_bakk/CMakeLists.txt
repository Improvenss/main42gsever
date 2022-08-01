cmake_minimum_required(VERSION 3.17)
project(push_swap C)
set(CMAKE_C_STANDARD 90)

file(GLOB util_files "src/utils/*.c")
file(GLOB chunk_files "src/chunk/*.c")
file(GLOB checker_files "src/checker/*.c")
file(GLOB operations_files "src/operations/*.c")
file(GLOB solver_files "src/solver/*.c")
file(GLOB stack_files "src/stack/*.c")
file(GLOB header_files "include/*.h")

add_executable(push_swap
		${util_files}
		${chunk_files}
		${checker_files}
		${operations_files}
		${solver_files}
		${stack_files}
		${header_files}
)

include_directories(include)
include_directories(libft/include)
include_directories(libc_vector/include)
include_directories(getnextline/include)
include_directories(ft_printf/include)

add_subdirectory(libc_vector)
