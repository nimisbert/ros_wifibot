cmake_minimum_required(VERSION 2.8.3)

project(wifibot)

find_package(catkin REQUIRED roscpp std_msgs)
#find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

catkin_package(
	INCLUDE_DIRS include
	LIBRARIES $wifibot
	CATKIN_DEPENDS roscpp)

include_directories(include ${catkin_INCLUDE_DIRS})

file( GLOB_RECURSE wifibot_HEARDERS include/*.h )
file( GLOB_RECURSE wifibot_SOURCES src/*.cpp )

add_library(
	wifibot SHARED 
	src/wifibot.cpp 
	src/i2c.cpp
	src/module.cpp
	src/motor.cpp
	src/servo.cpp
	src/sharp.cpp
	)

include_directories(${WIRINGPI_INCLUDE_DIRS})
target_link_libraries(wifibot ${WIRINGPI_LIBRARIES}) 
target_link_libraries(wifibot ${CMAKE_THREAD_LIBS_INIT}) 

add_executable(user_motor scripts/user_motor.cpp)
target_link_libraries(user_motor wifibot ${catkin_LIBRARIES})
add_dependencies(user_motor wifibot)

add_executable(user_sharp scripts/user_sharp.cpp)
target_link_libraries(user_sharp wifibot ${catkin_LIBRARIES})
add_dependencies(user_sharp wifibot)

add_executable(user_servo scripts/user_servo.cpp)
target_link_libraries(user_servo wifibot ${catkin_LIBRARIES})
add_dependencies(user_servo wifibot)

add_executable(motor nodes/dev_motor.cpp)
target_link_libraries(motor wifibot ${catkin_LIBRARIES})
add_dependencies(motor wifibot)

add_executable(i2c nodes/dev_i2c.cpp)
target_link_libraries(i2c wifibot ${catkin_LIBRARIES})
add_dependencies(i2c wifibot)

add_executable(servo nodes/dev_servo.cpp)
target_link_libraries(servo wifibot ${catkin_LIBRARIES})
add_dependencies(servo wifibot)

add_executable(sharp nodes/dev_sharp.cpp)
target_link_libraries(sharp wifibot ${catkin_LIBRARIES})
add_dependencies(sharp wifibot)

SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov" "-lwiringPi")
