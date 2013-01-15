add_executable(basic_app_settings     basic_app_settings.cpp)
target_link_libraries(basic_app_settings tinyxml)

add_executable(build_simple_doc       build_simple_doc.cpp)
target_link_libraries(build_simple_doc tinyxml)

add_executable(get_all_attributes     get_all_attributes.cpp)
target_link_libraries(get_all_attributes tinyxml)

add_executable(load_xml_from_file1    load_xml_from_file1.cpp)
target_link_libraries(load_xml_from_file1 tinyxml)

add_executable(load_xml_from_file2    load_xml_from_file2.cpp)
target_link_libraries(load_xml_from_file2 tinyxml)

add_executable(setting_attributes     setting_attributes.cpp)
target_link_libraries(setting_attributes tinyxml)

add_executable(write_document_to_file write_document_to_file.cpp)
target_link_libraries(write_document_to_file tinyxml)

add_executable(write_simple_doc2      write_simple_doc2.cpp)
target_link_libraries(write_simple_doc2 tinyxml)
