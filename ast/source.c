#include "source.h"

#include <malloc.h>


struct ast_source * ast_source_new(void) {
    struct ast_source * result = malloc(sizeof(struct ast_source));

    result->items = ast_source_item_list_init();

    return result;
}

void ast_source_delete(struct ast_source * value) {
    if (!value) {
        return;
    }

    ast_source_item_list_fini(&value->items);

    free(value);
}
