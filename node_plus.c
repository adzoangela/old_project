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
	duplicate_str = custom_strdup(str);
	if (duplicate_str == NULL)
		return (NULL);
	new_node = malloc(sizeof(type_env));
	if (new_node == NULL)
		return (NULL);
	new_node->str = duplicate_str;
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

/**
  * node_plus_alias - add linked list for alias
  * @home: head node
  * @key: key in key=value
  * @value: value in key=value pair
  *
  * Return: struct
  */

alias_struct *node_plus_alias(alias_struct **home, char *key, char *value)
{
	alias_struct *new_node = malloc(sizeof(alias_struct));
	alias_struct *last_node;

	if (new_node == NULL)
		return (NULL);

	new_node->next = NULL;
	new_node->name = malloc(sizeof(char) * (custom_strlen(key) + 1));
	if (new_node->name == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	custom_strcpy(new_node->name, key);

	if (*home)
	{
		last_node = *home;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	else
		*home = new_node;

	return (new_node);
}
