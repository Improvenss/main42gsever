# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-src"
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-build"
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix"
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
