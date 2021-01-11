cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 14)
project(cloudPCL)

aux_source_directory(. DIR_SRCS)

include_directories(inc)
include_directories(inc/google_log)

FIND_LIBRARY(GLOG_LIB glog ./inc/google_log NO_DEFAULT_PATH)
FIND_LIBRARY(GLOGR_LIB glogr ./inc/google_log NO_DEFAULT_PATH)
link_libraries(${GLOG_LIB} ${GLOGR_LIB})
set(OUTPUT_DIRECTORY_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/build/${CMAKE_BUILD_TYPE})
# 设置可执行程序输出到build/Debug/bin目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY_ROOT}/bin" CACHE PATH "Runtime directory" FORCE)
# 设置库文件输出到build/Debug/lib目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY_ROOT}/lib" CACHE PATH "Library directory" FORCE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY_ROOT}/lib" CACHE PATH "Archive directory" FORCE)


find_package(Boost REQUIRED COMPONENTS
  thread
)


include_directories(
  inc
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

add_library(r2000_driver
  src/driver/r2000_driver.cpp
  src/driver/http_command_interface.cpp
  src/driver/scan_data_receiver.cpp
)
target_link_libraries(r2000_driver
  ${catkin_LIBRARIES}
  ${Boost_LIBRARIES}
)


find_package(PCL REQUIRED)

add_subdirectory(src)



 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g -w -L../lib/pepperl_fuchs_r2000 -lr2000_driver -L/usr/local/lib_boost -lboost_system -lboost_thread -fopenmp") 

add_executable(cloudPCL ${DIR_SRCS})

target_link_libraries(cloudPCL ${PCL_LIBRARIES} depends r2000_driver)
