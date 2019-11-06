# Set target name for project files to be tested
set(TEST_TARGETS
        soundex_targets)

# Create library from source files
add_library(${TEST_TARGETS}
        soundex.h
        soundex.cpp
        charUtil.h
        charUtil.cpp
        stringUtil.h
        stringUtil.cpp)

# Include library directory as an Interface
target_include_directories(${TEST_TARGETS}
        INTERFACE ./)