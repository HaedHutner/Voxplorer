cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_NAME Voxplorer)

project(${PROJECT_NAME})

set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
        ${PROJECT_NAME}
        ${PROJECT_SRC_DIR}/main.cpp
        src/engine/Game.cpp src/engine/Game.h src/engine/GameState.h)

set(PROJECT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(PROJECT_BIN ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# GLFW
set(GLFW_DIR ${PROJECT_LIB}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(${GLFW_DIR})

target_link_libraries(${PROJECT_NAME} "glfw" ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)

#GLAD
set(GLAD_DIR ${PROJECT_LIB}/glad)
add_library("glad" ${GLAD_DIR}/src/glad.c)

target_include_directories("glad" PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
target_link_libraries(${PROJECT_NAME} "glad" ${CMAKE_DL_LIBS})

#GLM
set(GLM_DIR ${PROJECT_LIB}/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_DIR})

#FastNoise
set(FAST_NOISE_DIR ${PROJECT_LIB}/FastNoise)
add_library("fastnoise" ${FAST_NOISE_DIR}/FastNoise.h ${FAST_NOISE_DIR}/FastNoise.cpp src/game/Voxplorer.cpp src/game/Voxplorer.h)

target_include_directories("fastnoise" PRIVATE ${FAST_NOISE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${FAST_NOISE_DIR})
target_link_libraries(${PROJECT_NAME} "fastnoise" ${CMAKE_DL_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SRC_DIR})