#include "literal.h"

#include <malloc.h>


struct ast_literal * ast_literal_new_bool(bool value) {
    struct ast_literal * result = malloc(sizeof(struct ast_literal));

    result->_type = AST_LITERAL_TYPE_BOOL;
    result->_bool.value = value;

    return result;
}

struct ast_literal * ast_literal_new_str(char * value) {
    struct ast_literal * result = malloc(sizeof(struct ast_literal));

    result->_type = AST_LITERAL_TYPE_STR;
    result->str.value = value;

    return result;
}

struct ast_literal * ast_literal_new_char(char value) {
    struct ast_literal * result = malloc(sizeof(struct ast_literal));

    result->_type = AST_LITERAL_TYPE_CHAR;
    result->_char.value = value;

    return result;
}

struct ast_literal * ast_literal_new_hex(char * value) {
    struct ast_literal * result = malloc(sizeof(struct ast_literal));

    result->_type = AST_LITERAL_TYPE_HEX;
    result->hex.value = value;

    return result;
}

struct ast_literal * ast_literal_new_bits(char * value) {
    struct ast_literal * result = malloc(sizeof(struct ast_literal));

    result->_type = AST_LITERAL_TYPE_BITS;
    result->bits.value = value;

    return result;
}

struct ast_literal * ast_literal_new_dec(char * value) {
    struct ast_literal * result = malloc(sizeof(struct ast_literal));

    result->_type = AST_LITERAL_TYPE_DEC;
    result->dec.value = value;

    return result;
}

void ast_literal_delete(struct ast_literal * value) {
    if (!value) {
        return;
    }

    switch (value->_type) {
        case AST_LITERAL_TYPE_STR:
            free(value->str.value);
            break;

        case AST_LITERAL_TYPE_HEX:
            free(value->hex.value);
            break;

        case AST_LITERAL_TYPE_BITS:
            free(value->bits.value);
            break;

        case AST_LITERAL_TYPE_DEC:
            free(value->dec.value);
            break;

        case AST_LITERAL_TYPE_BOOL:
        case AST_LITERAL_TYPE_CHAR:
            break;
    }

    free(value);
}
