add_library(buffer SHARED buffer.cpp)
install(TARGETS buffer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
