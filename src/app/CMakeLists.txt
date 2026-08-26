find_package(SFML CONFIG REQUIRED COMPONENTS system window graphics)

# Linden dependency
include (FetchContent)

FetchContent_Declare(
    linden
    GIT_REPOSITORY
        https://github.com/DarylStark/linden-lib-cpp-linden.git
    GIT_TAG
        dev   # TODO: Migrate to a stable release of linden when available
)
FetchContent_MakeAvailable(linden)

file(GLOB APP_SOURCES CONFIGURE_DEPENDS *.cpp **/*.cpp **/**/*.cpp)
add_executable(pomodoro ${APP_SOURCES})

target_link_libraries(pomodoro PRIVATE
    linden::linden
    SFML::System
    SFML::Window
    SFML::Graphics
)
