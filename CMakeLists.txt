cmake_minimum_required(VERSION 3.26)
project(OpenURLTool)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_PREFIX_PATH "D:/Qt5/Qt5.13.2/5.13.2/mingw73_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OpenURLTool Sources/main.cpp
        Sources/Module/mainwindow.cpp
        Sources/Headers/mainwindow.h
        Sources/Forms/mainwindow.ui
        Sources/Headers/PopupTemplate.h
        Sources/Module/InfoPopup.cpp
        Sources/Headers/InfoPopup.h
        Sources/Module/ErrorPopup.cpp
        Sources/Headers/ErrorPopup.h
        Sources/Module/AskPopup.cpp
        Sources/Headers/AskPopup.h
        Sources/Module/WarningPopup.cpp
        Sources/Headers/WarningPopup.h
        Sources/Headers/Popup.h
        Sources/Module/InputListDiaLog.cpp
        Sources/Headers/InputListDiaLog.h
        Sources/Module/BrowserDiaLog.cpp
        Sources/Headers/BrowserDiaLog.h)

set(LOG_FILE "${PROJECT_SOURCE_DIR}/logs/build.log")

execute_process(
        COMMAND ${CMAKE_COMMAND} -E echo "Build output for ${CMAKE_PROJECT_NAME}" >> ${LOG_FILE}
        COMMAND ${CMAKE_COMMAND} -E echo "--------------------------------------" >> ${LOG_FILE}
        COMMAND ${CMAKE_COMMAND} -E echo "" >> ${LOG_FILE}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always" CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fdiagnostics-color=always" CACHE STRING "" FORCE)

set(CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} 2>&1 | tee -a ${LOG_FILE}")

target_link_libraries(OpenURLTool
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
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

include_directories(Sources)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/images)
file(COPY ${RESOURCES_DIR} DESTINATION ${EXECUTABLE_OUTPUT_PATH})

execute_process(
        COMMAND ${CMAKE_COMMAND} -E echo "" >> ${LOG_FILE}
        COMMAND ${CMAKE_COMMAND} -E echo "--------------------------------------" >> ${LOG_FILE}
)
