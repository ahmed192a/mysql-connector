cmake_minimum_required(VERSION 3.20)
# set(CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(myapp)

# # find mysql connector package
# find_package(unofficial-mysql-connector-cpp CONFIG REQUIRED)

# message(STATUS "Found mysql connector package which is ${unofficial-mysql-connector-cpp_FOUND}")
# # print the config file path
# message(STATUS "Found mysql connector package config file which is ${unofficial-mysql-connector-cpp_DIR}")


add_executable(myapp main.cpp)
target_link_directories(
    myapp
    PUBLIC
    ${CMAKE_SOURCE_DIR}/x64-linux/lib
)
target_link_libraries(
    myapp
    PRIVATE    
    mysqlcppconn8-static
    pthread
    resolv
)

target_include_directories(
    myapp
    PUBLIC
    # ${CMAKE_BINARY_DIR}/vcpkg_installed/x64-linux/include
    ${CMAKE_SOURCE_DIR}/x64-linux/include
)
message(STATUS "${CMAKE_BUILD_TYPE} mode")


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(myapp PUBLIC DEBUG)

    # if debug move the executable to the Debug folder



    # add cunstom command to run the executable "make run"
    # add_custom_target(run
    #     COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/myapp
    #     DEPENDS myapp
    #     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}
    # )

else()
    # message(STATUS "Release mode")
    target_compile_definitions(myapp PUBLIC RELEASE)

    # if release move the release the executable to the Release folder
    # set_target_properties(myapp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Release)






    # add cunstom command to run the executable "make run"
    # add_custom_target(run
    #     COMMAND ${CMAKE_BINARY_DIR}/Release/myapp
    #     DEPENDS myapp
    #     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Release
    # )
endif()


set_target_properties(myapp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
add_custom_target(run
COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/myapp
DEPENDS myapp
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}
)



# command for configure cmake in release mode
# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
# command for build project
# cmake --build build

