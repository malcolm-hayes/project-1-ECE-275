set( target FindGary )

set( sources
  ${CMAKE_CURRENT_SOURCE_DIR}/Cell.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Gary.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Board.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/FindGary.cpp )

add_executable( ${target} ${sources} )
