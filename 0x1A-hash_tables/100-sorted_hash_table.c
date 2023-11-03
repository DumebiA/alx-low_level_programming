#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *new_table = NULL;
    unsigned long int i;

    new_table = malloc(sizeof(shash_table_t));
    if (new_table == NULL)
        return (NULL);

    new_table->size = size;
    new_table->array = malloc(sizeof(shash_node_t *) * size);
    if (new_table->array == NULL)
    {
        free(new_table);
        return (NULL);
    }

    for (i = 0; i < size; i++)
    {
        new_table->array[i] = NULL;
    }

    new_table->shead = NULL;
    new_table->stail = NULL;

    return (new_table);
}

/**
 * shash_table_set - Inserts an element into the sorted hash table.
 * @ht: The sorted hash table to insert into.
 * @key: The key (must not be an empty string).
 * @value: The value associated with the key (can be an empty string).
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node, *current, *prev = NULL;

    if (ht == NULL || key == NULL || *key == '\0')
        return (0);

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);

    if (new_node->key == NULL || new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    new_node->next = NULL;
    current = ht->shead;

    while (current != NULL && strcmp(key, current->key) > 0)
    {
        prev = current;
        current = current->snext;
    }

    if (current != NULL && strcmp(key, current->key) == 0)
    {
        free(current->value);
        current->value = new_node->value;
        free(new_node->key);
        free(new_node);
        return (1);
    }

    if (prev == NULL)
    {
        new_node->snext = ht->shead;
        ht->shead = new_node;
    }
    else
    {
        prev->snext = new_node;
        new_node->snext = current;
    }

    if (current == NULL)
        ht->stail = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key from the sorted hash table.
 * @ht: The sorted hash table to look into.
 * @key: The key you are looking for.
 * Return: The value associated with the element, or NULL if the key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *node;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];

    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table using the sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    node = ht->shead;
    printf("{");
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->snext;
        if (node != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order using the sorted linked list.
 * @ht: The sorted hash table to print in reverse.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (ht == NULL)
        return;

    node = ht->stail;
    printf("{");
    while (node != NULL)
    {
        printf("'%s': '%s'", node->key, node->value);
        node = node->sprev;
        if (node != NULL)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes the sorted hash table and its elements.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;

    if (ht == NULL)
        return;

    for (node = ht->shead; node != NULL;)
    {
        temp = node;
        node = node->snext;
        free(temp->key);
        free(temp->value);
        free(temp);
    }

    free(ht->array);
    free(ht);
}

