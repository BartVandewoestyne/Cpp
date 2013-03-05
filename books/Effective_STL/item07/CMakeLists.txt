include_directories(../utils)

add_executable(resource_leak01 resource_leak01.cpp)
target_link_libraries(resource_leak01 estl)

add_executable(resource_leak02 resource_leak02.cpp)
target_link_libraries(resource_leak02 estl)

add_executable(resource_leak03 resource_leak03.cpp)
target_link_libraries(resource_leak03 estl)

add_executable(resource_leak04 resource_leak04.cpp)
target_link_libraries(resource_leak04 estl)

add_executable(resource_leak05 resource_leak05.cpp)
target_link_libraries(resource_leak05 estl)

add_executable(resource_leak06 resource_leak06.cpp)
target_link_libraries(resource_leak06 estl)
