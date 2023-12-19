# find_package(GTest REQUIRED)
# add_executable(liblog_test loblog_test.cpp)

# target_include_directories(liblog_test PUBLIC${GTEST_INCLUDE_DIRS})

# target_link_libraries(liblog_test PRIVATE
#         ${GTEST_LIBRARIES}
#         ${GTEST_MAIN_LIBRARIES}
# )

# add_test(liblog_test liblog_test)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        URL_HASH SHA256=1f357c27ca988c3f7c6b4bf68a9395005ac6761f034046e9dde0896e3aba00e4
)

#set(gtest_force_shared_crt OFF CACHE BOOL "" FORCE)
# Force Google Test to link the C/C++ runtimes dynamically when
# building on Visual Studio
# Link:
# * https://github.com/google/googletest/tree/release-1.8.1/googletest#visual-studio-dynamic-vs-static-runtimes
if (MSVC)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Fetch GoogleTest amd make build scripts available
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

set(TEST_NAME LibLogTests)
add_executable(${TEST_NAME} liblog_test.cpp)
target_link_libraries(${TEST_NAME} PRIVATE lib gtest_main)
gtest_discover_tests(${TEST_NAME})
