cmake_minimum_required(VERSION 3.8)

#set(LLVM_VERSION_EXPLICIT 13.0.0)
#set(LIBCLANG_LIBRARY C:/Program Files/LLVM/lib/)
#set(LIBCLANG_INCLUDE_DIR to C:/Program Files/LLVM/lib/clang/13.0.0/include/)
#set(CLANG_BINARY C:/Program Files/LLVM/bin)

add_executable(Test
        "main.cpp"
        )

target_include_directories(Test
        PUBLIC
        ""
        )

target_link_libraries(Test
        PUBLIC
        cppast
        )
