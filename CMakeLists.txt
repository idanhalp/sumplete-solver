cmake_minimum_required(VERSION 3.16)

project(SumpleteSolverQt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(WARNING_FLAGS "-Wall -Wextra")
set(OPTIMIZATION_LEVEL -O0)
set(CMAKE_CXX_FLAGS "${WARNING_FLAGS} ${OPTIMIZATION_LEVEL}")

# Project files.
# Files' paths mst relative to the root.

set(BACKEND_FILES

    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version1/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version1/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/Trie/Trie.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/Trie/Trie.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Parameters.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/ValidityChecks/ValidityChecks.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/ValidityChecks/ValidityChecks.hpp
)

set(FRONTEND_FILES

    ${CMAKE_SOURCE_DIR}/Source/Frontend/Main.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/MainModule/MainModule.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/MainModule/MainModule.hpp
)

set(QML_FILES

    Source/Frontend/Components/ClearButton.qml
    Source/Frontend/Components/ColsSums.qml
    Source/Frontend/Components/Description.qml
    Source/Frontend/Components/Grid.qml
    Source/Frontend/Components/GridSizeDropdown.qml
    Source/Frontend/Components/Popups/ErrorPopup.qml
    Source/Frontend/Components/Popups/IncompleteInputPopup.qml
    Source/Frontend/Components/Popups/NoSolutionPopup.qml
    Source/Frontend/Components/Popups/Popups.qml
    Source/Frontend/Components/RowsSums.qml
    Source/Frontend/Components/SolveButton.qml
    Source/Frontend/Main.qml
)

set(TEST_FILES

    ${CMAKE_SOURCE_DIR}/Tests/Backend/Algorithm/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/Algorithm/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/Algorithm/Version2/Trie/Trie.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/Algorithm/Version2/Trie/Trie.hpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp
    ${CMAKE_SOURCE_DIR}/Tests/Main.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/ValidityChecks/ValidityChecks.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Backend/ValidityChecks/ValidityChecks.hpp
)

qt_add_executable(SumpleteSolverApp

    ${BACKEND_FILES}
    ${FRONTEND_FILES}
)

qt_add_executable(Test

    ${BACKEND_FILES}
    ${TEST_FILES}
)

target_include_directories(SumpleteSolverApp PRIVATE
    ${CMAKE_SOURCE_DIR} # Addresses should be relative to the root.
    ${CMAKE_SOURCE_DIR}/Source/Frontend/MainModule
)

target_include_directories(Test PRIVATE
    ${CMAKE_SOURCE_DIR}
)

qt_add_qml_module(SumpleteSolverApp
    URI SumpleteSolverQt
    VERSION 1.0
    QML_FILES
	${QML_FILES}

    # C++ files that should be converted to QML using the QML_ELEMENT macro.
    SOURCES
	Source/Frontend/MainModule/MainModule.cpp
	Source/Frontend/MainModule/MainModule.hpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(SumpleteSolverApp Test PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SumpleteSolverApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(SumpleteSolverApp
    PRIVATE Qt6::Quick Qt6::qtquickcontrols2plugin
)

target_link_libraries(Test
    PRIVATE Qt6::Test
)

include(GNUInstallDirs)
install(TARGETS SumpleteSolverApp Test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
