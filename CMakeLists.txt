cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME slots)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME}  src/main.cpp 
                                src/application.cpp 
                                src/window.cpp 
                                src/event.cpp 
                                src/point.cpp
                                src/rect.cpp
                                src/object.cpp
                                src/paintevent.cpp
                                src/mouseevent.cpp
                                src/graphicsobject.cpp
                                src/interactiveobject.cpp
                                src/painter.cpp
                                src/button.cpp
                                src/barrel.cpp
                                src/callbackevent.cpp
                                src/buttonclickevent.cpp
                                src/gamewindow.cpp
                                src/fpswidget.cpp
                                src/texture.cpp
                                src/texturemanager.cpp
                                src/fpsevent.cpp
                                src/animation.cpp)

add_subdirectory(lib/SDL2)


include_directories(lib/SDL2/include)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)

if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main)
endif()