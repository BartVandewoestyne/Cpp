add_definitions(-DTIXML_USE_STL)

add_executable(xmltest xmltest.cpp)
target_link_libraries(xmltest tinyxml)
