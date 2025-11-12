cmake_minimum_required(VERSION 4.0)
project(qfin_option_pricer LANGUAGES CXX)

# --- Compiler settings ---

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Debug warnings ---

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- Library target ---

add_library(qfin_option_pricer
    src/black_scholes.cpp
)

target_include_directories(qfin_option_pricer
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# --- CLI executable ---

add_executable(qfin_option_pricer_cli
    src/main.cpp
)

target_link_libraries(qfin_option_pricer_cli
    PRIVATE
        qfin_option_pricer
)

# --- Tests ---

enable_testing()

add_executable(qfin_option_pricer_tests
    tests/test_black_scholes.cpp
)

target_link_libraries(qfin_option_pricer_tests
    PRIVATE
        qfin_option_pricer
)

add_test(
    NAME qfin_option_pricer_tests
    COMMAND qfin_option_pricer_tests
)
