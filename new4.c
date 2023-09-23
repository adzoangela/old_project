#include "main.h"

/**
 * l_length - finds length of linked list
 * @n: pointer
 * Return: size
 */
size_t l_length(const list_t *n)
{
	size_t a = 0;

	while (n)
	{
		n = n->next;
		a++;
	}
	return (a);
}

/**
 * convert_list_to_strings - fetches an array of strings
 * @head: pointer
 * Return: text array
 */
char **convert_list_to_strings(list_t *head)
{
	list_t *nd = head;
	size_t a = l_length(head), b;
	char **strings;
	char *text;

	if (!head || !a)
		return (NULL);
	strings = malloc(sizeof(char *) * (a + 1));
	if (!strings)
		return (NULL);
	for (a = 0; nd; nd = nd->next, a++)
	{
		text = malloc(custom_strlen(nd->text) + 1);
		if (!text)
		{
			for (b = 0; b < a; b++)
				free(strings[b]);
			free(strings);
			return (NULL);
		}

		text = custom_strcpy(text, nd->text);
		strings[a] = text;
	}
	strings[a] = NULL;
	return (strings);
}



/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t _prints_lists(const list_t *n)
{
	size_t a = 0;

	while (n)
	{
		_print(conv_num(n->num, 10, 0));
		_print(':');
		_print(' ');
		_print(n->text? h->text : "(nil)");
		_print("\n");
		n = n->next;
		a++;
	}
	return (a);
}

/**
 * start_node - fetches node with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_with(list_t *nd, char *pf, char c)
{
	char *a = NULL;

	while (nd)
	{
		a = custom_start(nd->text, prefix);
		if (a && ((c == -1) || (*a == c)))
			return (nd);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_with_index(list_t *head, list_t *nd)
{
	size_t a = 0;

	while (head)
	{
		if (head == nd)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}
