cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(TDDSoundex)

# Enable testing
include(CTest)

# See if boost is installed
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARY_DIRS ${Boost_LIBRARY_DIRS}")
    message(STATUS "Boost_LIBRARIES ${Boost_LIBRARIES}")
    include_directories(
            ${Boost_INCLUDE_DIRS}
            ${Boost_LIBRARY_DIRS})
    # Compile options for Boost
    add_compile_options(-lunit_test_framework)
endif()

# Include sources before tests
add_subdirectory(source)
add_subdirectory(tests)