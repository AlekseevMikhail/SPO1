#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "ast.h"


void ast_display_source(struct ast_source * source, const char * label, size_t indent, FILE * output);
void ast_display_source_item(struct ast_source_item * source_item, const char * label, size_t indent, FILE * output);
void ast_display_function_signature(
        struct ast_function_signature * function_signature,
        const char * label,
        size_t indent,
        FILE * output
);
void ast_display_type_reference(
        struct ast_type_reference * type_reference,
        const char * label,
        size_t indent,
        FILE * output
);
void ast_display_stmt(struct ast_stmt * stmt, const char * label, size_t indent, FILE * output);
void ast_display_expr(struct ast_expr * expr, const char * label, size_t indent, FILE * output);
void ast_display_literal(struct ast_literal * literal, const char * label, size_t indent, FILE * output);
