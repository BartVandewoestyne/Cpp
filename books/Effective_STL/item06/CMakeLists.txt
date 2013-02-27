include_directories(../utils)

add_executable(function_declarations function_declarations.cpp)

add_executable(load_ints_in_list load_ints_in_list.cpp)

add_executable(typical_mistake typical_mistake.cpp)
target_link_libraries(typical_mistake estl)
