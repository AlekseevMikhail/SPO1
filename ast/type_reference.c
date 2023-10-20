#include "type_reference.h"


struct ast_type_reference * ast_type_reference_new_builtin(enum ast_type_reference_builtin_type type) {
    struct ast_type_reference * result = malloc(sizeof(struct ast_type_reference));

    result->_type = AST_TYPE_REFERENCE_TYPE_BUILTIN;
    result->builtin = (struct ast_type_reference_builtin) {
        .type = type,
    };

    return result;
}

struct ast_type_reference * ast_type_reference_new_custom(char * id) {
    struct ast_type_reference * result = malloc(sizeof(struct ast_type_reference));

    result->_type = AST_TYPE_REFERENCE_TYPE_CUSTOM;
    result->custom = (struct ast_type_reference_custom) {
        .id = id,
    };

    return result;
}

struct ast_type_reference * ast_type_reference_new_array(struct ast_type_reference * type, size_t axes) {
    struct ast_type_reference * result = malloc(sizeof(struct ast_type_reference));

    result->_type = AST_TYPE_REFERENCE_TYPE_ARRAY;
    result->array = (struct ast_type_reference_array) {
        .type = type,
        .axes = axes,
    };

    return result;
}

void ast_type_reference_delete(struct ast_type_reference * value) {
    if (!value) {
        return;
    }

    switch (value->_type) {
        case AST_TYPE_REFERENCE_TYPE_BUILTIN:
            break;

        case AST_TYPE_REFERENCE_TYPE_CUSTOM:
            free(value->custom.id);
            break;

        case AST_TYPE_REFERENCE_TYPE_ARRAY:
            ast_type_reference_delete(value->array.type);
            break;
    }

    free(value);
}
