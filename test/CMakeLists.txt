#
# Copyright (c) 2018 Bogdan-Constantin Popescu
# Use, modification and distribution are subject to the MIT license.
# See accompanying file LICENSE or copy at:
# https://github.com/MathPlayer/project-euler/blob/master/LICENSE
#

project(PROJECT_EULER_TEST)

enable_testing()

absolute_prefix_path(source_files .
  MainTest.cpp
  Test001.cpp
  Test002.cpp
  )

add_executable(solver-test ${source_files})
target_link_libraries(solver-test solver)

add_cpplint_command(solver-test ${source_files})

# Automatically use add_test for tests defined with Catch
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CONAN_RES_DIRS_CATCH2})
include(ParseAndAddCatchTests)
ParseAndAddCatchTests(solver-test)
