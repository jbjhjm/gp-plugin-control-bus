cmake_minimum_required(VERSION 3.21)

set (PROJECT_VERSION "0.0.1")
set (PROJECT_NAME "GPCB")
set (PROJECT_TITLE "GP Control Bus")
string(TIMESTAMP TODAY "%d/%m/%Y")
set (PROJECT_BUILD_DATE ${TODAY})

project(${PROJECT_NAME} VERSION 1.0)

# Import the SDK
include(FetchContent)
FetchContent_Declare(
  gp-sdk
  GIT_REPOSITORY https://github.com/gigperformer/gp-sdk.git
  GIT_TAG 756ecd249f1ff00f3d3a5955769408f74c9fa453 # sdk v60
)
FetchContent_MakeAvailable(gp-sdk)

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h @ONLY) 

# Define our library including sources, include directories and dependencies
add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/LibMain.h")
target_link_libraries(${PROJECT_NAME} PRIVATE gigperformer::sdk::cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Language options: this will be a pure C++20 project
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 20
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS NO
)

# Install the extension on the development machine
install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION "${GIG_PERFORMER_EXTENSIONS_DIRECTORY}"
  RUNTIME DESTINATION "${GIG_PERFORMER_EXTENSIONS_DIRECTORY}"
)
