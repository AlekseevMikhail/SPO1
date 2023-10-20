#pragma once

#include "source_item.h"


struct ast_source {

    struct ast_source_item_list items;
};

struct ast_source * ast_source_new(void);
void ast_source_delete(struct ast_source * value);
