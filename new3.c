#include "main.h"

/**
 * add_list_node - Adds a node.
 * @head: Address of the pointer.
 * @text: Text field of the node.
 * @number: Node index.
 * Return: Size of the list.
 */
list_t *add_list_node(list_t **head, const char *text, int number)
{
    list_t *nh;

    if (!head)
        return (NULL);
    nh = malloc(sizeof(list_t));
    if (!nh)
        return (NULL);
    mem_init((void *)nh, 0, sizeof(list_t));
    nh->number = number;
    if (text)
    {
        nh->text = custom_strdup(text);
        if (!nh->text)
        {
            free(nh);
            return (NULL);
        }
    }
    nh->next = *head;
    *head = nh;
    return (nh);
}

/**
 * append_list_node - Adds a node.
 * @head: Address of the pointer.
 * @text: Text field.
 * @number: Node index.
 * Return: Size of the list.
 */
list_t *append_list_node(list_t **head, const char *text, int number)
{
    list_t *nn, *node;

    if (!head)
        return (NULL);

    node = *head;
    nn = malloc(sizeof(list_t));
    if (!nn)
        return (NULL);
    mem_init((void *)nn, 0, sizeof(list_t));
    nn->number = number;
    if (text)
    {
        nn->text = custom_strdup(text);
        if (!nn->text)
        {
            free(nn);
            return (NULL);
        }
    }
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = nn;
    }
    else
        *head = nn;
    return (nn);
}

/**
 * print_text_list - Prints string  element of list_t
 * @node: Pointer
 * Return: Size
 */
size_t print_text_list(const list_t *n)
{
    size_t count = 0;

    while (n)
    {
        _print(n->text ? n->text : "(nil)");
        _print("\n");
        n = n->next;
        count++;
    }
    return (count);
}

/**
 * delete_n_by_index - Deletes node.
 * @head: Address of the pointer.
 * @index: Index of the node.
 * Return: 1 or 0
 */
int delete_n_by_index(list_t **head, unsigned int index)
{
    list_t *node, *pn;
    unsigned int a = 0;

    if (!head || !*head)
        return (0);

    if (!index)
    {
        node = *head;
        *head = (*head)->next;
        free(node->text);
        free(node);
        return (1);
    }
    node = *head;
    while (node)
    {
        if (a == index)
        {
            pn->next = node->next;
            free(node->text);
            free(node);
            return (1);
        }
        a++;
        pn = node;
        node = node->next;
    }
    return (0);
}

/**
 * free_text_list - Frees nodes.
 * @head_pointer: Address of the pointer.
 * Return: Void.
 */
void free_text_list(list_t **head_pointer)
{
    list_t *node, *nn, *head;

    if (!head_pointer || !*head_pointer)
        return;
    head = *head_pointer;
    node = head;
    while (node)
    {
        nn = node->next;
        free(node->text);
        free(node);
        node = nn;
    }
    *head_ptr = NULL;
}
