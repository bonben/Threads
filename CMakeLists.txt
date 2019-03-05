cmake_minimum_required (VERSION 3.0.2)
project                (threads      )


# Enable C++11
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    set (CMAKE_CXX_STANDARD 14)
else ()
    set (CMAKE_CXX_STANDARD 11)
endif()

add_compile_options(-pthread)
	file (GLOB_RECURSE source_files src/*)
add_library    (threads-obj OBJECT ${source_files})
add_executable (threads-bin $<TARGET_OBJECTS:threads-obj>)
target_link_libraries (threads-bin -lpthread)

set                    (EXECUTABLE_OUTPUT_PATH bin/)
