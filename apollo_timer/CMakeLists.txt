cmake_minimum_required(VERSION 2.8.3)
project(apollo_timer)

set(CMAKE_CXX_STANDARD 11)

include("cmake/FindGlog.cmake")

list(APPEND LINKER_LIBS ${GLOG_LIBRARIES})

include("cmake/FindGFlags.cmake")

list(APPEND LINKER_LIBS ${GFLAGS_LIBRARIES})

include_directories(
        include
        ${GLOG_INCLUDE_DIRS}
        ${GFLAGS_INCLUDE_DIRS}
)

message(STATUS "TEST filesystem:" ${GLOG_INCLUDE_DIRS})

add_executable(apollo_timer_demo
        src/duration.cpp
        src/timer.cpp
        src/config_gflags.cpp
        src/main.cpp)

target_link_libraries(apollo_timer_demo
        ${LINKER_LIBS})


