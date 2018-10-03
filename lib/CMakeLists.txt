#
# Copyright (c) 2018 Bogdan-Constantin Popescu
# Use, modification and distribution are subject to the MIT license.
# See accompanying file LICENSE or copy at:
# https://github.com/MathPlayer/project-euler/blob/master/LICENSE
#

absolute_prefix_path(include_files ""
  Solve.hpp
  )

absolute_prefix_path(source_files ""
  Solve001.cpp
  Solve002.cpp
  )

add_library(solver ${source_files})
target_include_directories(solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_cpplint_command(solver ${source_files} ${include_files})
