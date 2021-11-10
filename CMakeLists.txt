cmake_minimum_required(VERSION 3.19)
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(LLVM_VERSION_EXPLICIT 13.0.0)
#set(LIBCLANG_LIBRARY C:/Program Files/LLVM/lib/)
#set(LIBCLANG_INCLUDE_DIR to C:/Program Files/LLVM/lib/clang/13.0.0/include/)
#set(CLANG_BINARY C:/Program Files/LLVM/bin)

project(cppastTest)

add_subdirectory ("src")
add_subdirectory ("thirdparty")
