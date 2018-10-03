#
# Copyright (c) 2018 Bogdan-Constantin Popescu
# Use, modification and distribution are subject to the MIT license.
# See accompanying file LICENSE or copy at:
# https://github.com/MathPlayer/project-euler/blob/master/LICENSE
#

cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(PROJECT_EULER)

# Add cpplint as a custom command to run for a given target.
function(add_cpplint_command target)
  # Cpplint root is a relative path to the root of the repository.
  file(RELATIVE_PATH root ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
  add_custom_command(
    TARGET ${target} PRE_BUILD VERBATIM
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Run cpplint for target ${target} ..."
    COMMAND
      cpplint --linelength=80 --filter=+build/c++14,-runtime/references
      --root=${root} ${ARGN})
endfunction(add_cpplint_command)


# Create absolute path for a list of files, prefixing it with the given prefix.
function(absolute_prefix_path variable prefix)
  set(tmp_list "")
  foreach(arg ${ARGN})
    get_filename_component(
      tmp_file ${CMAKE_CURRENT_SOURCE_DIR}/${prefix}/${arg} ABSOLUTE)
    list(APPEND tmp_list ${tmp_file})
  endforeach()
  set(${variable} ${tmp_list} PARENT_SCOPE)
endfunction(absolute_prefix_path)


# Conan configuration
execute_process(
  COMMAND conan install ${CMAKE_SOURCE_DIR}
    -s compiler=clang
    -s compiler.libcxx=libc++
    -s cppstd=14

  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

set(CONAN_SYSTEM_INCLUDES ON)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()
conan_basic_setup()

# Project configuration
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CPPCHECK cppcheck --std=c++14)

# Build solver
add_subdirectory(lib)

# Build tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()
