cmake_minimum_required(VERSION 2.4)

project(PGMLib)

# output type
# If you want to build as a shared lib, uncomment the below
# set(BUILD_SHARED_LIBS ON)

# build type
# set to Release for optimization and if you don't require symbols
# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE RelWithDebInfo )

# output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# compiler selection
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99") #c++ compiler
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")       #c compiler

# pgm handling
set(PGM
        src/pgm/pgm.c src/pgm/pgm.h)

# filter collection
set(FILTER
        src/filter/filter.c src/filter/filter.h 
		src/filter/linear/blurFilter.c src/filter/linear/blurFilter.h 
		src/filter/linear/sharpFilter.c src/filter/linear/sharpFilter.h
        src/filter/linear/normalizeFilter.c src/filter/linear/normalizeFilter.h
        src/filter/nonlinear/minFilter.c src/filter/nonlinear/minFilter.h 
		src/filter/nonlinear/maxFilter.c src/filter/nonlinear/maxFilter.h
        src/filter/nonlinear/medianFilter.c src/filter/nonlinear/medianFilter.h 
		src/filter/nonlinear/thresholdFilter.c src/filter/nonlinear/thresholdFilter.h
        src/filter/nonlinear/quantizeFilter.c src/filter/nonlinear/quantizeFilter.h
        src/filter/edge/sobelFilter.c src/filter/edge/sobelFilter.h 
		src/filter/edge/prewittFilter.c src/filter/edge/prewittFilter.h 
		src/filter/edge/robertsFilter.c src/filter/edge/robertsFilter.h
        src/filter/edge/cannyFilter.c src/filter/edge/cannyFilter.h
        src/filter/edge/nmsFilter.c src/filter/edge/nmsFilter.h 
		src/filter/edge/edgeFilter.c src/filter/edge/edgeFilter.h)

# build lib
add_library(PGMLib ${PGM} ${FILTER})
if(UNIX)
	target_link_libraries(PGMLib m)
endif(UNIX)


# build examples
add_executable(echo example/echo.c)
target_link_libraries(echo PGMLib)

add_executable(blur example/blur.c)
target_link_libraries(blur PGMLib)

add_executable(sharpen example/sharpen.c)
target_link_libraries(sharpen PGMLib)

add_executable(median example/median.c)
target_link_libraries(median PGMLib)

add_executable(edges example/edges.c)
target_link_libraries(edges PGMLib)


# build tests