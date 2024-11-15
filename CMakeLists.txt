cmake_minimum_required(VERSION 3.16)

project(SumpleteSolverQt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(WARNING_FLAGS "-Wall -Wextra")
set(OPTIMIZATION_LEVEL -O0)
set(CMAKE_CXX_FLAGS "${WARNING_FLAGS} ${OPTIMIZATION_LEVEL}")

# Define source files with paths relative to the root
qt_add_executable(SumpleteSolverApp

    # Backend files
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version1/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version1/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/Trie/Trie.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/Trie/Trie.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/ValidityChecks/ValidityChecks.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/ValidityChecks/ValidityChecks.hpp

    # Frontend files
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/Grid/Grid.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/Grid/Grid.hpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/GridSizeDropdown/GridSizeDropdown.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/GridSizeDropdown/GridSizeDropdown.hpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/ColsSums/ColsSums.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/ColsSums/ColsSums.hpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/RowsSums/RowsSums.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/RowsSums/RowsSums.hpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/SolveButton/SolveButton.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Components/SolveButton/SolveButton.hpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/Main.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/MainModule/MainModule.cpp
    ${CMAKE_SOURCE_DIR}/Source/Frontend/MainModule/MainModule.hpp
)

qt_add_executable(Test
    # Backend files.
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version1/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version1/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/Trie/Trie.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/Trie/Trie.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/ValidityChecks/ValidityChecks.cpp
    ${CMAKE_SOURCE_DIR}/Source/Backend/ValidityChecks/ValidityChecks.hpp

    # Test files.
    ${CMAKE_SOURCE_DIR}/Tests/Algorithm/Algorithm.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Algorithm/Algorithm.hpp
    ${CMAKE_SOURCE_DIR}/Tests/Algorithm/Version2/Trie/Trie.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Algorithm/Version2/Trie/Trie.hpp
    ${CMAKE_SOURCE_DIR}/Tests/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp
    ${CMAKE_SOURCE_DIR}/Tests/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.hpp
    ${CMAKE_SOURCE_DIR}/Tests/Main.cpp
    ${CMAKE_SOURCE_DIR}/Tests/ValidityChecks/ValidityChecks.cpp
    ${CMAKE_SOURCE_DIR}/Tests/ValidityChecks/ValidityChecks.hpp
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
	Source/Frontend/Components/Grid/Grid.qml
	Source/Frontend/Components/GridSizeDropdown/GridSizeDropdown.qml
	Source/Frontend/Components/ColsSums/ColsSums.qml
	Source/Frontend/Components/RowsSums/RowsSums.qml
	Source/Frontend/Components/SolveButton/SolveButton.qml
	Source/Frontend/Main.qml

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
