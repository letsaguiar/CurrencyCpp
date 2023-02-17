include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

########### InitTest ###########

add_executable(
    InitTest
    init/init_test.cc
    ../source/currency.hpp
    ../source/init/init.cpp
)

target_include_directories(
    InitTest
    PRIVATE ../source
)

target_link_libraries(
    InitTest
    gtest_main
)

########### AddTest ###########

add_executable(
    AddTest
    add/add_test.cc
    ../source/currency.hpp
    ../source/add/add.cpp
)

target_include_directories(
    AddTest
    PRIVATE ../source
)

target_link_libraries(
    AddTest
    gtest_main
)

########### gtest_discover ###########

include(GoogleTest)
gtest_discover_tests(
    InitTest
)