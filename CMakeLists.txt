cmake_minimum_required(VERSION 3.16)
project(Calc LANGUAGES CXX)

# 设置 C++17 标准，并启用 Qt 的自动 MOC/UIC/RCC
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 Qt6 的必需模块（Core, Gui, Widgets）
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# windows10以上支持
add_definitions(-D_WIN32_WINNT=0x0A00)
add_definitions(-DWINVER=0x0A00)

# 添加可执行文件，列出所有源文件和 .ui 文件
qt_add_executable(Calc
    src/main.cpp
    src/uiCalc.cpp
    include/uiCalc.h
    include/uiCalc.ui
)

# 链接 Qt 库
target_link_libraries(Calc PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core dwmapi)