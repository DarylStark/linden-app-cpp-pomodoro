cmake_minimum_required(VERSION 3.20)
project(
    linden-pomodoro
    VERSION
        0.0.1
    LANGUAGES
        CXX
)

# C++ Configuration
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Application source
add_subdirectory(src)