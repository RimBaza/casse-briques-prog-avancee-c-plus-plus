cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(casse-briques VERSION 1.0.0)

#add_executable(casse-briques src/test-sdl-all.cpp)

add_executable(casse-briques src/main.cpp src/main.h src/game/app.cpp src/game/app.h src/game/events_handler.cpp src/game/events_handler.h src/game/player.cpp src/game/player.h src/game/ball.cpp src/game/ball.h src/game/brick.cpp src/game/brick.h src/game/game_element.cpp src/game/game_element.h src/utils/sdl_utils.h src/utils/sdl_utils.cpp)

add_subdirectory(external/SDL-release-2.30.2)
add_subdirectory(external/SDL_image-release-2.8.2) 
add_subdirectory(external/SDL_ttf-release-2.22.0) 

target_link_libraries(casse-briques PRIVATE
  SDL2
  SDL2_image 
  SDL2_ttf 
)

if (WIN32)
  target_link_libraries(
    casse-briques PRIVATE SDL2main
  )
endif()

add_custom_command(
  TARGET casse-briques POST_BUILD COMMAND
  ${CMAKE_COMMAND} -E copy_if_different
    "$<TARGET_FILE:SDL2>"
    "$<TARGET_FILE:SDL2_image>" 
    "$<TARGET_FILE:SDL2_ttf>" 
    "$<TARGET_FILE_DIR:casse-briques>"
  VERBATIM
)