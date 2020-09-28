cmake_minimum_required(VERSION 3.2)
project(cmake VERSION 0.0.1$ENV{TRAVIS_BUILD_NUMBER})

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/libs/)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

set(CMAKE_CXX_STANDARD 14)

add_executable(otstart main.cpp )

add_library(otstart_dll lib.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(otstart otstart_dll test_version PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(otstart
        otstart_dll
        Threads::Threads
        )
target_link_libraries(test_version
        ${Boost_LIBRARIES}
        otstart_dll
        )
target_link_libraries(test_version
        ${Boost_LIBRARIES}
        otstart_dll
        )

install(TARGETS otstart RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT yarakaeff@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(otstart_tests test_version)


