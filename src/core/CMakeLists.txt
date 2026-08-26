file(GLOB POMODORO_CORE_SOURCES CONFIGURE_DEPENDS *.cpp **/*.cpp **/**/*.cpp)
add_library(pomodoro_core ${POMODORO_CORE_SOURCES})

target_include_directories(
    pomodoro_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/)

target_link_libraries(
    pomodoro_core
    PUBLIC
        linden::linden
)