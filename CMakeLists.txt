cmake_minimum_required(VERSION 2.8.11)

project(GuiSelfGoverningShip)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

include_directories(/usr/include/jsoncpp)
link_directories(/usr/lib)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets)


file(
	GLOB_RECURSE
	source_files
	src/*
)

add_executable(
	gui
	${source_files}
)

target_link_libraries(
	gui
	jsoncpp
	Qt5::Widgets
)