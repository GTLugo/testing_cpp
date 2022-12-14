cmake_minimum_required(VERSION 3.24)
set(TARGET_NAME "library")

# ===================================================
# LIBRARY
# ===================================================
set(SOURCES
    "library/lib.cpp"
    )
add_library(${TARGET_NAME} STATIC ${SOURCES})
target_compile_features(${TARGET_NAME} PRIVATE cxx_std_23)
target_compile_options(${TARGET_NAME} PRIVATE "/bigobj" "/std:c++latest" "/experimental:module")
target_compile_definitions(${TARGET_NAME}
                           PRIVATE _CRT_SECURE_NO_WARNINGS=1
                                   WIN32_LEAN_AND_MEAN=1
                           PRIVATE NOMINMAX=1
                                  $<$<CONFIG:debug>:LIB_DEBUG_MODE=1>
                                  $<$<CONFIG:relwithdebinfo>:LIB_DEBUG_MODE=1;LIB_RELDEB_MODE=1>
                           )
target_precompile_headers(${TARGET_NAME} PUBLIC "internal/pch.hpp")
target_include_directories(${TARGET_NAME} PUBLIC "../include" ".")

# ===================================================
# DEPENDENCIES
# ===================================================
target_include_directories(${TARGET_NAME} PUBLIC "../extern/koyote_utils/include")
target_link_libraries(${TARGET_NAME} PUBLIC koyote)