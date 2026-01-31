cmake_minimum_required(VERSION 3.10)
project(WeedMenCheat)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the DLL
add_library(WeedMenCheat SHARED
    SOURCE_TEMPLATE.cpp
)

# Link DirectX 11
target_link_libraries(WeedMenCheat
    d3d11
)

# Set output directory
set_target_properties(WeedMenCheat PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# For Release builds, use static runtime
if(MSVC)
    set_property(TARGET WeedMenCheat PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Installation rules (optional)
install(TARGETS WeedMenCheat
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
