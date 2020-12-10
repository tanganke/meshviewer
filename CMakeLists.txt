cmake_minimum_required(VERSION 3.10)
project(meshviewer)

find_package(LIBIGL REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/glad)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/libigl-imgui)

# Output directories
if(MSVC)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
else()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endif()


file(GLOB SRCFILES 
  ${CMAKE_SOURCE_DIR}/*.cpp
)
add_executable(${PROJECT_NAME}
  ${SRCFILES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
  /usr/include/eigen3
)
target_link_libraries(${PROJECT_NAME}
  imgui igl glad glfw pthread
)
# set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_OPTIONS "-pthread")

message("${LIBIGL_LIBRARIES}")
