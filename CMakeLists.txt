cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME slots)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME}  main.cpp 
                                application.cpp 
                                window.cpp 
                                event.cpp 
                                point.cpp
                                rect.cpp
                                object.cpp)

add_subdirectory(lib/SDL2)


include_directories(lib/SDL2/include)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main)
endif()