cmake_minimum_required(VERSION 3.8)

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
