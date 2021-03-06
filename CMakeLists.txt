cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME Voxplorer)

project(${PROJECT_NAME})

set(PROJECT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_SHADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/shader)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp
        src/engine/Camera.cpp
        src/engine/Camera.h
        src/engine/Game.cpp
        src/engine/Game.h
        src/engine/GameState.h
        src/engine/ShaderProgram.cpp
        src/engine/ShaderProgram.h
        src/engine/Mesh.cpp
        src/engine/Mesh.h
        src/engine/Vertex.hpp
        src/engine/Renderer.h
        src/engine/Renderable.h
        src/engine/Keyboard.cpp
        src/engine/Keyboard.h
        src/game/Voxplorer.cpp
        src/game/Voxplorer.h
        src/game/state/IdleGameState.cpp
        src/game/state/IdleGameState.h
        src/game/state/GenerateSingleVoxelChunkState.cpp
        src/game/state/GenerateSingleVoxelChunkState.h
        src/game/state/MarchingCubesBenchmarkState.cpp
        src/game/state/MarchingCubesBenchmarkState.h
        src/game/world/VoxelChunk.cpp
        src/game/world/VoxelChunk.h
        src/game/world/Voxel.cpp
        src/game/world/Voxel.h
        src/game/world/VoxelGenerator.cpp
        src/game/world/VoxelGenerator.h
        src/game/world/VoxelField.h
        src/game/world/VoxelWorld.cpp
        src/game/world/VoxelWorld.h
        src/game/logic/MarchingCubes.cpp
        src/game/logic/MarchingCubes.h
        src/game/render/VoxelWorldRenderer.h
        src/game/render/VoxelWorldRenderer.cpp
        src/game/render/VoxelChunkRenderer.h
        src/game/render/VoxelChunkRenderer.cpp
        src/game/world/VoxelChunkMap.hpp src/game/util/Vec3Map.h)

set(PROJECT_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(PROJECT_BIN ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# GLFW
set(GLFW_DIR ${PROJECT_LIB}/glfw)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

add_subdirectory(${GLFW_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_DIR}/include)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})

# GLAD
set(GLAD_DIR ${PROJECT_LIB}/glad)
add_library("glad" ${GLAD_DIR}/src/glad.c)

target_include_directories("glad" PRIVATE ${GLAD_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLAD_DIR}/include)
target_link_libraries(${PROJECT_NAME} "glad" ${CMAKE_DL_LIBS})

# GLM
set(GLM_DIR ${PROJECT_LIB}/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLM_DIR})

# FastNoise
set(FAST_NOISE_DIR ${PROJECT_LIB}/FastNoise)
add_library("fastnoise" ${FAST_NOISE_DIR}/FastNoise.h ${FAST_NOISE_DIR}/FastNoise.cpp)

target_include_directories("fastnoise" PRIVATE ${FAST_NOISE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${FAST_NOISE_DIR})
target_link_libraries(${PROJECT_NAME} "fastnoise" ${CMAKE_DL_LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SRC_DIR})

# file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/res)
file(COPY ${PROJECT_SHADER_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res)