# Minimum CMake Version
cmake_minimum_required(VERSION 3.10)

# Define Project Data
project("PVFDefaultEvents" VERSION 1.0 LANGUAGES CXX)

# Define Header Files (.h)
set(headers
        include/Utils.h
        include/EventHandler.h
)

# Define Source Files (.cpp)
set(sources
        src/Plugin.cpp
        src/EventHandler.cpp
)

# Dependencies
find_package(CommonLibSSE CONFIG REQUIRED)

# Create CLib Plugin
add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${headers} ${sources})

# Precompile Header
target_precompile_headers(${PROJECT_NAME} PRIVATE PCH.h)

# Define C++ Version as 23
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
