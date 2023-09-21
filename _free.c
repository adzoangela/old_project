#include "main.h"

/**
  * _free - frees a list
  * @home: head node
  *
  * Return: Nothing
  */
void _free(type_env *home)
{
	if (home == NULL)
		return;
	_free(home->next);
	free(home->str);
	free(home);
}
