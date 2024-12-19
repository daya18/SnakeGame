# CMakeList.txt : CMake project for SnakeGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SnakeGame")

# Add source to this project's executable.
add_executable (SnakeGame )

target_sources ( SnakeGame PRIVATE 
	"source/Main.cpp"  
	"source/Application.cpp" 
	"source/game/GameLayer.cpp" 
	"source/game/snake/Snake.cpp" 
	 
	"source/Math.cpp" 
	"source/gui/HUDLayer.cpp"
 "source/game/Food.cpp" "source/game/snake/SnakeSegment.cpp" "source/game/snake/SnakeTurnPoint.cpp")

find_package ( SFML COMPONENTS system graphics window REQUIRED )

target_precompile_headers ( SnakeGame PRIVATE source/pch.hpp )

target_link_libraries ( SnakeGame PRIVATE sfml-system sfml-graphics sfml-window )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SnakeGame PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
