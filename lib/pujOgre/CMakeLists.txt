file(GLOB _lib_src "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")

include_directories(
  ${OIS_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(pujOgre SHARED ${_lib_src})
target_link_libraries(pujOgre ${OGRE_LIBRARIES} ${OIS_LIBRARIES})