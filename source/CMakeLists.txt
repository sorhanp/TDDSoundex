# Set target name for project files to be tested
set(TEST_TARGETS
        soundex_targets)

# Create library from test files
add_library(${TEST_TARGETS}
        soundex.h
        soundex.cpp)

# Include library directory as an Interface
target_include_directories(${TEST_TARGETS}
        INTERFACE ./)