cmake_minimum_required(VERSION 3.17)
project(rimebrew)


#let qDebug dont output if on release mode.
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
else()
    add_compile_definitions(QT_NO_DEBUG_OUTPUT)
endif()

find_package(KF5Archive REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCE_FILES main.cpp first_run.cpp first_run.h first_run.ui)

add_executable(rimebrew ${SOURCE_FILES})
target_link_libraries(rimebrew PRIVATE KF5::Archive Qt5::Core Qt5::Widgets)

add_executable(yamlProcessor yaml_processor.cpp)
target_link_libraries(yamlProcessor yaml-cpp)

install(TARGETS rimebrew DESTINATION ${INSTALL_BIN_DIR})


#[[
Following dlls need to be copied for a win release.

Qt5Core.dll

libpcre2-16-0.dll
libstdc++-6.dll

libKF5Archive.dll
liblzma-5.dll
libzstd.dll
libbz2-1.dll
zlib1.dll

libdouble-conversion.dll

libicudt67.dll
libicuin67.dll
libicuuc67.dll
]]
