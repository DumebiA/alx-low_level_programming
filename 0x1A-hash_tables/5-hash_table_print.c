#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int index;
    hash_node_t *node;
    int printed = 0;

    if (ht == NULL)
        return;

    printf("{");
    for (index = 0; index < ht->size; index++)
    {
        node = ht->array[index];
        while (node)
        {
            if (printed)
                printf(", ");
            printf("'%s': '%s'", node->key, node->value);
            printed = 1;
            node = node->next;
        }
    }
    printf("}\n");
}

