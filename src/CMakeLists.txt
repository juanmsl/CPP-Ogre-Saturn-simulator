include_directories(
  ${OIS_INCLUDE_DIRS}
  ${OGRE_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/lib
  ${PROJECT_BINARY_DIR}/lib
)

SET(MODEL_LIBRARIES
  model/app.cxx
  model/ball.cxx
)

file(GLOB MODEL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/model/*.c*")
file(GLOB VIEW_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/view/*.c*")
file(GLOB CONTROLLER_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/controller/*.c*")
file(GLOB UTILITY_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/utilities/*.c*")

add_executable(simulator main.cxx ${MODEL_LIBRARIES} ${VIEW_LIBRARIES} ${CONTROLLER_LIBRARIES} ${UTILITY_LIBRARIES})
target_link_libraries(simulator pujOgre)