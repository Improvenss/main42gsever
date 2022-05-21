cmake_minimum_required(VERSION 3.17)
project(libc_vector C)

set(CMAKE_C_STANDARD 99)

file(GLOB source_files "srcs/*.c")
file(GLOB headers "include_internal/*.h")
file(GLOB test_files "test/*.c")

add_library(libc_vector
		${source_files}
		${test_files}
		${headers}
)

include_directories(include libft/include)