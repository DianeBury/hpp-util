# Copyright (C) 2010 Florent Lamiraux, Thomas Moulard, JRL, CNRS/AIST.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Path to boost headers
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# DEFINE_TEST(NAME)
# -----------------
#
# Compile a program and add it as a test.
#
MACRO(DEFINE_TEST NAME LIB)
  ADD_EXECUTABLE(${NAME} ${NAME}.cc)

  TARGET_LINK_LIBRARIES(${NAME} hpp-util)

  # Link against Boost.
  TARGET_LINK_LIBRARIES(${NAME} ${Boost_LIBRARIES})

  ADD_TEST(NAME ${NAME} COMMAND ${RUNTIME_OUTPUT_DIRECTORY}/${NAME})
ENDMACRO(DEFINE_TEST)


# Define tests.
DEFINE_TEST(simple-test hpp-util)
DEFINE_TEST(assertion hpp-util)
DEFINE_TEST(exception hpp-util)
DEFINE_TEST(exception-factory hpp-util)
DEFINE_TEST(timer hpp-util)

SET(HPP_LOGGINGDIR "${CMAKE_CURRENT_BINARY_DIR}")
CONFIG_FILES(run_debug.sh)
ADD_EXECUTABLE(debug debug.cc)
TARGET_LINK_LIBRARIES(debug hpp-util ${Boost_LIBRARIES})
ADD_TEST(NAME debug COMMAND ${RUNTIME_OUTPUT_DIRECTORY}/run_debug.sh)
