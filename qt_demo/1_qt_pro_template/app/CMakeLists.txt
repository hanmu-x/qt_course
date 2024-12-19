
cmake_minimum_required(VERSION 3.5)

project(app LANGUAGES CXX)


# 添加可执行文件
add_executable(${PROJECT_NAME} "main.cpp")

# 依赖 core_lib 和 Qt::Widgets
target_link_libraries(${PROJECT_NAME} core_lib Qt${QT_VERSION_MAJOR}::Widgets)


