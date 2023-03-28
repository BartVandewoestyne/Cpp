add_executable(example01 example01.cpp)
target_link_libraries(example01
    Catch2::Catch2WithMain
    trompeloeil::trompeloeil)

add_test(NAME example01 COMMAND example01)

add_subdirectory(libwarehouse)
