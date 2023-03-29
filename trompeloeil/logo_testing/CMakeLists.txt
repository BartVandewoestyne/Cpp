add_executable(PainterTest2 PainterTest2.cpp)
target_link_libraries(PainterTest2
    PRIVATE
        logo
        Catch2::Catch2WithMain
        trompeloeil::trompeloeil)

add_test(NAME PainterTest2 COMMAND PainterTest2)
