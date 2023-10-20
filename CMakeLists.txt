cmake_minimum_required(VERSION 3.16)
project(spo C)

set(CMAKE_C_STANDARD 11)

find_package(BISON)
find_package(FLEX)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_compile_options(-Wall -Werror -pedantic-errors)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

FLEX_TARGET(Lexer parser/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/parser/lexer.c
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser/lexer.h)

BISON_TARGET(Parser parser/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser/parser.c
        COMPILE_FLAGS -Wcounterexamples
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser/parser.h
        VERBOSE REPORT_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser/parser.txt)

ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

add_executable(spo
        ast/expr.c
        ast/expr.h
        ast/function_signature.c
        ast/function_signature.h
        ast/literal.h
        ast/source.h
        ast/source_item.h
        ast/stmt.h
        ast/type_reference.h
        ast.h
        main.c
        ${BISON_Parser_OUTPUTS}
        ${FLEX_Lexer_OUTPUTS}
        ast/literal.c
        ast/source.c
        ast/source_item.c
        ast/stmt.c
        ast/type_reference.c
        ast_display.h
        ast_display.c)
