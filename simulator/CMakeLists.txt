file(GLOB SIMULATOR_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.c*")

include_directories(
  ${OIS_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/lib/pujOgre/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(sim main.cxx ${SIMULATOR_SRC})
target_link_libraries(sim pujOgre)