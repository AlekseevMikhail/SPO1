#pragma once

#include <stdlib.h>


enum ast_type_reference_type {

    AST_TYPE_REFERENCE_TYPE_BUILTIN = 0,
    AST_TYPE_REFERENCE_TYPE_CUSTOM,
    AST_TYPE_REFERENCE_TYPE_ARRAY,
};

enum ast_type_reference_builtin_type {

    AST_TYPE_REFERENCE_BUILTIN_TYPE_BOOL = 0,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_BYTE,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_INT,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_UINT,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_LONG,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_ULONG,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_CHAR,
    AST_TYPE_REFERENCE_BUILTIN_TYPE_STRING,
};

struct ast_type_reference;

struct ast_type_reference_builtin {

    enum ast_type_reference_builtin_type type;
};

struct ast_type_reference_custom {

    char * id;
};

struct ast_type_reference_array {

    struct ast_type_reference * type;
    size_t axes;
};

struct ast_type_reference {

    enum ast_type_reference_type _type;

    union {
        struct ast_type_reference_builtin builtin;
        struct ast_type_reference_custom custom;
        struct ast_type_reference_array array;
    };
};

struct ast_type_reference * ast_type_reference_new_builtin(enum ast_type_reference_builtin_type type);
struct ast_type_reference * ast_type_reference_new_custom(char * id);
struct ast_type_reference * ast_type_reference_new_array(struct ast_type_reference * type, size_t axes);
void ast_type_reference_delete(struct ast_type_reference * value);
