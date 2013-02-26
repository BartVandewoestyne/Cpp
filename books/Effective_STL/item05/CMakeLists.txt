include_directories(../utils)

add_executable(opening_problem opening_problem.cpp)
target_link_libraries(opening_problem estl)

add_executable(fill_vector_from_array fill_vector_from_array.cpp)
