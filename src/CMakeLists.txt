option(FORT_HAVE_WCHAR "Enable wchar support" ON)
option(FORT_HAVE_UTF8 "Enable UTF8 support" ON)
option(FORT_TEST_BUILD "Export some internal symbols for tests" ON)

add_library(fort
    fort_impl.c
    vector.c
    string_buffer.c
    properties.c
    cell.c
    row.c
    table.c
    fort_utils.c
    wcwidth.c)

target_include_directories(fort
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(NOT FORT_HAVE_WCHAR)
    target_compile_definitions(fort
        PRIVATE
            -DFT_CONGIG_DISABLE_WCHAR
    )
endif()

if(NOT FORT_HAVE_UTF8)
    target_compile_definitions(fort
        PRIVATE
            -DFT_CONGIG_DISABLE_UTF8
    )
endif()

if(FORT_TEST_BUILD)
    target_compile_definitions(fort
        PRIVATE
            -DFT_TEST_BUILD=1
    )
endif()
