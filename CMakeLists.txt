cmake_minimum_required(VERSION 3.5.1)
project(ft_retro)
set(CC /usr/bin/clang)
set(CXX /usr/bin/clang++)


set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -I includes")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(SOURCE_FILES
		src/main.cpp
		src/gameLoop.cpp
		src/actions.cpp
		src/obstacles.cpp
		src/LinkedList.cpp
		src/Bullet/Bullet.cpp
		src/Enemy/Enemy.cpp
		src/Enemy/Zorg.cpp
		src/Player/Player.cpp
		src/Player/ShipOne.cpp)
include_directories(includes)

add_executable(ft_retro ${SOURCE_FILES})
target_link_libraries(ft_retro ${CURSES_LIBRARIES})
