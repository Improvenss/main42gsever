# libc_vector
My own little vector in C.
One thing I still want to do is determine if the type inside the vector is a pointer, so I can free it when I deallocate it.
A vector of ints doesn't need this of course, but a vector of structs would benefit from this a lot.

### Workflows to test compilation on Ubuntu and macOS:
[![Ubuntu C/C++ CI](https://github.com/pde-bakk/libc_vector/actions/workflows/ubuntu-build.yml/badge.svg)](https://github.com/pde-bakk/libc_vector/actions/workflows/ubuntu-build.yml)
[![macOS C/C++ CI](https://github.com/pde-bakk/libc_vector/actions/workflows/macos-build.yml/badge.svg)](https://github.com/pde-bakk/libc_vector/actions/workflows/macos-build.yml)
