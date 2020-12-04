cmake_minimum_required(VERSION 3.17)
project(Curl)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Set this to the minimal version you want to support
find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
file(COPY data DESTINATION ${CMAKE_BINARY_DIR})
include(FetchContent)
set(BUILD_EXAMPLES FALSE)
if (NOT raylib_FOUND)

    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 3.0.0
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_SHARED_LIBS ON)
        #set(SUPPORT_HIGH_DPI ON)
        set(BUILD_EXAMPLES OFF)
        set(SUPPORT_CAMERA_SYSTEM OFF)
        set(SUPPORT_VR_SIMULATOR OFF)
        set(SUPPORT_DISTORTION_SHADER OFF)
        set(SUPPORT_IMAGE_GENERATION OFF)
        set(SUPPORT_FILEFORMAT_DDS OFF)
        set(SUPPORT_FILEFORMAT_HDR OFF)
        set(SUPPORT_FILEFORMAT_KTX OFF)
        set(SUPPORT_FILEFORMAT_ASTC OFF)
        set(SUPPORT_FILEFORMAT_OBJ OFF)
        set(SUPPORT_FILEFORMAT_MTL OFF)
        set(SUPPORT_MESH_GENERATION OFF)
        set(SUPPORT_FILEFORMAT_GIF ON)
        set(USE_AUDIO ON)
        set(SUPPORT_SCREEN_CAPTURE OFF)
        set(SUPPORT_GIF_RECORDING OFF)

        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()
set(WANT_ZLIB FALSE)


add_executable(Impostor main.c src/graphsLib.c src/impostorLib.c src/mechanicsLib.c src/test.c)
if (WIN32)
    target_link_libraries(Impostor raylib)
elseif (APPLE)
    target_link_libraries(Impostor raylib pthread)
else()
    target_link_libraries(Impostor raylib GL X11 glfw pthread)
endif()