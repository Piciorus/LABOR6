cmake_minimum_required(VERSION 3.21)
project(LABOR6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(LABOR6
        CONTROLLER/Car_Controller.cpp
        CONTROLLER/Car_Controller.h
        CSV-FILE-REPOSITORY/CSVRepository.cpp
        CSV-FILE-REPOSITORY/CSVRepository.h
        DOMAIN/Car.cpp
        DOMAIN/Car.h
        IN-MEMORY/Car_Repository.cpp
        IN-MEMORY/Car_Repository.h
        REPOSITORY/CRUD-Repository.h
        UI/test.cpp
        UI/test.h
        UI/UI.cpp
        UI/UI.h
        QT/CustomTable.h
        QT/CustomTable.cpp
        App.cpp)
target_link_libraries(LABOR6
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    #    if (CMAKE_BUILD_TYPE MATCHES "Debug")
    #        set(DEBUG_SUFFIX "d")
    #    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


