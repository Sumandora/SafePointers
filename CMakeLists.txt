cmake_minimum_required(VERSION 3.20)

if(TARGET SafePointer)
	return()
endif()

project(SafePointer)

add_library(SafePointer INTERFACE)
target_include_directories(SafePointer INTERFACE "${PROJECT_SOURCE_DIR}/Include")

if(PROJECT_IS_TOP_LEVEL)
	add_executable(SafePointerExample "${PROJECT_SOURCE_DIR}/Example/Main.cpp")
	target_link_libraries(SafePointerExample PRIVATE SafePointer)

	enable_testing()
	add_test(NAME SafePointerExample COMMAND $<TARGET_FILE:SafePointerExample>)
endif()