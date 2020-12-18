cmake_minimum_required(VERSION 3.10)
#set(CMAKE_CXX_COMPILER  "/usr/bin/clang++")
#set(CMAKE_C_COMPILER  "/usr/bin/clang")
set(CMAKE_CXX_STANDARD 17)
set(PROJECT_NAME humagl)

project(${PROJECT_NAME})
add_compile_options(
    # -Werror
	-g
    -Wall
        -Wextra
    # -Wpedantic

    # -Wcast-align
    # -Wcast-qual
    # -Wconversion
    # -Wctor-dtor-privacy
    # -Wenum-compare
    # -Wfloat-equal
    # -Wnon-virtual-dtor
    # -Wold-style-cast
    # -Woverloaded-virtual
    # -Wredundant-decls
    # -Wsign-conversion
    # -Wsign-promo
)
# target_compile_features(${PROJECT_NAME} cxx_std_17)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glm)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#add_subdirectory(./libs/glfw/)
 add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
set(INCLUDES
    include/
    include/States/
    libs/glad/include/
    libs/glfw/include/
    libs/stb_image/
    libs/glm/ src/)
set(SOURCEFILES
    main.cpp
    libs/glad/src/glad.c)
include_directories(${INCLUDES})
add_executable(${PROJECT_NAME} ${SOURCEFILES})
link_directories(${INCLUDES}
    //${CMAKE_CURRENT_SOURCE_DIR}/libs/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/src
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/win/)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} glfw)
elseif(APPLE)
    find_library(COCOA_Framework Cocoa)
    find_library(OpenGL_Framework OpenGL)
    find_library(IOKit_Framework IOKit)
    find_library(CoreVideo_Framework CoreVideo)

    target_link_libraries(${PROJECT_NAME}
            glfw
            ${COCOA_Framework} ${OpenGL_Framework}
            ${IOKit_Framework} ${CoreVideo_Framework})
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME}
            glfw
            GL X11 pthread dl)
endif()
    #https://ps-group.github.io/cxx/cmake_cheatsheet
#https://habr.com/ru/post/461817/
# add_library(hello hello.cxx)

# if(WIN32)
#   target_sources(hello PRIVATE system_win.cxx)
# elseif(UNIX)
#   target_sources(hello PRIVATE system_posix.cxx)
# else()
#   target_sources(hello PRIVATE system_generic.cxx)
# endif()