cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
project(engine)

set(COMPILE_STATIC TRUE)
set(RELEASE FALSE)

enable_language(ASM_NASM)
link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(engine WIN32 include/physics.hpp include/graphics.hpp include/color.hpp
        src/main.cpp src/graphics.cpp src/physics.cpp src/color.cpp
        asm/color.asm asm/physics.asm)
target_compile_definitions(engine PRIVATE _MBCS)
target_link_libraries(engine PRIVATE d2d1.lib)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -malign-double -m64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -malign-double -m64")
if(COMPILE_STATIC)
    set_target_properties(engine PROPERTIES LINK_FLAGS "--static")
endif()
if(RELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()