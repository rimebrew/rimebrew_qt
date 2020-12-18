cmake_minimum_required(VERSION 3.17)
project(rimebrew)

set(SOURCE_FILES main.cpp)

find_package(KF5Archive REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(helloCpp ${SOURCE_FILES})
target_link_libraries(helloCpp KF5::Archive)

install(TARGETS helloCpp DESTINATION ${INSTALL_BIN_DIR})


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
