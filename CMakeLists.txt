cmake_minimum_required(VERSION 2.8.9)
project(MySQL)

# Bring the header file
include_directories(include)
# include_directories(/usr/include/mysql)
# Add source files
# set(SOURCES src/main.cpp src/student.cpp)

# However the file(GLOB...) allows for wildcard additions
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11")
 
include(FindPkgConfig)
pkg_check_modules(LIBMYSQLCLIENT REQUIRED mysqlclient)
 
foreach(FLAG ${LIBMYSQLCLIENT_CFLAGS_OTHER})
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${FLAG}")
endforeach()
 
link_directories(${LIBMYSQLCLIENT_LIBRARY_DIRS})
 
add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${LIBMYSQLCLIENT_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${LIBMYSQLCLIENT_LIBRARIES})
