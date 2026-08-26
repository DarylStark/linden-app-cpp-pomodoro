find_package(SFML CONFIG REQUIRED COMPONENTS system window graphics)

file(GLOB APP_SOURCES CONFIGURE_DEPENDS *.cpp **/*.cpp **/**/*.cpp)
add_executable(pomodoro ${APP_SOURCES})

target_link_libraries(
    pomodoro
    PRIVATE
        linden::linden
        SFML::System
        SFML::Window
        SFML::Graphics
        pomodoro_core
)
