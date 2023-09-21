#include "main.h"

/**
  * node_plus - add new node to end(linklist)
  * @home: head of the linked list
  * @str: string
  * @length: length of the string
  *
  * Return: ptr to the current_position in the linklist
  **/

type_env *node_plus(type_env **home, char *str, unsigned int length)
{
	type_env *current_node, *new_node;
	char *duplicate_str;

	if (str == NULL)
		return (NULL);
	duplicate_str = _strdup(str);
	if (dupstr == NULL)
		return (NULL);
	new_node = malloc(sizeof(type_env));
	if (new_node == NULL)
		return (NULL);
	new_node->str = dupstr;
	new_node->len = length;
	new_node->next = NULL;

	if (*home == NULL)
	{
		*home = new_node;
		return (*home);
	}
	current_node = *home;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_node;
	return (*home);
}
