cmake_minimum_required (VERSION 2.6)

#default compiler flags
SET( CMAKE_BUILD_TYPE RELEASE CACHE STRING "A variable which controls the type of build" )
SET( CMAKE_CXX_FLAGS_RELEASE "-Wextra -Wall -O2" CACHE STRING "" )
SET( CMAKE_C_FLAGS_RELEASE "-Wextra -Wall -O2" CACHE STRING "" )
SET( CMAKE_CXX_FLAGS_DEBUG "-Wextra -Wall -g3 -O0" CACHE STRING "" )
SET( CMAKE_C_FLAGS_DEBUG "-Wextra -Wall -g3 -O0" CACHE STRING "" )

project ("algorithms")
# The version numer.
set(ALGO_VERSION 0.1)

SET(BUILD_STATIC OFF CACHE BOOL "choose between static or dynamic linking")

# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH FALSE)
# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

IF (BUILD_STATIC)
	SET( LINKING_MODE STATIC)
ELSE (BUILD_STATIC)
	SET( LINKING_MODE SHARED)
ENDIF (BUILD_STATIC)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(
	"/opt/local/lib"
	"/usr/local/lib"
)

# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")

# add_library(algo_impl algorithm.h)
add_executable(algorithms algo_test.cc algorithm.h)
# target_link_libraries(algorithms algo_impl)
