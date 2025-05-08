cmake_minimum_required(VERSION 3.10)
project(onnxruntime_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set visibility settings
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fvisibility-inlines-hidden")
endif()

# Set the path to the ONNX Runtime static library
set(ONNXRUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/onnxruntime")

# Add the include directory
include_directories(${ONNXRUNTIME_DIR}/include)

# Add the executable
add_executable(onnxruntime_test main.cpp)

# Find required frameworks
find_library(FOUNDATION_LIBRARY Foundation REQUIRED)
find_library(COREFOUNDATION_LIBRARY CoreFoundation REQUIRED)

# Link against the static library and required frameworks
target_link_libraries(onnxruntime_test
    ${ONNXRUNTIME_DIR}/lib/libonnxruntime.a
    ${FOUNDATION_LIBRARY}
    ${COREFOUNDATION_LIBRARY}
) 