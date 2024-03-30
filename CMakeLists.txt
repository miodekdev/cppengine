cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 17)
project(engine)

set(COMPILE_STATIC TRUE)
enable_language(ASM_NASM)
link_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(engine WIN32 include/physics.hpp include/graphics.hpp
        src/main.cpp src/graphics.cpp asm/color.asm src/physics.cpp asm/physics.asm)
target_compile_definitions(engine PRIVATE _MBCS)
target_link_libraries(engine PRIVATE d2d1.lib)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -malign-double -m64")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -malign-double -m64")
if(COMPILE_STATIC)
    set_target_properties(engine PROPERTIES LINK_FLAGS "--static")
endif()