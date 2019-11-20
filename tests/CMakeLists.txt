# Set target name for test source files
set(SOUNDEX_TEST
        soundex_tests)

# Create list of unit tests, new unit test files need to be appended here
set(UNIT_TEST_LIST
        soundex
        charUtil
        stringUtil)

# Loop through UNIT_TEST_LIST and add test source -files to UNIT_TEST_SOURCE_LIST -list
foreach(NAME IN LISTS UNIT_TEST_LIST)
    list(APPEND UNIT_TEST_SOURCE_LIST ${NAME}.test.cpp)
endforeach()

# Inform user about the files included for testing
message(STATUS ":-------------------------------:")
message(STATUS "The test files are as follows:")

foreach(NAME IN LISTS UNIT_TEST_SOURCE_LIST)
    message(STATUS ${NAME})
endforeach()

message(STATUS ":-------------------------------:")

# Create executable by including files from UNIT_TEST_SOURCE_LIST
add_executable(${SOUNDEX_TEST}
        test_main.cpp
        ${UNIT_TEST_SOURCE_LIST})

# Link the library "soundex_targets" to executable
target_link_libraries(${SOUNDEX_TEST}
        PUBLIC soundex_targets)

# Link boost libraries to executable
target_link_libraries(${SOUNDEX_TEST}
        PUBLIC ${Boost_LIBRARIES}
        )

# Add tests, COMMAND can be the target
add_test(
        NAME ${SOUNDEX_TEST}
        COMMAND ${SOUNDEX_TEST} --log_level=all --log_format=XML --log_sink=../log.xml --report_level=no --report_format=XML --report_sink=../report.xml --use_alt_stack=1 --show_progress=1
)