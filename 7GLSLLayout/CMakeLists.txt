cmake_minimum_required(VERSION 3.19)
project(GLSLLayout LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)   # 启用自动处理 .qrc 文件

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets OpenGLWidgets)

qt_standard_project_setup()

qt_add_executable(GLSLLayout
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    axbopenglwidget.h
    axbopenglwidget.cpp
    res.qrc               # 将 .qrc 文件加入源文件列表
)

target_link_libraries(GLSLLayout
    PRIVATE
    Qt::Core
    Qt::Widgets
    Qt::OpenGLWidgets      # 正确链接 OpenGLWidgets 模块
)

include(GNUInstallDirs)

install(TARGETS GLSLLayout
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GLSLLayout
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
