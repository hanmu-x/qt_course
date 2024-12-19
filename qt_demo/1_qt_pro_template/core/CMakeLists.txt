cmake_minimum_required(VERSION 3.5)

project(core_lib LANGUAGES CXX)

# 搜索 core 目录下的所有源文件和头文件
file(GLOB_RECURSE CORE_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.ui"
    "${PROJECT_SOURCE_DIR}/ui/*.ui"  # 指向根目录下的ui目录中的 .ui 文件
)

# 添加库
add_library(${PROJECT_NAME} STATIC ${CORE_SRC})

# 依赖 ui_src 和 Qt::Widgets
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)


