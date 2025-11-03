cmake_minimum_required(VERSION 3.10)
project(YoVoy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recursively collect all .cpp files
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/app/*.cpp"
    "${PROJECT_SOURCE_DIR}/controllers/*.cpp"
    "${PROJECT_SOURCE_DIR}/models/*.cpp"
    "${PROJECT_SOURCE_DIR}/services/*.cpp"
    "${PROJECT_SOURCE_DIR}/utils/*.cpp"
)

# Include header directories
include_directories(
    "${PROJECT_SOURCE_DIR}/app"
    "${PROJECT_SOURCE_DIR}/controllers"
    "${PROJECT_SOURCE_DIR}/models"
    "${PROJECT_SOURCE_DIR}/services"
    "${PROJECT_SOURCE_DIR}/utils"
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})