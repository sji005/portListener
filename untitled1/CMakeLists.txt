cmake_minimum_required(VERSION 3.16)

project(untitled1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 6.4 REQUIRED COMPONENTS SerialPort)
qt_standard_project_setup()

qt_add_executable(appuntitled1
    main.cpp
    portcontroller.h
    portcontroller.cpp
)

qt_add_qml_module(appuntitled1
    URI untitled1
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES MySendPage.qml
        QML_FILES MyGraphPage.qml
        QML_FILES ComPlat.qml
        QML_FILES MyPrePage.qml
        QML_FILES MyHelpPage.qml
        QML_FILES MyAboutPage.qml
        QML_FILES Tcps.qml
        QML_FILES TcpcUdp.qml
        SOURCES portcontroller.h portcontroller.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appuntitled1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appuntitled1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appuntitled1
    PRIVATE Qt6::Quick
)

target_link_libraries(appuntitled1 PRIVATE Qt6::SerialPort)

include(GNUInstallDirs)
install(TARGETS appuntitled1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
