cmake_minimum_required(VERSION 3.16)
project(EnhancedBacktestEngine VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Engine sources
file(GLOB ENGINE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# App sources
file(GLOB APP_SOURCES
    ${PROJECT_SOURCE_DIR}/app/*.cpp
)

# Create executable
add_executable(backtest ${ENGINE_SOURCES} ${APP_SOURCES})

# Optional: enable warnings
if (MSVC)
    target_compile_options(backtest PRIVATE /W4 /permissive-)
else()
    target_compile_options(backtest PRIVATE -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()
