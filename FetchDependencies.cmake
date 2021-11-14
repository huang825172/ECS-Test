# Fetch and test project dependencies
#   googletest: unit testing
#   glfw: OpenGL context and input management
#   glad: OpenGL API Loader
#   libuv: Event system with networking features
#   openal-soft: Software implementation of OpenAL
#   freealut: OpenAL API Wrapper
#   SPIR-V: use glslangValidator to compile glsl file
include(FetchContent)

# Get googletest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# Get glfw
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
)
FetchContent_MakeAvailable(glfw)

# Add glad
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC include)

# Get libuv
FetchContent_Declare(
        libuv
        GIT_REPOSITORY https://github.com/libuv/libuv.git
)
FetchContent_MakeAvailable(libuv)

# Add openal-soft
FetchContent_Declare(
        openalsoft
        GIT_REPOSITORY https://github.com/kcat/openal-soft.git
)
FetchContent_MakeAvailable(openalsoft)
set(OPENAL_LIBRARY OpenAL)
set(OPENAL_INCLUDE_DIR ${openalsoft_SOURCE_DIR}/include)

# Add freealut
FetchContent_Declare(
        freealut
        GIT_REPOSITORY https://github.com/vancegroup/freealut.git
)
FetchContent_MakeAvailable(freealut)
include_directories(${freealut_SOURCE_DIR}/include)

# Add bullet physics SDK
# FetchContent_Declare(
#         bullet3
#         GIT_REPOSITORY https://github.com/bulletphysics/bullet3.git
# )
# FetchContent_MakeAvailable(bullet3)