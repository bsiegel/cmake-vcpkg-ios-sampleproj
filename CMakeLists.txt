cmake_minimum_required(VERSION 3.19)
project(sampleproj LANGUAGES CXX)
#include($ENV{HOME}/vcpkg/scripts/buildsystems/vcpkg.cmake)

add_executable(main main.cpp)
set_property(TARGET main PROPERTY OUTPUT_NAME main)
target_compile_features(main PRIVATE cxx_std_20)

find_package(azure-identity-cpp CONFIG REQUIRED)
find_package(azure-storage-blobs-cpp CONFIG REQUIRED)
target_link_libraries(main PRIVATE Azure::azure-identity Azure::azure-storage-blobs)

