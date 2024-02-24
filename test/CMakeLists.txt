include(CTest)

enable_testing()

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -j4 -C $<CONFIG>)

##################################################
# Parser tests
##################################################
add_executable(
    compile_tests
    compile_tests_main.cpp
    compile_attribute.cpp
    compile_seq_attribute.cpp
    compile_or_attribute.cpp
    compile_combining_groups.cpp
)
target_link_libraries(compile_tests parser)

function(add_test_executable name)
    if(ARGC EQUAL 1)
        set(src "${name}.cpp")
    else()
        set(src "${ARGV1}")
    endif()
    add_executable(${name} ${src})
    target_link_libraries(${name} parser gtest gtest_main ${link_flags})
    if (MSVC)
        target_compile_options(${name} PRIVATE /source-charset:utf-8 /bigobj)
    endif ()
    add_test(NAME ${name} COMMAND ${name} --gtest_catch_exceptions=1)
endfunction()

add_test_executable(all_t)
add_test_executable(search)
add_test_executable(split)
add_test_executable(replace)
add_test_executable(transform_replace)
add_test_executable(hl)
add_test_executable(aggr_tuple_assignment)
add_test_executable(parser_ parser.cpp)
add_test_executable(parser_api)
add_test_executable(parser_lazy_params)
add_test_executable(parser_if_switch)
add_test_executable(parser_rule)
add_test_executable(parser_rule_with_params)
add_test_executable(parser_action)
add_test_executable(parser_action_with_params)
add_test_executable(parser_symbol_table)
add_test_executable(tracing)
add_test_executable(parse_empty)
add_test_executable(tuple_aggregate)
add_test_executable(class_type)
add_test_executable(case_fold_generated)
add_test_executable(no_case)
add_test_executable(merge_separate)
