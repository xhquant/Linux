SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(external_libs)

ADD_SUBDIRECTORY(src)

ADD_EXECUTABLE(dynamic_loading
        main.cpp external_libs/tinyxml2.cpp)
TARGET_LINK_LIBRARIES(dynamic_loading dl rt)