cmake_minimum_required(VERSION 3.0)
include_directories(include)

if(ARM_BUILD)
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)
    set(CMAKE_C_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-g++)
endif(ARM_BUILD)

project(SimpleLibrary)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)



install(TARGETS Main DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
set_property(TARGET MainLib PROPERTY PUBLIC_HEADER "${SimpleLibrary_SOURCE_DIR}/include/buffer.h")
install(TARGETS MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
