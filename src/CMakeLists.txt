
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

add_subdirectory(app)
add_subdirectory(core)