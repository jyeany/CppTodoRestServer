cmake_minimum_required (VERSION 3.5)
if (UNIX)
  add_definitions(-Wno-sign-compare -Wno-enum-compare)
endif(UNIX)
project(restserver)
set (CMAKE_CXX_STANDARD 11)
option(DBMS "Dbms" OFF)
include_directories("${CMAKE_SOURCE_DIR}")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/Build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
find_package( Boost 1.67 COMPONENTS
		program_options
		system
		filesystem
		thread REQUIRED )
set(OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/1.0.2o_2)
find_package(openssl COMPONENTS crypto ssl REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )
include_directories("/usr/local/Cellar/libpqxx/6.2.4/include")
find_package(cpprestsdk REQUIRED)

add_executable(restserver
  main.cpp
  include/handler.h
  src/handler.cpp
  include/router.h
  src/router.cpp
  src/model/todo.cpp
  include/model/todo.h
  src/service/todo_service.cpp
  include/service/todo_service.h)

target_link_libraries(restserver
		${Boost_LIBRARIES}
		${OPENSSL_LIBRARIES}
		cpprestsdk::cpprest)