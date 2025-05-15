# CMakeLists.txt

# Always set the cmake min version.
cmake_minimum_required(VERSION 3.18)

cmake_policy(SET CMP0076 NEW) # auto-converts relative paths passed to target_sources
cmake_policy(SET CMP0054 NEW) # no magic evaluation of string-args in if()

# Set the GP_SDK_ROOT variable to the GP_SDK folder
set (GP_SDK_ROOT "gpsdk")
set (PROJECT_VERSION "0.0.1")
set (PROJECT_NAME "GPCB")
set (PROJECT_TITLE "GP Control Bus")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

include("${CMAKE_CURRENT_LIST_DIR}/cmake/dependencies.cmake")
# include("${CMAKE_CURRENT_LIST_DIR}/cmake/juce-shared-library.cmake")

# To build shared libraries in Windows, we set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to TRUE.
# See https://cmake.org/cmake/help/v3.4/variable/CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS.html
# See https://blog.kitware.com/create-dlls-on-windows-without-declspec-using-new-cmake-export-all-feature/
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h @ONLY) 

# Create our library target
# add_library is handled in juce-shared-library!
add_library(${PROJECT_NAME} SHARED)
_juce_initialise_target(${PROJECT_NAME} ${ARGN})

target_sources(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/LibMain.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/LibMain.h
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/GPScriptFunctions.h
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Logwindow.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Logwindow.h
  
   PUBLIC ${GP_SDK_ROOT}/interfaces/CPP/GPUtils.cpp
   PUBLIC ${GP_SDK_ROOT}/interfaces/CPP/GigPerformerFunctions.cpp
   PUBLIC ${GP_SDK_ROOT}/interfaces/C/imports.c
   PUBLIC ${GP_SDK_ROOT}/interfaces/C/utils.c
   PUBLIC ${GP_SDK_ROOT}/interfaces/CPP/entry.cpp
   PUBLIC ${GP_SDK_ROOT}/interfaces/CPP/GPMidiMessages.cpp
)

target_link_libraries( ${PROJECT_NAME} 
	PRIVATE juce::juce_gui_basics
            juce::juce_core 
			juce::juce_events 
			juce::juce_graphics
)
include_directories( INTERFACE ${GP_SDK_ROOT})                 # So that the interface files can be found
include_directories( PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)    # So that the LibMain.h can be found
# target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# debug directories
get_directory_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
MESSAGE(WARNING ${dirs})

set_target_properties(${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS NO
)

target_compile_definitions(${PROJECT_NAME} 
	PRIVATE "JUCER_ENABLE_GPL_MODE=1"
            "JUCE_DISPLAY_SPLASH_SCREEN=0"
	PRIVATE JUCE_STANDALONE_APPLICATION=1 
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release)

# Let's set compiler-specific flags
MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}" )
# CMAKE_CXX_COMPILER_ID must not be wrapped in $ {..} anymore!
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # G++
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
    # WIN_EXPORT definition controls macros.h which sets SDK API to be set to dllexport
	# if error "a function declared 'dllimport' may not be defined" arises,
	# this is likely due to macro misconfiguration.
	MESSAGE(STATUS "Define WIN_EXPORT")
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT=1)
	
	MESSAGE(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
	set_target_properties(${TARGET_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release
	)
endif()