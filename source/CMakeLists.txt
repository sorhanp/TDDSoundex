# Set target name for project files to be tested
set(TARGETS
        soundex_targets)

set(TARGET_LIST
        soundex
        charUtil
        stringUtil)

# Loop through TARGET_LIST and add header and source files to TARGET_SOURCE_LIST
foreach(NAME IN LISTS TARGET_LIST)
    list(APPEND TARGET_SOURCE_LIST ${NAME}.cpp)
    list(APPEND TARGET_SOURCE_LIST ${NAME}.h)
endforeach()

# Create library from source files
add_library(${TARGETS}
        ${TARGET_SOURCE_LIST})

# Include library directory as an Interface
target_include_directories(${TARGETS}
        INTERFACE ./)