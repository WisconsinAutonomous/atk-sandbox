cmake_minimum_required(VERSION 3.8)
project(wacore)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

#Declare the library

# https://stackoverflow.com/questions/11801186/cmake-unable-to-determine-linker-language-with-c
add_library(wacore INTERFACE)

target_include_directories(wacore
    PUBLIC
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(wacore
    ament_cmake
)

install(
    DIRECTORY include/
    DESTINATION include/${PROEJCT_NAME}
)

install(
    TARGETS
        wacore
    EXPORT export_wacore
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

#install (
#    DESTINATION share/${PROJECT_NAME}
#    )

# Export old-style CMake variables
ament_export_include_directories("include/${PROJECT_NAME}")
ament_export_libraries(wacore)

# Export modern CMake targets
ament_export_targets(export_wacore HAS_LIBRARY_TARGET)

ament_package()
