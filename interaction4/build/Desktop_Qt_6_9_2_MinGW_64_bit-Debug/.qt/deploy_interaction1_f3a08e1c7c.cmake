include("D:/soft/QTproject/OpenGL/interaction1/build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/interaction1-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/soft/QTproject/OpenGL/interaction1/build/Desktop_Qt_6_9_2_MinGW_64_bit-Debug/interaction1.exe"
    GENERATE_QT_CONF
)
