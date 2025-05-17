cmake_minimum_required(VERSION 3.16)
project(Calc LANGUAGES CXX)

# 设置 C++17 标准，并启用 Qt 的自动 MOC/UIC/RCC
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 加入QtWin 库
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/QtWin")
set(QtWin_DIR ${CMAKE_CURRENT_SOURCE_DIR}/QtWin/library/cmake/QtWin)
find_package(QtWin 0.0.1 REQUIRED)

# 查找 Qt6 的必需模块（Core, Gui, Widgets）
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# windows10以上支持
add_definitions(-D_WIN32_WINNT=0x0A00)
add_definitions(-DWINVER=0x0A00)
# 添加可执行文件，列出所有源文件和 .ui 文件
qt_add_executable(Calc
    src/main.cpp
    src/uiCalc.cpp
    src/uiMain.cpp
    include/uiCalc.h
    include/uiCalc.ui
    include/uiMain.h
    include/uiMain.ui
)

# 链接 Qt 库
target_link_libraries(Calc PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core dwmapi)
target_link_libraries(Calc PRIVATE QtWin::QtWin)

add_custom_command(TARGET Calc POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/QtWin/library/libQtWin.dll"
        "$<TARGET_FILE_DIR:Calc>"
    COMMENT "Copying libQtWin.dll to executable directory."
)