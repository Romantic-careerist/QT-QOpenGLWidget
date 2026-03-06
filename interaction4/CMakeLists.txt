cmake_minimum_required(VERSION 3.19)
project(interaction1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)

qt_standard_project_setup()

qt_add_executable(interaction1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    axbopenglwidget.h axbopenglwidget.cpp
)

target_link_libraries(interaction1
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(interaction1
    PRIVATE
    Qt6::OpenGLWidgets
)

include(GNUInstallDirs)

install(TARGETS interaction1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET interaction1

    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
